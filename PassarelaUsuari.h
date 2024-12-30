#ifndef PASSARELA_USUARI_H
#define PASSARELA_USUARI_H

#include <string>
#include "Connexio.h"

using namespace std;

class PassarelaUsuari {
private:
    string sobrenom;
    string nom;
    string correu_electronic;
    string contrasenya;
    string data_naixement;
    string subscripcio;

public:
    PassarelaUsuari();
    // Constructor
    PassarelaUsuari(const string& sobrenomU, const string& nomU,
        const string& correu_electronicU, const string& contrasenyaU,
        const string& data_naixementU, const string& subscricpioU);

    // Getters
    string getSobrenom() const;
    string getNom() const;
    string getCorreuElectronic() const;
    string getContrasenya() const;
    string getDataNaixement() const;
    string getSubscricpio() const;

    // Setters
    void setSobrenom(const string& nouSobrenom);
    void setNom(const string& nouNom);
    void setCorreuElectronic(const string& nouCorreu);
    void setContrasenya(const string& nouContrasenya);
    void setDataNaixement(const string& nouDataNaixement);
    void setSubscripcio(const string& nouSubscripcio);

    // Operaciones sobre la base de datos
    void insereix();
    void modifica();
    void esborra();
};

#endif // PASSARELA_USUARI_H
