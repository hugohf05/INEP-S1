#include "CercadoraContingut.h"
#include <iostream>

using namespace std;

PassarelaPelicula CercadoraContingut::cercaPelicula(const string& titolPelicula) {
    ConnexioBD& con = *ConnexioBD::getInstance();
    string query = "SELECT * FROM pelicula WHERE titol = '" + titolPelicula + "'";
    sql::ResultSet* resultat = con.consultaSQL(query);

    if (!resultat->next()) {
        delete resultat;  // Libera memoria
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