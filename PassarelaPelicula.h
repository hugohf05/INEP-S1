#ifndef PASSARELA_PELICULA_H
#define PASSARELA_PELICULA_H

#include <string>
#include "Connexio.h"

using namespace std;

class PassarelaPelicula {
private:
    string titol;
    string descripcio;
    string qualificacio;
    int duracio;
    string dataEstrena;

public:
    PassarelaPelicula();
    PassarelaPelicula(const string& titolP, const string& descripcioP,
        const string& qualificacioP, int duracioP,
        const string& dataEstrenaP);

    // Getters
    string getTitol() const;
    string getDescripcio() const;
    string getQualificacio() const;
    int getDuracio() const;
    string getDataEstrena() const;

    // Setters
    void setTitol(const string& nouTitol);
    void setDescripcio(const string& novaDescripcio);
    void setQualificacio(const string& novaQualificacio);
    void setDuracio(int novaDuracio);
    void setDataEstrena(const string& novaDataEstrena);

    // Operaciones sobre la base de datos
    void insereix();
    void modifica();
    void esborra();
};

#endif // PASSARELA_PELICULA_H
