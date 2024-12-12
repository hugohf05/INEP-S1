#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"

PassarelaUsuari CercadoraUsuari::cercaPerSobrenom(const string& sobrenomU) {
    ConnexioBD& con = *ConnexioBD::getInstance();
    PassarelaUsuari info;
    string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenomU + "'";

    sql::ResultSet* res = con.consultaSQL(sql);
    // Bucle per recórrer les dades retornades mostrant les dades de cada fila
    if (res->next()) {
        // a la funció getString es fa servir el nom de la columna de la taula
        info.setSobrenom(res->getString("sobrenom"));
        info.setNom(res->getString("nom"));
        info.setCorreuElectronic(res->getString("correu_electronic"));
    }
    else { throw runtime_error("Error: no existeix l'usuari"); }

    return info;
}

//Finish