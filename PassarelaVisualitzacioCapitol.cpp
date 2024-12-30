#include "PassarelaVisualitzacioCapitol.h"
#include "PetitFlix.h"
#include <string>
#include <sstream>


PassarelaVisualitzacioCapitol::PassarelaVisualitzacioCapitol() {
    titolSerie = "";
    dataVisualitzacio = "";
    numVisualitzacions = 0;
}

PassarelaVisualitzacioCapitol::PassarelaVisualitzacioCapitol(const string& titol) : titolSerie(titol) {}

string PassarelaVisualitzacioCapitol::obteTitol() const {
    return titolSerie;
}

string PassarelaVisualitzacioCapitol::obteDataVisualitzacio() const {
    return dataVisualitzacio;
}

int PassarelaVisualitzacioCapitol::obteNumVisualitzacions() const {
    return numVisualitzacions;
}

PassarelaVisualitzacioCapitol::PassarelaVisualitzacioCapitol(const string& titol, int numTemporada, int numCapitol) : titolSerie(titol), numTemporada(numTemporada), numCapitol(numCapitol) {}

void PassarelaVisualitzacioCapitol::registraVisualitzacioCapitol() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    try {
        //Obtenir usuari loggejat
        PetitFlix& petitFlix = PetitFlix::getInstance();
        PassarelaUsuari* usuariLoggejat = petitFlix.obtenirUsuariLoggejat();
        string sobrenomUsuari = usuariLoggejat->getSobrenom();

        //Comprovar si el capitol ha estat visualitzat previament per l'usuari
        std::string queryCheck =
            "SELECT num_visualitzacions FROM visualitzacio_capitol "
            "WHERE sobrenom_usuari = '" + sobrenomUsuari + "' "
            "AND titol_serie = '" + titolSerie + "' "
            "AND num_temporada = " + std::to_string(numTemporada) + " "
            "AND num_capitol = " + std::to_string(numCapitol);

        std::unique_ptr<sql::ResultSet> res(connexio.consultaSQL(queryCheck));

        if (res->next()) {
            //Actualitzar el numero de visualitzacions
            int numVisualitzacions = res->getInt("num_visualitzacions") + 1;

            std::string queryUpdate =
                "UPDATE visualitzacio_capitol "
                "SET num_visualitzacions = " + std::to_string(numVisualitzacions) + ", data = NOW() "
                "WHERE sobrenom_usuari = '" + sobrenomUsuari + "' "
                "AND titol_serie = '" + titolSerie + "' "
                "AND num_temporada = " + std::to_string(numTemporada) + " "
                "AND num_capitol = " + std::to_string(numCapitol);
            connexio.execSQL(queryUpdate);
        }
        else {
            //Insertar una nova fila a la taula, si aquesta no existeix
            std::string queryInsert =
                "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) "
                "VALUES ('" + sobrenomUsuari + "', '" + titolSerie + "', " + std::to_string(numTemporada) + ", " + std::to_string(numCapitol) + ", NOW(), 1)";
            connexio.execSQL(queryInsert);
        }
    }
    catch (const sql::SQLException& e) {
        throw std::runtime_error("Error al registrar la visualitzacio del capitol: " + std::string(e.what()));
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
