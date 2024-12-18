#ifndef DTO_PELICULA_H
#define DTO_PELICULA_H

#include <string>
using namespace std;

class DTOPelicula {
private:
    string titol;
    string descripcio;
    string qualificacio;
    int duracio;
    string dataEstrena;

public:
    DTOPelicula(const string& titolP, const string& descripcioP,
        const string& qualificacioP, int duracioP,
        const string& dataEstrenaP)
        : titol(titolP), descripcio(descripcioP), qualificacio(qualificacioP),
        duracio(duracioP), dataEstrena(dataEstrenaP) {
    }

    // Getters
    string getTitol() const { return titol; }
    string getDescripcio() const { return descripcio; }
    string getQualificacio() const { return qualificacio; }
    int getDuracio() const { return duracio; }
    string getDataEstrena() const { return dataEstrena; }
};

#endif // DTO_PELICULA_H
