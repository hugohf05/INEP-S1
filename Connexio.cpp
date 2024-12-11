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
<<<<<<< HEAD
    // Constructor: Crea la connexió a la base de dades
    ConnexioBD(const string& host, const string& usuari, const string& contrasenya, const string& base_de_dades) {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, usuari, contrasenya);  // Establir connexió
        con->setSchema(base_de_dades);  // Seleccionar la base de dades
    }

    // Destructor: Tanca la connexió a la base de dades
=======
    // Constructor: Crea la connexiï¿½ a la base de dades
    ConnexioBD(const string& host, const string& usuari, const string& contrasenya, const string& base_de_dades) {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, usuari, contrasenya);  
        con->setSchema(base_de_dades);  // Seleccionar la base de dades
    }

    // Destructor: Tanca la connexiï¿½ a la base de dades
>>>>>>> V1
    ~ConnexioBD() {
        if (con) con->close();
    }

<<<<<<< HEAD
    // Operació de consulta (SELECT)
=======
    // Operaciï¿½ de consulta (SELECT)
>>>>>>> V1
    sql::ResultSet* consultaSQL(const string& consulta) {
        sql::Statement* stmt = con->createStatement();
        return stmt->executeQuery(consulta);  // Executar la consulta SELECT
    }

<<<<<<< HEAD
    // Operació d'execució (INSERT, UPDATE, DELETE)
=======
    // Operaciï¿½ d'execuciï¿½ (INSERT, UPDATE, DELETE)
>>>>>>> V1
    void execSQL(const string& comanda) {
        sql::Statement* stmt = con->createStatement();
        stmt->execute(comanda);  // Executar la comanda (INSERT, UPDATE, DELETE)
    }
<<<<<<< HEAD
};
=======
};
>>>>>>> V1
