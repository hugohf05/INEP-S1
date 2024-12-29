#include "TxConsultaCapitols.h"
#include "CercadoraContingut.h"

TxConsultaCapitols::TxConsultaCapitols(const std::string& titolSerie, int temporada) : titolSerie(titolSerie), temporada(temporada) {}

void TxConsultaCapitols::executar() {
	capitols = CercadoraContingut::getInstance().obtenirCapitolsPerTemporada(titolSerie, temporada);
}
vector<DTOCapitol> TxConsultaCapitols::obteResultat() {
	return capitols;
}