#include "CercadoraPelicula.h"

PassarelaPelicula CercadoraPelicula::cercaPerTitol(const string& titolPelicula) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    string query = "SELECT * FROM pelicula WHERE titol = '" + titolPelicula + "'";
    sql::ResultSet* resultat = connexio.consultaSQL(query);

    if (!resultat->next()) {
        delete resultat;
        throw runtime_error("Pel·lícula no trobada.");
    }

    PassarelaPelicula pelicula(
        resultat->getString("titol"),
        resultat->getString("descripcio"),
        resultat->getString("qualificacio"),
        resultat->getInt("duracio"),
        resultat->getString("data_estrena")
    );

    delete resultat;
    return pelicula;
}

vector<PassarelaPelicula> CercadoraPelicula::cercaRelacionades(const string& titolPelicula) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    string query = "SELECT c2.* FROM relacionat r "
        "JOIN contingut c1 ON r.titol_x = c1.titol "
        "JOIN contingut c2 ON r.titol_y = c2.titol "
        "WHERE c1.titol = '" + titolPelicula + "' "
        "ORDER BY c2.data_estrena DESC";
    sql::ResultSet* resultat = connexio.consultaSQL(query);

    vector<PassarelaPelicula> relacionades;
    while (resultat->next()) {
        relacionades.emplace_back(
            resultat->getString("titol"),
            resultat->getString("descripcio"),
            resultat->getString("qualificacio"),
            resultat->getInt("duracio"),
            resultat->getString("data_estrena")
        );
    }
    delete resultat;
    return relacionades;
}