#include "TxConsultaNovetatsSerie.h"
#include "CercadoraContingut.h"

void TxConsultaNovetatsSerie::executar() {
	_numTemporada = CercadoraContingut::getInstance().obteUltimaTemporadaEstrena(_titolSerie);
	_ultimCapitol = CercadoraContingut::getInstance().obteUltimCapitolDeTemporada(_titolSerie, _numTemporada);
}

//Obtenim el resultat de la transacció
int TxConsultaNovetatsSerie::obteResultatTemporada() {
	return _numTemporada;
}

DTOCapitol TxConsultaNovetatsSerie::obteResultatCapitol() {
	return _ultimCapitol;
}