#include "TxConsultaRelacionades.h"
#include "CercadoraContingut.h"

TxConsultaRelacionades::TxConsultaRelacionades(const std::string& titolPelicula) : titolPelicula(titolPelicula) {}

void TxConsultaRelacionades::executar() {
    CercadoraContingut& cercadora = CercadoraContingut::getInstance();
    relacionades = cercadora.cercaRelacionades(titolPelicula);
}

std::vector<DTOPelicula> TxConsultaRelacionades::obteResultat() const {
    return relacionades;
}
