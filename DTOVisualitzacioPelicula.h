#pragma once
#include <string>
using namespace std;

class DTOVisualitzacioPelicula {
private:
    std::string titolPelicula;
    std::string sobrenomUsuari;
    std::string data;
    int numVisualitzacions;
    std::string qualificacio;
    int duracio;
    string descripcio;

public:
    DTOVisualitzacioPelicula(
        const std::string& titolPelicula,
        const std::string& sobrenomUsuari,
        const std::string& data,
        int numVisualitzacions,
        const std::string& qualificacio,
        int duracio, const string& descripcio
    ) : titolPelicula(titolPelicula), sobrenomUsuari(sobrenomUsuari),
        data(data), numVisualitzacions(numVisualitzacions),
        qualificacio(qualificacio), duracio(duracio), descripcio(descripcio) {}

    std::string obteTitolPelicula() const { return titolPelicula; }
    std::string obteSobrenomUsuari() const { return sobrenomUsuari; }
    std::string obteData() const { return data; }
    int obteNumVisualitzacions() const { return numVisualitzacions; }
    std::string obteQualificacio() const { return qualificacio; }
    int obteDuracio() const { return duracio; }
    string obteDescripcio() const { return descripcio; }
};

