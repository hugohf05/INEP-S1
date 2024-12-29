#include "Connexio.h"

ConnexioBD* ConnexioBD::instance = nullptr;

ConnexioBD::ConnexioBD() {
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep18", "aFoo1ahNgohGei");  // Establir connexi�
    con->setSchema("inep18");  // Seleccionar la base de dades
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

sql::ResultSet* ConnexioBD::consultaSQL(const string& consulta) {
    sql::Statement* stmt = con->createStatement();
    return stmt->executeQuery(consulta);  // Executar la consulta SELECT
}

// Operaci� d'execuci� (INSERT, UPDATE, DELETE)
// Operaci� d'execuci� (INSERT, UPDATE, DELETE)
void ConnexioBD::execSQL(const string& comanda) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute(comanda);  // Executar la comanda (INSERT, UPDATE, DELETE)
}