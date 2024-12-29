#include "TxRegistreUsuari.h"
#include "Connexio.h"
#include <stdexcept>

TxRegistraUsuari::TxRegistraUsuari(const std::string& nom, const std::string& sobrenom, const std::string& contrasenya,
    const std::string& correuElectronic, const std::string& dataNaixement,
    const std::string& subscripcio)
    : nom(nom), sobrenom(sobrenom), contrasenya(contrasenya), correuElectronic(correuElectronic),
    dataNaixement(dataNaixement), subscripcio(subscripcio) {
}

void TxRegistraUsuari::executar() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    // Verificar subscripci� v�lida
    if (subscripcio != "Completa" && subscripcio != "Cinefil" && subscripcio != "Infantil") {
        throw std::invalid_argument("Subscripci� no v�lida.");
    }

    // Consulta SQL per inserir l'usuari
    std::string query = "INSERT INTO usuari (sobrenom, nom, contrasenya, correu_electronic, data_naixement, subscripcio) "
        "VALUES ('" + sobrenom + "', '" + nom + "', '" + contrasenya + "', '" + correuElectronic +
        "', '" + dataNaixement + "', '" + subscripcio + "')";

    try {
        connexio.execSQL(query);
    }
    catch (const sql::SQLException& e) {
        if (std::string(e.what()).find("Duplicate entry") != std::string::npos) {
            if (std::string(e.what()).find("correu_electronic") != std::string::npos) {
                throw std::runtime_error("Ja existeix un usuari amb aquest correu electr�nic.");
            }
            else if (std::string(e.what()).find("sobrenom") != std::string::npos) {
                throw std::runtime_error("Ja existeix un usuari amb aquest sobrenom.");
            }
        }
        throw std::runtime_error("Error en registrar l'usuari: " + std::string(e.what()));
    }
}