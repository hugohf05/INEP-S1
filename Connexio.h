#ifndef CONNEXIOBD_H
#define CONNEXIOBD_H

#include <iostream>
#include <string>
#include "C:/Users/NBCom/OneDrive/Escritorio/Mysql/mysql-connector-c++-9.1.0-winx64/include/jdbc/mysql_driver.h"
#include "C:/Users/NBCom/OneDrive/Escritorio/Mysql/mysql-connector-c++-9.1.0-winx64/include/jdbc/mysql_connection.h"
#include "C:/Users/NBCom/OneDrive/Escritorio/Mysql/mysql-connector-c++-9.1.0-winx64/include/jdbc/cppconn/prepared_statement.h"
#include "C:/Users/NBCom/OneDrive/Escritorio/Mysql/mysql-connector-c++-9.1.0-winx64/include/jdbc/cppconn/resultset.h"
#include "C:/Users/NBCom/OneDrive/Escritorio/Mysql/mysql-connector-c++-9.1.0-winx64/include/jdbc/cppconn/exception.h"

using namespace std;

class ConnexioBD {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

    ConnexioBD();

    static ConnexioBD* instance;

public:
    // Constructor: Crea la connexi� a la base de dades
    static ConnexioBD* getInstance();

    // Destructor: Tanca la connexi� a la base de dades
    ~ConnexioBD();

    // Consulta SELECT
    sql::ResultSet* consultaSQL(const string& consulta);

    // Operaci� d'execuci� (INSERT, UPDATE, DELETE)
    void execSQL(const string& comanda);
};

#endif // CONNEXIOBD_H