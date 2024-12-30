#include "TxConsultaSerie.h"
#include "CercadoraContingut.h"


TxConsultaSerie::TxConsultaSerie(const std::string& titolSerie) : _titolSerie(titolSerie) {}

DTOSerie TxConsultaSerie::obteResultat() const {
    return _resultat;
}

void TxConsultaSerie::executar() {
    CercadoraContingut& cercadora = CercadoraContingut::getInstance();
    _resultat = cercadora.cercaSerie(_titolSerie);
}
