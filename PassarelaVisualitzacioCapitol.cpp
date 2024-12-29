#include "PassarelaVisualitzacioCapitol.h"
#include "PetitFlix.h"
#include <string>
#include <sstream>

PassarelaVisualitzacioCapitol::PassarelaVisualitzacioCapitol(const string& titol, int numTemporada, int numCapitol) : titolSerie(titol), numTemporada(numTemporada), numCapitol(numCapitol) {}

void PassarelaVisualitzacioCapitol::registraVisualitzacioCapitol() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    try {
        //Obtenir usuari loggejat
        PetitFlix& petitFlix = PetitFlix::getInstance();
        PassarelaUsuari* usuariLoggejat = petitFlix.obtenirUsuariLoggejat();
        string sobrenomUsuari = usuariLoggejat->getSobrenom();

        //Comprovar si el capítol ha estat visualitzat previament per l'usuari
        std::string queryCheck =
            "SELECT num_visualitzacions FROM visualitzacio_capitol "
            "WHERE sobrenom_usuari = '" + sobrenomUsuari + "' "
            "AND titol_serie = '" + titolSerie + "' "
            "AND num_temporada = " + std::to_string(numTemporada) + " "
            "AND num_capitol = " + std::to_string(numCapitol);

        std::unique_ptr<sql::ResultSet> res(connexio.consultaSQL(queryCheck));

        if (res->next()) {
            //Actualitzar el número de visualitzacions
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
        throw std::runtime_error("Error al registrar la visualització del capítol: " + std::string(e.what()));
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

string PassarelaVisualitzacioCapitol::ConsultaVisualitzacioCapitol() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    std::ostringstream result;

    try {
        //Obtenir usuari loggejat
        PetitFlix& petitFlix = PetitFlix::getInstance();
        PassarelaUsuari* usuariLoggejat = petitFlix.obtenirUsuariLoggejat();
        string sobrenomUsuari = usuariLoggejat->getSobrenom();

        //Crear la consulta SQL per obtenir la data de la visualitzacio
        std::ostringstream query;
        query << "SELECT data FROM visualitzacio_capitol "
            << "WHERE sobrenom_usuari = '" << sobrenomUsuari << "' "
            << "AND titol_serie = '" << titolSerie << "' "
            << "AND num_temporada = " << numTemporada << " "
            << "AND num_capitol = " << numCapitol;

        std::unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query.str()));

        if (res->next()) {
            std::string dataVisualitzacio = res->getString("data");

            //Retornar la data
            result << dataVisualitzacio;
        }
        else {
            result << "no visualitzat";
        }
    }
    catch (const sql::SQLException& e) {
        result << "Error al consultar la visualización del capítulo: " << e.what();
    }
    catch (const std::runtime_error& e) {
        result << "Error en la consulta: " << e.what();
    }
    return result.str();
}