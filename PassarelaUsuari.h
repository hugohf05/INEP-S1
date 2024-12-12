#ifndef PASSARELA_USUARI_H
#define PASSARELA_USUARI_H

#include <string>
#include "Connexio.h" // Incluye la clase para gestionar la base de datos

using namespace std;

class PassarelaUsuari {
private:
    string sobrenom;
    string nom;
    string correu_electronic;

public:
    PassarelaUsuari();
    // Constructor
    PassarelaUsuari(const string& sobrenomU, const string& nomU, const string& correuElectronicU);

    // Getters
    string getSobrenom() const;
    string getNom() const;
    string getCorreuElectronic() const;

    // Setters
    void setSobrenom(const string& nouSobrenom);
    void setNom(const string& nouNom);
    void setCorreuElectronic(const string& nouCorreu);

    // Operaciones sobre la base de datos
    void insereix();
    void modifica();
    void esborra();
};

#endif // PASSARELA_USUARI_H