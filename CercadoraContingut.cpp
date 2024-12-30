#include "CercadoraContingut.h"
#include <iostream>
#include <memory>
#include <stdexcept>

vector<DTOPelicula> CercadoraContingut::cercaProperesPelicules(const string& modalitat) {
    vector<DTOPelicula> resultats;
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    string query = R"(
        SELECT c.titol, c.descripcio, c.qualificacio, p.data_estrena, p.duracio
        FROM contingut c
        JOIN pelicula p ON c.titol = p.titol
        WHERE p.data_estrena > NOW()
    )";

    if (!modalitat.empty()) {
        query += " AND EXISTS (SELECT 1 FROM usuari u WHERE u.subscripcio = '" + modalitat + "')";
    }

    unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));
    while (res->next()) {
        resultats.emplace_back(
            res->getString("titol"),
            res->getString("descripcio"),
            res->getString("qualificacio"),
            res->getString("data_estrena"),
            res->getInt("duracio")
        );
    }

    return resultats;
}

vector<DTOSerie> CercadoraContingut::cercaProperesSeries(const string& modalitat) {
    vector<DTOSerie> resultats;
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    string query = R"(
        SELECT c.titol, c.descripcio, c.qualificacio, MIN(cap.data_estrena) AS data_estrena, COUNT(cap.numero) AS total_capitols
        FROM contingut c
        JOIN serie s ON c.titol = s.titol
        JOIN capitol cap ON s.titol = cap.titol_serie
        WHERE cap.data_estrena > NOW()
        GROUP BY c.titol, c.descripcio, c.qualificacio
    )";

    if (!modalitat.empty()) {
        query += " AND EXISTS (SELECT 1 FROM usuari u WHERE u.subscripcio = '" + modalitat + "')";
    }

    unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));
    while (res->next()) {
        resultats.emplace_back(
            res->getString("titol"),
            res->getString("descripcio"),
            res->getString("qualificacio"),
            res->getString("data_estrena"),
            res->getInt("total_capitols")
        );
    }

    return resultats;
}

vector<DTOPelicula> CercadoraContingut::cercaUltimesPelicules(const string& modalitat) {
    vector<DTOPelicula> resultats;
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    // Consulta base
    string query = R"(
        SELECT c.titol, c.descripcio, c.qualificacio, p.data_estrena, p.duracio
        FROM contingut c
        JOIN pelicula p ON c.titol = p.titol
        WHERE p.data_estrena <= NOW()
    )";

    // Si modalitat no esta vacio, añadimos el filtro de subscripcion
    if (!modalitat.empty()) {
        query += " AND EXISTS (SELECT 1 FROM usuari u WHERE u.subscripcio = '" + modalitat + "')";
    }

    // Añadir el ORDER BY y el LIMIT al final
    query += " ORDER BY p.data_estrena DESC LIMIT 5";

    // Depuracion: Verificar la consulta generada

    // Ejecutar la consulta
    unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));
    while (res->next()) {
        resultats.emplace_back(
            res->getString("titol"),
            res->getString("descripcio"),
            res->getString("qualificacio"),
            res->getString("data_estrena"),
            res->getInt("duracio")
        );
    }
    return resultats;
}


vector<DTOSerie> CercadoraContingut::cercaUltimesSeries(const string& modalitat) {
    vector<DTOSerie> resultats;
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    string query = R"(
        SELECT c.titol, c.descripcio, c.qualificacio, MAX(cap.data_estrena) AS data_estrena, COUNT(cap.numero) AS total_capitols
        FROM contingut c
        JOIN serie s ON c.titol = s.titol
        JOIN capitol cap ON s.titol = cap.titol_serie
        WHERE cap.data_estrena <= NOW()
    )";

    // Si modalitat no esta vacio, agregar la condicion de subscripcion
    if (!modalitat.empty()) {
        query += " AND EXISTS (SELECT 1 FROM usuari u WHERE u.subscripcio = '" + modalitat + "')";
    }

    // Asegurate de que la consulta este ordenada por la fecha de estreno (descendente) y limitada a 5
    query += " GROUP BY c.titol, c.descripcio, c.qualificacio ORDER BY data_estrena DESC LIMIT 5";

    try {
        unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));

        if (!res) {
            cout << "Error: No se pudo ejecutar la consulta o no se obtuvieron resultados." << endl;
            return resultats;
        }


        while (res->next()) {
            string titol = res->getString("titol");
            string descripcio = res->getString("descripcio");
            string qualificacio = res->getString("qualificacio");
            string dataEstrena = res->getString("data_estrena");
            int totalCapitols = res->getInt("total_capitols");
            resultats.emplace_back(titol, descripcio, qualificacio, dataEstrena, totalCapitols);
        }

    }
    catch (const sql::SQLException& e) {
        cout << "Error al ejecutar la consulta SQL: " << e.what() << endl;
    }
    catch (const std::exception& e) {
        cout << "Error inesperado: " << e.what() << endl;
    }

    return resultats;
}

