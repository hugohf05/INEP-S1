#include "TxEsborraUsuari.h"
#include "PetitFlix.h"
#include "PassarelaUsuari.h"

TxEsborrarUsuari::TxEsborrarUsuari(const string& contrasenyaU)
    : contrasenya(contrasenyaU) {
}

void TxEsborrarUsuari::executar() {
    PetitFlix& sistema = PetitFlix::getInstance();
    PassarelaUsuari* usuari = sistema.obtenirUsuariLoggejat();

    if (usuari->getContrasenya() != contrasenya) {
        throw runtime_error("Error: La contrasenya no és correcta.");
    }

    usuari->esborra();
    //usuari->tancarSesio();
}
