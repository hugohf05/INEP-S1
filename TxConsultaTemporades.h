#ifndef TXCONSULTA_TEMPORADES_H
#define TXCONSULTA_TEMPORADES_H

#include <vector>
#include <memory>
#include <string>
using namespace std;

class TxConsultaTemporades {
public:
    
    //Constructor
    TxConsultaTemporades(const std::string& titolSerie);
    
    //Metode per executar la transaccio
    void executar();
    
    //Obtenim el resultat de la transaccio
    int obteResultat();

private:
    string titolSerie;
    int temporades;
};
#endif