int CercadoraContingut::obteUltimaTemporadaEstrena(const std::string& titolSerie) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    // Consulta para obtener la ultima temporada con capitulos estrenados
    std::string consulta =
        "SELECT MAX(temporada.numero) AS ultima_temporada "
        "FROM temporada "
        "JOIN capitol ON temporada.titol_serie = capitol.titol_serie "
        "AND temporada.numero = capitol.numero_temporada "
        "WHERE temporada.titol_serie = '" + titolSerie + "'";

    sql::ResultSet* resultado = connexio.consultaSQL(consulta);  // Ejecutar la consulta

    int ultimaTemporada = 0;
    if (resultado->next()) {
        ultimaTemporada = resultado->getInt("ultima_temporada");
    }

    delete resultado;

    return ultimaTemporada;
}


DTOCapitol CercadoraContingut::obteUltimCapitolDeTemporada(const std::string& titolSerie, int ultimaTemporada) {
    if (ultimaTemporada == 0) {
        throw std::runtime_error("No hi ha capitols disponibles.");
    }

    ConnexioBD& connexio = *ConnexioBD::getInstance();

    // Consulta para obtener el ultimo capitulo de la ultima temporada
    std::string consulta =
        "SELECT MAX(numero) AS ultim_capitol, titol, data_estrena, qualificacio "
        "FROM capitol "
        "WHERE titol_serie = '" + titolSerie + "' AND numero_temporada = " + std::to_string(ultimaTemporada);

    sql::ResultSet* resultado = connexio.consultaSQL(consulta);  // Ejecutar la consulta

    DTOCapitol ultimCapitol;
    if (resultado->next()) {
        ultimCapitol = DTOCapitol(
            titolSerie,
            ultimaTemporada,
            resultado->getInt("ultim_capitol"),
            resultado->getString("titol"),
            resultado->getString("data_estrena"),
            resultado->getString("qualificacio"));
    }
    else {
        throw std::runtime_error("No hi ha capitols disponibles.");
    }

    delete resultado;

    return ultimCapitol;
}


DTOPelicula CercadoraContingut::cercaPelicula(const std::string& titol) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    std::string query =
        "SELECT c.titol, c.descripcio, c.qualificacio, p.data_estrena, p.duracio "
        "FROM contingut c "
        "JOIN pelicula p ON c.titol = p.titol "
        "WHERE c.titol = '" + titol + "' AND c.tipus = 'pelicula'";
    unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));

    if (res->next()) {
        return DTOPelicula(
            res->getString("titol"),
            res->getString("descripcio"),
            res->getString("qualificacio"),
            res->getString("data_estrena"),
            res->getInt("duracio")
        );
    }
    throw std::runtime_error("Pelicula no trobada: " + titol);
}

std::vector<DTOPelicula> CercadoraContingut::cercaRelacionades(const std::string& titol) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    std::string query =
        "SELECT c.titol, c.descripcio, c.qualificacio, p.data_estrena, p.duracio "
        "FROM contingut c NATURAL JOIN pelicula p "
        "WHERE c.titol IN ("
        "    SELECT titol_y FROM relacionat WHERE titol_x = '" + titol + "' "
        "    UNION "
        "    SELECT titol_x FROM relacionat WHERE titol_y = '" + titol + "'"
        ")";
    unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));

    std::vector<DTOPelicula> relacionades;
    while (res->next()) {
        relacionades.emplace_back(
            res->getString("titol"),
            res->getString("descripcio"),
            res->getString("qualificacio"),
            res->getString("data_estrena"),
            res->getInt("duracio")
        );
    }
    return relacionades;
}

