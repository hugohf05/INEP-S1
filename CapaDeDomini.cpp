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

bool CapaDeDomini::verificaCredencials(const std::string& sobrenom, const std::string& contrasenya) {
    try {
        DTOUsuari usuari = consultaUsuari(sobrenom);
        return usuari.obteContrasenya() == contrasenya;
    } catch (const std::runtime_error& e) {
        return false; // Si el usuario no existe, retorna false.
    }
}

DTOUsuari CapaDeDomini::consultaUsuari(string sobrenom_usuari) {
    CercadoraUsuari usuari;
    PassarelaUsuari usu = usuari.cercaPerSobrenom(sobrenom_usuari);
    return DTOUsuari(usu);
}

void CapaDeDomini::modificaUsuari(){}
void CapaDeDomini::esborraUsuari(){}
