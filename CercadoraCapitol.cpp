#include "CercadoraCapitol.h"

/*PassarelaVisualitzacioCapitol CercadoraCapitol::cercaPerTitol(const string& titolPelicula) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    string query = "SELECT * FROM pelicula WHERE titol = '" + titolPelicula + "'";
    sql::ResultSet* resultat = connexio.consultaSQL(query);

    if (!resultat->next()) {
        delete resultat;
        throw runtime_error("Pel·lícula no trobada.");
    }

    PassarelaVisualitzacioCapitol pelicula(
        resultat->getString("titol"),
        resultat->getString("descripcio"),
        resultat->getString("qualificacio"),
        resultat->getInt("duracio"),
        resultat->getString("data_estrena")
    );

    delete resultat;
    return pelicula;
}*/
vector<DTOVisualitzacioCapitol> CercadoraCapitol::cercaVisualitzacions(const std::string& sobrenomUsuari) {
    ConnexioBD& con = *ConnexioBD::getInstance();
    vector<DTOVisualitzacioCapitol> resultats;

    string query =
        "SELECT vc.titol_serie, vc.num_capitol, vc.num_temporada, vc.data, vc.num_visualitzacions, "
        "c.qualificacio "
        "FROM Visualitzacio_capitol vc "
        "JOIN Contingut c ON vc.titol_serie = c.titol "
        "WHERE vc.sobrenom_usuari = '" + sobrenomUsuari + "'";

    con.execSQL(query);

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
