#include "TxConsultaVisualitzacioCapitol.h"
#include "PassarelaVisualitzacioCapitol.h"

void TxConsultaVisualitzacioCapitol::executar() {
    PassarelaVisualitzacioCapitol visualitzacio(_titolSerie, _numTemporada, _numCapitol);
    dataVisualitzacio = visualitzacio.ConsultaVisualitzacioCapitol();
}

string TxConsultaVisualitzacioCapitol::obteResultat() {
    return dataVisualitzacio;
}