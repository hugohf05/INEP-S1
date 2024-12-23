#include "PetitFlix.h"

PetitFlix& PetitFlix::getInstance() {
    static PetitFlix instance;
    return instance;
}

PassarelaUsuari* PetitFlix::obtenirUsuariLoggejat() const {
    if (!usuariLoggejat) {
        throw runtime_error("Error: No hi ha cap usuari loggejat.");
    }
    return usuariLoggejat;
}

bool PetitFlix::estaUsuariLoggejat() const {
    return usuariLoggejat != nullptr;
}

string PetitFlix::obteModalitatUsuariLoggejat() const {
    return usuariLoggejat->getSubscricpio();
}

void PetitFlix::iniciaSessio(PassarelaUsuari* usuari){
if (estaUsuariLoggejat()) {
        throw std::runtime_error("Ja hi ha un usuari loggejat");
    }
    usuariLoggejat = usuari;
}

// Cerrar sesión
void PetitFlix::tancaSessio() {
    if (!estaUsuariLoggejat()) {
        throw std::runtime_error("No hi ha cap sessió per tancar");
    }
    usuariLoggejat = nullptr;
}