DTOSerie CercadoraContingut::cercaSerie(const std::string& titol) {
    ConnexioBD& con = *ConnexioBD::getInstance();

    string query =
        "SELECT c.titol, c.descripcio, c.qualificacio, s.data_estrena "
        "FROM contingut c "
        "JOIN serie s ON c.titol = s.titol "
        "WHERE c.titol = '" + titol + "' AND c.tipus = 'serie'";

    sql::ResultSet* resultat = nullptr;

    try {
        resultat = con.consultaSQL(query);

        if (!resultat->next()) {
            throw std::runtime_error("Serie no trobada.");
        }

        DTOSerie serie(
            resultat->getString("titol"),
            resultat->getString("descripcio"),
            resultat->getString("qualificacio"),
            resultat->getString("data_estrena"),
            0
        );

        delete resultat;

        return serie;
    }
    catch (const sql::SQLException& e) {
        if (resultat) delete resultat;
        throw std::runtime_error("Error en la consulta SQL: " + std::string(e.what()));
    }
}


int CercadoraContingut::obtenirNumeroTemporades(const string& titol) {
    ConnexioBD& con = *ConnexioBD::getInstance();

    string query =
        "SELECT COUNT(DISTINCT numero) AS total_temporades "
        "FROM temporada "
        "WHERE titol_serie = '" + titol + "'";

    sql::ResultSet* resultat = nullptr;

    try {
        resultat = con.consultaSQL(query);

        if (!resultat->next()) {
            throw runtime_error("No s'ha pogut obtenir el numero de temporades.");
        }

        int totalTemporades = resultat->getInt("total_temporades");

        delete resultat;

        return totalTemporades;
    }
    catch (const sql::SQLException& e) {
        if (resultat) delete resultat;
        throw runtime_error("Error en la consulta SQL: " + string(e.what()));
    }
}

vector<DTOCapitol> CercadoraContingut::obtenirCapitolsPerTemporada(const string& titol_serie, int numero_temporada) {
    ConnexioBD& con = *ConnexioBD::getInstance();

    string query =
        "SELECT c.titol_serie, c.numero_temporada, c.numero, c.titol, c.data_estrena, c.qualificacio "
        "FROM capitol c "
        "WHERE c.titol_serie = '" + titol_serie + "' AND c.numero_temporada = " + to_string(numero_temporada);

    sql::ResultSet* resultat = nullptr;
    vector<DTOCapitol> capitols;

    try {
        resultat = con.consultaSQL(query);

        if (!resultat->next()) {
            throw runtime_error("No s'han trobat capitols per a la temporada indicada.");
        }

        do {
            DTOCapitol capitol(
                resultat->getString("titol_serie"),
                resultat->getInt("numero_temporada"),
                resultat->getInt("numero"),
                resultat->getString("titol"),
                resultat->getString("data_estrena"),
                resultat->getString("qualificacio")
            );

            capitols.push_back(capitol);

        } while (resultat->next());

        delete resultat;

        return capitols;

    }
    catch (const sql::SQLException& e) {
        if (resultat) delete resultat;
        throw runtime_error("Error en la consulta SQL: " + string(e.what()));
    }
}

vector<DTOVisualitzacioCapitol> CercadoraContingut::cercaVisualitzacionsCapitol(const std::string& sobrenomUsuari) {
    ConnexioBD& con = *ConnexioBD::getInstance();
    vector<DTOVisualitzacioCapitol> resultats;

    string query =
        "SELECT vc.titol_serie, vc.num_capitol, vc.num_temporada, vc.data, vc.num_visualitzacions, "
        "c.qualificacio "
        "FROM visualitzacio_capitol vc "
        "JOIN contingut c ON vc.titol_serie = c.titol "
        "WHERE vc.sobrenom_usuari = '" + sobrenomUsuari + "'";

    sql::ResultSet* res = con.consultaSQL(query);
    while (res->next()) {
        DTOVisualitzacioCapitol dto(
            res->getString("titol_serie"),
            res->getInt("num_capitol"),
            res->getInt("num_temporada"),
            res->getString("data"),
            res->getInt("num_visualitzacions"),
            res->getString("qualificacio")
        );
        resultats.push_back(dto);
    }
    delete res;
    return resultats;
}

