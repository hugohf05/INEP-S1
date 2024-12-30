#include "TxConsultaVisualitzacioCapitol.h"
#include "CercadoraContingut.h"

void TxConsultaVisualitzacioCapitol::executar() {
    CercadoraContingut& cercadora = CercadoraContingut::getInstance();
    dataVisualitzacio = cercadora.ConsultaVisualitzacioCapitol(_titolSerie, _numTemporada, _numCapitol);
}

string TxConsultaVisualitzacioCapitol::obteResultat() {
    return dataVisualitzacio;
}
