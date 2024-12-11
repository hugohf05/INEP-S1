#include "CapaDeDomini.h"
#include "PassarelaUsuari.h"

void CapaDeDomini::registreUsuari(string nom, string sobrenom, string correu) {
    try {
        string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES('" + sobrenom + "', '" + nom + "', '" + correu + "')";
        connexio.execSQL(sql);
        cout << "Usuari enregistrat correctament!" << endl;
    }
    catch (sql::SQLException& e) {
        throw;
    }
}

vector<string> CapaDeDomini::consultaUsuari(string sobrenom_usuari){
    try {
        vector<string> info;
        string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";

        sql::ResultSet* res = connexio.consultaSQL(sql);
        // Bucle per recórrer les dades retornades mostrant les dades de cada fila
        while (res->next()) {
            // a la funció getString es fa servir el nom de la columna de la taula
            info.push_back(res->getString("sobrenom"));
            info.push_back(res->getString("nom"));
            info.push_back(res->getString("correu_electronic"));
        }
        if (!res->next()) { throw runtime_error("Error: no existeix l'usuari amb aquest sobrenom") }
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        // si hi ha un error es tanca la connexió (si esta oberta)
    }
}

