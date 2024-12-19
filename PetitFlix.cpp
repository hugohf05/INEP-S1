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