std::vector<DTOVisualitzacioPelicula> CercadoraContingut::cercaPelMesVistes() {
    ConnexioBD& con = *ConnexioBD::getInstance();
    std::vector<DTOVisualitzacioPelicula> resultats;

    std::string query =
        "SELECT vp.titol_pelicula, vp.sobrenom_usuari, vp.data, "
        "SUM(vp.num_visualitzacions) AS num_visualitzacions, "
        "c.qualificacio, p.duracio "
        "FROM visualitzacio_pelicula vp "
        "JOIN pelicula p ON vp.titol_pelicula = p.titol "
        "JOIN contingut c ON p.titol = c.titol "
        "GROUP BY vp.titol_pelicula "
        "ORDER BY num_visualitzacions DESC, vp.data ASC "
        "LIMIT 5";

    try {
        sql::ResultSet* res = con.consultaSQL(query);

        while (res->next()) {
            DTOVisualitzacioPelicula dto(
                res->getString("titol_pelicula"),
                res->getString("sobrenom_usuari"),
                res->getString("data"),
                res->getInt("num_visualitzacions"),
                res->getString("qualificacio"),
                res->getInt("duracio"),
                ""
            );
            resultats.push_back(dto);
        }

        delete res; // Liberar recursos del resultado.
    }
    catch (const sql::SQLException& e) {
        throw std::runtime_error("Error en cercaMesVistes: " + std::string(e.what()));
    }

    return resultats;
}


vector<DTOVisualitzacioPelicula> CercadoraContingut::cercaVisualitzacionsPelicula(const std::string& sobrenomUsuari) {
    ConnexioBD& con = *ConnexioBD::getInstance();
    std::vector<DTOVisualitzacioPelicula> resultats;

    std::string query =
        "SELECT vp.titol_pelicula, "
        "vp.sobrenom_usuari, "
        "vp.data, "
        "vp.num_visualitzacions, "
        "c.qualificacio, "
        "p.duracio, "
        "c.descripcio "
        "FROM visualitzacio_pelicula vp "
        "JOIN pelicula p ON vp.titol_pelicula = p.titol "
        "JOIN contingut c ON p.titol = c.titol "
        "WHERE vp.sobrenom_usuari = '" + sobrenomUsuari + "' "
        "ORDER BY vp.data DESC;";

    sql::ResultSet* res = con.consultaSQL(query);
    while (res->next()) {
        DTOVisualitzacioPelicula dto(
            res->getString("titol_pelicula"),
            res->getString("sobrenom_usuari"),
            res->getString("data"),
            res->getInt("num_visualitzacions"),
            res->getString("qualificacio"),
            res->getInt("duracio"),
            res->getString("descripcio")
        );

        resultats.push_back(dto);
    }
    delete res;
    return resultats;
}

string CercadoraContingut::ConsultaVisualitzacioCapitol(string titolSerie, int numTemporada, int numCapitol) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    std::ostringstream result;

    try {
        //Obtenir usuari loggejat
        PetitFlix& petitFlix = PetitFlix::getInstance();
        PassarelaUsuari* usuariLoggejat = petitFlix.obtenirUsuariLoggejat();
        string sobrenomUsuari = usuariLoggejat->getSobrenom();

        //Crear la consulta SQL per obtenir la data de la visualitzacio
        std::ostringstream query;
        query << "SELECT data FROM visualitzacio_capitol "
            << "WHERE sobrenom_usuari = '" << sobrenomUsuari << "' "
            << "AND titol_serie = '" << titolSerie << "' "
            << "AND num_temporada = " << numTemporada << " "
            << "AND num_capitol = " << numCapitol;

        std::unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query.str()));

        if (res->next()) {
            std::string dataVisualitzacio = res->getString("data");

            //Retornar la data
            result << dataVisualitzacio;
        }
        else {
            result << "no visualitzat";
        }
    }
    catch (const sql::SQLException& e) {
        result << "Error al consultar la visualizacion del capitulo: " << e.what();
    }
    catch (const std::runtime_error& e) {
        result << "Error en la consulta: " << e.what();
    }
    return result.str();
}