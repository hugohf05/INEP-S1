#ifndef TXCONSULTA_CAPITOLS_H
#define TXCONSULTA_CAPITOLS_H

#include <vector>
#include <memory>
#include <string>
#include "DTOCapitol.h"
using namespace std;

class TxConsultaCapitols {
public:
    
    //Constructor
    TxConsultaCapitols(const std::string& titolSerie, int temporada);
    
    //Metode per executar la transaccio
    void executar();
    
    //Obtenim el resultat de la transaccio
    vector<DTOCapitol> obteResultat();

private:
    string titolSerie;
    int temporada;
    vector<DTOCapitol> capitols;
};
#endif
