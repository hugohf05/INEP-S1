#include "CapaDeDomini.h"
#include "CercadoraUsuari.h"

void CapaDeDomini::registreUsuari(const string& sobrenomU, const string& nomU,
    const string& correu_electronicU, const string& contrasenyaU,
    const string& data_naixementU, const string& subscricpioU) {
    try {
        TxRegistreUsuari txRU(sobrenomU, nomU, correu_electronicU, contrasenyaU, data_naixementU, subscricpioU);
        txRU.executar();
    }
    catch (const sql::SQLException& e) {
        throw runtime_error("Error en la base de dades: " + string(e.what()));
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
void CapaDeDomini::esborraUsuari(const string& contrasenyaU) {
    try {
        TxEsborrarUsuari tx(contrasenyaU);
        tx.executar();  // Ejecutar la transacción
    }
    catch (const exception& e) {
        throw;  // Propagar el error a la capa de presentación
    }
}

