#include "PassarelaVisualitzacio.h"

PassarelaVisualitzacioPelicula::PassarelaVisualitzacioPelicula() {
    titolPelicula = "";
    dataVisualitzacio = "";
    numVisualitzacions = 0;
}

PassarelaVisualitzacioPelicula::PassarelaVisualitzacioPelicula(const string& titol)
    : titolPelicula(titol), dataVisualitzacio(""), numVisualitzacions(0) {}

void PassarelaVisualitzacioPelicula::registra() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    try {
        PetitFlix& sistema = PetitFlix::getInstance();
        PassarelaUsuari* u = sistema.obtenirUsuariLoggejat();
        string sobrenomUsuari = u->getSobrenom();
        // Comprovar si ja existeix una visualitzaci� per a aquest usuari i pel�l�cula
        std::string queryCheck =
            "SELECT num_visualitzacions FROM visualitzacio_pelicula "
            "WHERE sobrenom_usuari = '" + sobrenomUsuari + "' AND titol_pelicula = '" + titolPelicula + "'";

        unique_ptr<sql::ResultSet> res(connexio.consultaSQL(queryCheck));

        if (res->next()) {
            // Actualitzar el n�mero de visualitzacions si ja existeix el registre
            int numVisualitzacions = res->getInt("num_visualitzacions") + 1;

            std::string queryUpdate =
                "UPDATE visualitzacio_pelicula "
                "SET num_visualitzacions = " + std::to_string(numVisualitzacions) + ", data = NOW() "
                "WHERE sobrenom_usuari = '" + sobrenomUsuari + "' AND titol_pelicula = '" + titolPelicula + "'";
            connexio.execSQL(queryUpdate);
        }
        else {
            // Inserir una nova fila si no existeix
            std::string queryInsert =
                "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) "
                "VALUES ('" + sobrenomUsuari + "', '" + titolPelicula + "', NOW(), 1)";
            connexio.execSQL(queryInsert);
        }
    }
    catch (const sql::SQLException& e) {
        throw std::runtime_error("Error al registrar la visualitzaci�: " + std::string(e.what()));
    }
}

string PassarelaVisualitzacioPelicula::obteTitol() const {
    return titolPelicula;
}

string PassarelaVisualitzacioPelicula::obteDataVisualitzacio() const {
    return dataVisualitzacio;
}

int PassarelaVisualitzacioPelicula::obteNumVisualitzacions() const {
    return numVisualitzacions;
}

