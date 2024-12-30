#include "TxConsultaPelicula.h"
#include "CercadoraContingut.h"

TxConsultaPelicula::TxConsultaPelicula(const std::string& titol) : titol(titol) {}

void TxConsultaPelicula::executar() {
    CercadoraContingut& cercadora = CercadoraContingut::getInstance();
    pelicula = cercadora.cercaPelicula(titol);
}

DTOPelicula TxConsultaPelicula::obteResultat() {
    return pelicula;  // Transfiere la propiedad del recurso
}
