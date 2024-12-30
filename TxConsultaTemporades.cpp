#include "TxConsultaTemporades.h"
#include "CercadoraContingut.h"

TxConsultaTemporades::TxConsultaTemporades(const std::string& titolSerie) : titolSerie(titolSerie) {}

void TxConsultaTemporades::executar() {
	temporades = CercadoraContingut::getInstance().obtenirNumeroTemporades(titolSerie);
}

int TxConsultaTemporades::obteResultat() {
	return temporades;
}
