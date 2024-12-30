#ifndef TX_CONSULTA_ULTIMES_NOVETATS_H
#define TX_CONSULTA_ULTIMES_NOVETATS_H

#include <vector>
#include <memory>
#include <string>
#include "DTOContingut.h"
using namespace std;

class TxConsultaUltimesNovetats {
public:
    
    // Constructor
    explicit TxConsultaUltimesNovetats(const std::string& modalitat);

    //Metode per executar la transaccio
    void executar();

    //Obtenim el resultat de la transaccio
    const vector<unique_ptr<DTOContingut>>& obteResultatContingut() const;

private:
    string modalitat;
    vector<unique_ptr<DTOContingut>> novetatsContingut;
};
#endif;
