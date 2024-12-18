#include "CercadoraPelicula.h"

PassarelaPelicula CercadoraPelicula::cercaPerTitol(const string& titolPelicula) {
    ConnexioBD& connexio = ConnexioBD::getInstance();
    string query = "SELECT * FROM pelicula WHERE titol = '" + titolPelicula + "'";
    DTOPelicula resultat = connexio.consultaSQL(query);

    if (!resultat->next()) {
        throw runtime_error("Pel·lícula no trobada.");
    }

    return PassarelaPelicula(
        resultat->titol,
        resultat->descripcio,
        resultat->qualificacio,
        resultat->duracio,
        resultat->dataEstrena
    );
}

vector<PassarelaPelicula> CercadoraPelicula::cercaRelacionades(const string& titolPelicula) {
    ConnexioBD& connexio = ConnexioBD::getInstance();
    string query = "SELECT c2.* FROM relacionat r "
        "JOIN contingut c1 ON r.titol_x = c1.titol "
        "JOIN contingut c2 ON r.titol_y = c2.titol "
        "WHERE c1.titol = '" + titolPelicula + "' "
        "ORDER BY c2.data_estrena DESC";
    auto resultat = connexio.consultaSQL(query);

    vector<PassarelaPelicula> relacionades;
    while (resultat->next()) {
        relacionades.emplace_back(
            resultat->titol,
            resultat->descripcio,
            resultat->qualificacio,
            resultat->duracio,
            resultat->dataEstrena
        );
    }
    return relacionades;
}