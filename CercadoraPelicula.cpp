#include "CercadoraPelicula.h"

DTOPelicula CercadoraPelicula::cercaPerTitol(const string& titol) {
    ConnexioBD& con = *ConnexioBD::getInstance();
    string query =
        "SELECT c.titol, c.descripcio, c.qualificacio, p.duracio, p.data_estrena "
        "FROM Contingut c "
        "JOIN pelicula p ON c.titol = p.titol "
        "WHERE c.titol = '" + titol + "' AND c.tipus = 'pelicula'";

    sql::ResultSet* resultat = nullptr;

    try {
        resultat = con.consultaSQL(query);

        if (!resultat->next()) {
            throw runtime_error("Pel�l�cula no trobada.");
        }

        DTOPelicula pelicula(
            resultat->getString("titol"),
            resultat->getString("descripcio"),
            resultat->getString("qualificacio"),
            resultat->getString("data_estrena"),
            resultat->getInt("duracio")
        );

        delete resultat;
        return pelicula;

    }
    catch (const sql::SQLException& e) {
        if (resultat) delete resultat;
        throw runtime_error("Error en la consulta SQL: " + string(e.what()));
    }
}


vector<DTOPelicula> CercadoraPelicula::cercaRelacionades(const string& titolPelicula) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    string query = "SELECT c2.* FROM relacionat r "
        "JOIN contingut c1 ON r.titol_x = c1.titol "
        "JOIN contingut c2 ON r.titol_y = c2.titol "
        "WHERE c1.titol = '" + titolPelicula + "' "
        "ORDER BY c2.data_estrena DESC";
    sql::ResultSet* resultat = connexio.consultaSQL(query);

    vector<DTOPelicula> relacionades;
    while (resultat->next()) {
        relacionades.emplace_back(
            resultat->getString("titol"),
            resultat->getString("descripcio"),
            resultat->getString("qualificacio"),
            resultat->getString("data_estrena"),
            resultat->getInt("duracio")
        );
    }
    delete resultat;
    return relacionades;
}