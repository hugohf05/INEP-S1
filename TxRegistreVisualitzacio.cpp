#include "TxRegistreVisualitzacio.h"
#include "PassarelaVisualitzacio.h"

TxRegistreVisualitzacio::TxRegistreVisualitzacio(const std::string& titolPelicula) : titolPelicula(titolPelicula) {}

void TxRegistreVisualitzacio::executar() {
    PassarelaVisualitzacioPelicula passarela(titolPelicula);
    passarela.registra();
}
