#ifndef PETITFLIX_H
#define PETITFLIX_H

#include "PassarelaUsuari.h"
#include <stdexcept>
#include <string>

class PetitFlix {
private:
    PassarelaUsuari* usuariLoggejat;  // Usuario loggeado actualmente

    // Constructor privado
    PetitFlix() : usuariLoggejat(nullptr) {}

public:
    static PetitFlix& getInstance();

    PassarelaUsuari* obtenirUsuariLoggejat() const;

    bool estaUsuariLoggejat() const;

    string obteModalitatUsuariLoggejat() const;

    void iniciaSessio(PassarelaUsuari* usuari);
    void tancaSessio();
};

#endif // PETITFLIX_H