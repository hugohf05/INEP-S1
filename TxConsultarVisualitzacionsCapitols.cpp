#include "TxConsultarVisualitzacionsCapitols.h"

TxConsultarVisualitzacionsCapitols::TxConsultarVisualitzacionsCapitols(const std::string& sobrenomUsuari) : sobrenomUsuari(sobrenomUsuari) {}

void TxConsultarVisualitzacionsCapitols::executar() {
    CercadoraContingut& cercadora = CercadoraContingut::getInstance();
    visualitzacions = cercadora.cercaVisualitzacionsCapitol(sobrenomUsuari);
}

vector<DTOVisualitzacioCapitol> TxConsultarVisualitzacionsCapitols::obteResultat() const {
    return visualitzacions;
}


