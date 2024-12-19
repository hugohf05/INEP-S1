#include "CapaDeDomini.h"
#include "CercadoraUsuari.h"

/*
bool CapaDeDomini::verificaCredencials(const string& sobrenom, const string& contrasenya) {
    try {
        DTOUsuari usuari = consultaUsuari(sobrenom);
        return usuari.obteContrasenya() == contrasenya;
    } catch (const runtime_error& e) {
        return false; // Si el usuario no existe, retorna false.
    }
}
*/

DTOUsuari CapaDeDomini::consultaUsuari(string sobrenom_usuari) {
    CercadoraUsuari usuari;
    PassarelaUsuari usu = usuari.cercaPerSobrenom(sobrenom_usuari);
    return DTOUsuari(usu);
}

void CapaDeDomini::modificaUsuari(){}
void CapaDeDomini::esborraUsuari(const string& contrasenyaU) {
    try {
        TxEsborrarUsuari tx(contrasenyaU);
        tx.executar();  // Ejecutar la transacción
    }
    catch (const exception& e) {
        throw;  // Propagar el error a la capa de presentación
    }
}

//Visualitzacio Continguts

void CapaDeDomini::registreVisualitzacio(const string& titolPelicula) {
    PassarelaVisualitzacio visualitzacio(titolPelicula);
    visualitzacio.registra();
}
