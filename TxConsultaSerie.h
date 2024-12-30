#ifndef TXCONSULTA_SERIE_H
#define TXCONSULTA_SERIE_H

#include "DTOSerie.h"

class TxConsultaSerie {
private:
    std::string _titolSerie;
    DTOSerie _resultat;

public:
    
    //Constructor
    TxConsultaSerie(const std::string& titolSerie);
    
    //Obtenim el resultat de la transaccio
    DTOSerie obteResultat() const;
    
    //Metode per executar la transaccio
    void executar();
};
#endif
