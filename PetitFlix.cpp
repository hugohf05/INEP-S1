#include "PassarelaUsuari.h"

class PetitFlix {
private:
    static PetitFlix* instancia;  // Instancia única (Singleton)
    PassarelaUsuari* usuariLoggejat;  // Usuario loggeado actualmente

    // Constructor privado
    PetitFlix() : usuariLoggejat(nullptr) {}

public:
    static PetitFlix& getInstance() {
        static PetitFlix instance;
        return instance;
    }

    PassarelaUsuari* obtenirUsuariLoggejat() const {
        if (!usuariLoggejat) {
            throw runtime_error("Error: No hi ha cap usuari loggejat.");
        }
        return usuariLoggejat;
    }
};