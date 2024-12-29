#include "TxIniciSessio.h"
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"
#include "PetitFlix.h"
#include "Connexio.h"

TxIniciSessio::TxIniciSessio(const string& sobrenomU, const string& contrasenyaU)
    : sobrenom(sobrenomU), contrasenya(contrasenyaU) {}

void TxIniciSessio::executar() {
    CercadoraUsuari cercador;
    PassarelaUsuari* usuari = cercador.cerca(sobrenom); //Pasar de instancia a puntero
    string contrasenyaBD = usuari->getContrasenya();
    if (contrasenyaBD != contrasenya) {
        throw runtime_error("Hi ha hagut un error amb el sobrenom o la contrasenya");
    }
    PetitFlix::getInstance().iniciaSessio(usuari);
}