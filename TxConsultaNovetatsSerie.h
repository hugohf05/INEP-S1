#ifndef TX_CONSULTA_NOVETATS_SERIE_H
#define TX_CONSULTA_NOVETATS_SERIE_H

#include <string>
#include "DTOCapitol.h"

class TxConsultaNovetatsSerie {
private:
    std::string _titolSerie;
    int _numTemporada;
    DTOCapitol _ultimCapitol;

public:

    //Constructor
    TxConsultaNovetatsSerie(const std::string& titolSerie)
        : _titolSerie(titolSerie) {}

    //Metode per executar la transaccio
    void executar();

    //Obtenim el resultat de la transaccio
    int obteResultatTemporada();

    DTOCapitol obteResultatCapitol();
};

#endif // TX_CONSULTA_VISUALITZACIO_CAPITOL_H
