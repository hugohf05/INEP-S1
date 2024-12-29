#ifndef DTOCONTINGUT_H
#define DTOCONTINGUT_H

#include <string>

class DTOContingut {
public:
    DTOContingut(const std::string& titol, const std::string& descripcio, const std::string& qualificacio)
        : titol(titol), descripcio(descripcio), qualificacio(qualificacio) {
    }

    virtual ~DTOContingut() {}

    // M�todos accesores
    std::string obteTitol() const { return titol; }
    std::string obteDescripcio() const { return descripcio; }
    std::string obteQualificacio() const { return qualificacio; }

    // M�todo virtual puro para obtener el tipo de contenido
    virtual std::string obteTipus() const = 0;

protected:
    std::string titol;
    std::string descripcio;
    std::string qualificacio;
};

#endif