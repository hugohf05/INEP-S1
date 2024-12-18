#include "CercadoraContingut.h"
#include <iostream>

using namespace std;

PassarelaPelicula CercadoraContingut::cercaPelicula(const string& titolPelicula) {
    ConnexioBD& connexio = ConnexioBD::getInstance();
    std::string query = "SELECT * FROM pelicula WHERE titol = '" + titolPelicula + "'";
    DTOPelicula resultat = connexio.executarSelect(query);

    if (!resultat->next()) {
        throw runtime_error("Pel·lícula no trobada.");
    }

    return PassarelaPelicula(
        resultat->getString("titol"),
        resultat->getString("descripcio"),
        resultat->getString("qualificacio"),
        resultat->getInt("duracio"),
        resultat->getString("data_estrena")
    );
}