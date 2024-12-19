#ifndef DTOCAPITOL_H
#define DTOCAPITOL_H

class DTOCapitol {
public:
    DTOCapitol() {}
    DTOCapitol(
        const std::string& titolSerie,
        int numTemporada,
        int numCapitol,
        const std::string& titolCapitol,
        const std::string& dataEstrena,
        const std::string& qualificacio)
        : titolSerie(titolSerie),
        numTemporada(numTemporada),
        numCapitol(numCapitol),
        titolCapitol(titolCapitol),
        dataEstrena(dataEstrena),
        qualificacio(qualificacio) {
    }

    // Métodos de acceso (getters)
    std::string obteTitolSerie() const { return titolSerie; }
    int obteNumeroTemporada() const { return numTemporada; }
    int obteNumeroCapitol() const { return numCapitol; }
    std::string obteTitolCapitol() const { return titolCapitol; }
    std::string obteDataEstrena() const { return dataEstrena; }
    std::string obteQualificacio() const { return qualificacio; }

private:
    std::string titolSerie;
    int numTemporada;
    int numCapitol;
    std::string titolCapitol;
    std::string dataEstrena;
    std::string qualificacio;
};
#endif