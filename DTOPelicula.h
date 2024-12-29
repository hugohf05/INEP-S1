#ifndef DTOPELICULA_H
#define DTOPELICULA_H

#include "DTOContingut.h"

class DTOPelicula : public DTOContingut {

public:
    DTOPelicula()
        : DTOContingut("", "", ""), dataEstrena(""), duracio(0) {
    }

    DTOPelicula(const std::string& titol, const std::string& descripcio, const std::string& qualificacio,
        const std::string& dataEstrena, int duracio)
        : DTOContingut(titol, descripcio, qualificacio), dataEstrena(dataEstrena), duracio(duracio) {
    }

    std::string obteDataEstrena() const { return dataEstrena; }
    int obteDuracio() const { return duracio; }

    std::string obteTipus() const override { return "pelicula"; }

private:
    std::string dataEstrena;
    int duracio;
};

#endif
