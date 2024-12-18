#include <iostream>
using namespace std;

class TxRegistreUsuari {
    string sobrenom, nom, correu, contrasenya, data_naixement, subscripcio;

public:
    TxRegistreUsuari(const string& sobrenomU, const string& nomU,
        const string& correu_electronicU, const string& contrasenyaU,
        const string& data_naixementU, const string& subscripcioU)
        : sobrenom(sobrenomU), nom(nomU), correu(correu_electronicU),
        contrasenya(contrasenyaU), data_naixement(data_naixementU), subscripcio(subscripcioU) {
    }

    void executar() {
        if (sobrenom.empty() || nom.empty() || contrasenya.empty() || correu.empty()) {
            throw runtime_error("Els camps sobrenom, nom, contrasenya i correu son obligatoris.");
        }

        PassarelaUsuari usuari(sobrenom, nom, contrasenya, correu, data_naixement, subscripcio);

        usuari.insereix();
    }
};
