#pragma once
#include <string>
using namespace std;

class DTOVisualitzacioCapitol {
private:
    std::string titolSerie;
    int numCapitol;
    int numTemporada;
    std::string dataVisualitzacio;
    int numVisualitzacions;
    string qualificacio;

public:
    DTOVisualitzacioCapitol(
        const std::string& titolSerie,
        int numCapitol,
        int numTemporada,
        const std::string& dataVisualitzacio,
        int numVisualitzacions,
        const std::string& qualificacio
    ) : titolSerie(titolSerie), numCapitol(numCapitol), numTemporada(numTemporada),
        dataVisualitzacio(dataVisualitzacio), numVisualitzacions(numVisualitzacions),
        qualificacio(qualificacio) {}

    string obteTitolSerie() const { return titolSerie; }
    int obteNumCapitol() const { return numCapitol; }
    int obteNumTemporada() const { return numTemporada; }
    string obteDataVisualitzacio() const { return dataVisualitzacio; }
    int obteNumVisualitzacions() const { return numVisualitzacions; }
    string obteQualificacio() const { return qualificacio; }
};
