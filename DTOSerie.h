#ifndef DTOSERIE_H
#define DTOSERIE_H

#include "DTOContingut.h"

class DTOSerie : public DTOContingut {
public:
    DTOSerie(const string& titol, const string& descripcio, const string& qualificacio,
        const string& dataEstrena, int totalCapitols)
        : DTOContingut(titol, descripcio, qualificacio), dataEstrena(dataEstrena), totalCapitols(totalCapitols) {
    }

    string obteDataEstrena() const { return dataEstrena; }
    int obteTotalCapitols() const { return totalCapitols; }
    string obteTipus() const override { return "serie"; }

private:
    string dataEstrena;
    int totalCapitols;
};


#endif
