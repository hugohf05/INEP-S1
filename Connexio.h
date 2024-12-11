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

public:
    // Constructor: Crea la connexió a la base de dades
    ConnexioBD(const string& host, const string& usuari, const string& contrasenya, const string& base_de_dades);

    // Destructor: Tanca la connexió a la base de dades
    ~ConnexioBD();

    // Consulta SELECT
    sql::ResultSet* consultaSQL(const string& consulta);

    // Operació d'execució (INSERT, UPDATE, DELETE)
    void execSQL(const string& comanda);
};

#endif // CONNEXIOBD_H
