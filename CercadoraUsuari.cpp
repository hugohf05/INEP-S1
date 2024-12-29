#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"

PassarelaUsuari* CercadoraUsuari::cerca(const string& sobrenomU) {
    ConnexioBD& con = *ConnexioBD::getInstance();
    PassarelaUsuari* info = new PassarelaUsuari();
    string sql = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";

    sql::ResultSet* res = con.consultaSQL(sql);
    if (res->next()) {
        info->setSobrenom(res->getString("sobrenom"));
        info->setNom(res->getString("nom"));
        info->setCorreuElectronic(res->getString("correu_electronic"));
        info->setContrasenya(res->getString("contrasenya"));
        info->setDataNaixement(res->getString("data_naixement"));
        info->setSubscripcio(res->getString("subscripcio"));
    }
    else {
        delete info;  // Limpieza si no se encuentra el usuario
        throw runtime_error("Error: no existeix l'usuari");
    }
    return info;
}

//Finish