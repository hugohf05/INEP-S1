#include "PassarelaVisualitzacio.h"
#include "Connexio.h"
#include <string>

PassarelaVisualitzacio::PassarelaVisualitzacio(const string& titol) : titolPelicula(titol) {}

void PassarelaVisualitzacio::registra() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    try {
        PetitFlix& sistema = PetitFlix::getInstance();
        PassarelaUsuari* u = sistema.obtenirUsuariLoggejat();
        string sobrenomUsuari = u->getSobrenom();
        // Comprovar si ja existeix una visualització per a aquest usuari i pel·lícula
        std::string queryCheck =
            "SELECT num_visualitzacions FROM visualitzacio_pelicula "
            "WHERE sobrenom_usuari = '" + sobrenomUsuari + "' AND titol_pelicula = '" + titolPelicula + "'";

        unique_ptr<sql::ResultSet> res(connexio.consultaSQL(queryCheck));

        if (res->next()) {
            // Actualitzar el número de visualitzacions si ja existeix el registre
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
        throw std::runtime_error("Error al registrar la visualització: " + std::string(e.what()));
    }
}

