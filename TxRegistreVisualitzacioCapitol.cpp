#include "TxRegistreVisualitzacioCapitol.h"
#include "PassarelaVisualitzacioCapitol.h"

void TxRegistreVisualitzacioCapitol::executar() {
    PassarelaVisualitzacioCapitol visualitzacio(_titolSerie, _numTemporada, _numCapitol);
    visualitzacio.registraVisualitzacioCapitol();
}