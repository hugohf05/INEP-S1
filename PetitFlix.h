#ifndef PETITFLIX_H
#define PETITFLIX_H

#include <stdexcept>
#include <string>
#include "PassarelaUsuari.h"

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

    void iniciaSessio(PassarelaUsuari* nouUsuari);

    void tancaSessio();
};

#endif // PETITFLIX_H
