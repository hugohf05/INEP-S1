#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

using namespace std;

class ConnexioBD {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

public:
    // Constructor: Crea la connexi� a la base de dades
    ConnexioBD(const string& host, const string& usuari, const string& contrasenya, const string& base_de_dades) {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, usuari, contrasenya);  // Establir connexi�
        con->setSchema(base_de_dades);  // Seleccionar la base de dades
    }

    // Destructor: Tanca la connexi� a la base de dades
    // Constructor: Crea la connexi� a la base de dades
    ConnexioBD(const string& host, const string& usuari, const string& contrasenya, const string& base_de_dades) {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, usuari, contrasenya);  
        con->setSchema(base_de_dades);  // Seleccionar la base de dades
    }

    // Destructor: Tanca la connexi� a la base de dades
    ~ConnexioBD() {
        if (con) con->close();
    }

    sql::ResultSet* consultaSQL(const string& consulta) {
        sql::Statement* stmt = con->createStatement();
        return stmt->executeQuery(consulta);  // Executar la consulta SELECT
    }

    // Operaci� d'execuci� (INSERT, UPDATE, DELETE)
    // Operaci� d'execuci� (INSERT, UPDATE, DELETE)
    void execSQL(const string& comanda) {
        sql::Statement* stmt = con->createStatement();
        stmt->execute(comanda);  // Executar la comanda (INSERT, UPDATE, DELETE)
    }
};
