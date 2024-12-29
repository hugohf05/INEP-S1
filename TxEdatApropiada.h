#ifndef TX_EDAT_APROPIADA_H
#define TX_EDAT_APROPIADA_H

#include <string>

class TxEdatApropiada {
private:
    std::string _titolContingut;
    bool apte;

public:
    TxEdatApropiada(const std::string& titolContingut)
        : _titolContingut(titolContingut) {}

    void executar();

    int obtenerEdadMinima(const std::string& calificacion);

    bool obteResultat();
};

#endif // TX_CONSULTA_VISUALITZACIO_CAPITOL_H
