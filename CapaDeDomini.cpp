#include "CapaDeDomini.h"
#include "CercadoraUsuari.h"
void CapaDeDomini::registreUsuari(string nom, string sobrenom, string correu) {
    PassarelaUsuari usuari(sobrenom, nom, correu);
    try {
        usuari.insereix();
    }
    catch (sql::SQLException& e) {
        throw;
    }
}

DTOUsuari CapaDeDomini::consultaUsuari(string sobrenom_usuari) {
    CercadoraUsuari usuari;
    PassarelaUsuari usu = usuari.cercaPerSobrenom(sobrenom_usuari);
    return DTOUsuari(usu);
}

void CapaDeDomini::modificaUsuari(){}
void CapaDeDomini::esborraUsuari(){}