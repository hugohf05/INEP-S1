#include "TxConsultarVisualitzacionsPelicules.h"

TxConsultarVisualitzacionsPelicules::TxConsultarVisualitzacionsPelicules() {};
TxConsultarVisualitzacionsPelicules::TxConsultarVisualitzacionsPelicules(const std::string& sobrenomUsuari) : sobrenomUsuari(sobrenomUsuari) {}

void TxConsultarVisualitzacionsPelicules::executar() {
    CercadoraContingut& cercadora = CercadoraContingut::getInstance();
    visualitzacions = cercadora.cercaVisualitzacionsPelicula(sobrenomUsuari);
}

vector<DTOVisualitzacioPelicula> TxConsultarVisualitzacionsPelicules::obteResultat() const {
    return visualitzacions;
}
