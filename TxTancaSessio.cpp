#include "TxTancaSessio.h"
#include "CercadoraUsuari.h"  // Asumiendo que esta clase se encarga de buscar usuarios en la base de datos
#include "PassarelaUsuari.h"  // Clase que contiene la información de un usuario
#include "PetitFlix.h"


TxTancaSessio::TxTancaSessio() {}

void TxTancaSessio::executar() {
    PetitFlix::getInstance().tancaSessio();
}