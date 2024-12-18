#include <iostream>
#include "PetitFlix.cpp"
using namespace std;

class TxEsborrarUsuari {
    string contrasenya;

public:
    TxEsborrarUsuari(const string& contrasenyaU)
        : contrasenya(contrasenyaU) {
    }

    void executar() {

        PetitFlix& sistema = PetitFlix::getInstance();
        PassarelaUsuari* usuari = sistema.obtenirUsuariLoggejat();

        if (usuari->getContrasenya() != contrasenya) {
            throw runtime_error("Error: La contrasenya no és correcta.");
        }

        usuari->esborra();
    }
};
