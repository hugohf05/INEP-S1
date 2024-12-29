#ifndef DTOSERIE_H
#define DTOSERIE_H

#include "DTOContingut.h"

class DTOSerie : public DTOContingut {

public:
    DTOSerie()
        : DTOContingut("", "", ""), dataEstrena(""), totalCapitols(0) {
    }

    DTOSerie(const std::string& titol, const std::string& descripcio, const std::string& qualificacio,
        const std::string& dataEstrena, int totalCapitols)
        : DTOContingut(titol, descripcio, qualificacio), dataEstrena(dataEstrena), totalCapitols(totalCapitols) {
    }

    std::string obteDataEstrena() const { return dataEstrena; }
    int obteTotalCapitols() const { return totalCapitols; }
    std::string obteTipus() const override { return "serie"; }

private:
    std::string dataEstrena; // Miembro privado
    int totalCapitols;       // Miembro privado
};

#endif
