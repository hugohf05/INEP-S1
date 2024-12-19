#include "TxRegistreVisualitzacio.h"
#include "PassarelaVisualitzacio.h"

TxRegistreVisualitzacio::TxRegistreVisualitzacio(const std::string& titolPelicula) : titolPelicula(titolPelicula) {}

void TxRegistreVisualitzacio::executar() {
    PassarelaVisualitzacio passarela(titolPelicula);
    passarela.registra();
}
