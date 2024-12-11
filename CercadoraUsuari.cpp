#include "CercadoraUsuari.h"

PassarelaUsuari CerdaoraUsuari::cercaPerSobrenom(const string& sobrenomU) {
    ConnexioBD& con = ConnexioBD::getInstance();
    try {
        PassarelaUsuari info;
        string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";

        sql::ResultSet* res = con.consultaSQL(sql);
        // Bucle per recórrer les dades retornades mostrant les dades de cada fila
        if (res->next()) {
            // a la funció getString es fa servir el nom de la columna de la taula
            info.setSobrenom(res->getString("sobrenom"));
            info.setNom(res->getString("nom"));
            info.setCorreuElectronic(res->getString("correu_electronic"));
        }
        else { throw runtime_error("Error: no existeix l'usuari amb aquest sobrenom")}

        return info;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        // si hi ha un error es tanca la connexió (si esta oberta)
    }
}

//Finish