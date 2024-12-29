#include "Connexio.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

ConnexioBD* ConnexioBD::instance = nullptr;

ConnexioBD::ConnexioBD() {
    // Leer el archivo de configuración JSON
    std::ifstream configFile("config.json");  // Archivo de configuración
    json config;
    configFile >> config;

    std::string host = config["host"];
    int port = config["port"];
    std::string user = config["user"];
    std::string password = config["password"];
    std::string database = config["database"];

    // Establecer la conexión a la base de datos usando los valores del archivo JSON
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(host + ":" + std::to_string(port), user, password);
    con->setSchema(database);  // Seleccionar la base de datos
}

ConnexioBD* ConnexioBD::getInstance() {
    if (instance == nullptr) {
        // If instance doesn't exist, create it
        instance = new ConnexioBD();
    }
    return instance;
}

// Destructor: Tanca la connexi� a la base de dades
ConnexioBD::~ConnexioBD() {
    if (con) con->close();
}

sql::ResultSet* ConnexioBD::consultaSQL(const std::string& consulta) {
    sql::Statement* stmt = con->createStatement();
    return stmt->executeQuery(consulta);  // Executar la consulta SELECT
}

// Operaci� d'execuci� (INSERT, UPDATE, DELETE)
void ConnexioBD::execSQL(const std::string& comanda) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute(comanda);  // Executar la comanda (INSERT, UPDATE, DELETE)
}
