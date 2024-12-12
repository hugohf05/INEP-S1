#ifndef CONNEXIOBD_H
#define CONNEXIOBD_H

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

    ConnexioBD();

    static ConnexioBD* instance;

public:
    // Constructor: Crea la connexió a la base de dades
    static ConnexioBD* getInstance();

    // Destructor: Tanca la connexió a la base de dades
    ~ConnexioBD();

    // Consulta SELECT
    sql::ResultSet* consultaSQL(const string& consulta);

    // Operació d'execució (INSERT, UPDATE, DELETE)
    void execSQL(const string& comanda);
};

#endif // CONNEXIOBD_H
