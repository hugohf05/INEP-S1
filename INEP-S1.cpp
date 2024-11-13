// INEP-S1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
// INEP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Carlos Agudo (cybernze)
// Sergio Gonzalez Carazo
// David Pérez Cruz (dperezcruz024)
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std;

void registreUsuari() {
    string nom, sobrenom, correu;
    cout << "Nom: " << endl;
    cin >> nom;
    cout << "Sobrenom: " << endl;
    cin >> sobrenom;
    cout << "Correu Electronic: " << endl;
    cin >> correu;
    if (nom != "" and sobrenom != "" and correu!= "") {
        sql::mysql::MySQL_Driver* driver = NULL;
        sql::Connection* con = NULL;
        sql::Statement* stmt = NULL;
        try {
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep18", "aFoo1ahNgohGei");
            con->setSchema("inep18");
            stmt = con->createStatement();
            // Sentència SQL per obtenir totes les files de la taula usuari.
            // S’ha de posar el nom de la taula tal i com el teniu a la base
            // de dades respectant minúscules i majúscules
            string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES('"+ sobrenom + "', '" + nom + "', '" + correu + "')";
            stmt->execute(sql);
            con->close();
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Error: " << e.what() << std::endl;
            // si hi ha un error es tanca la connexió (si esta oberta)
            if (con != NULL) con->close();
        }
    }
    else {
        cout << "Error al registrar l'usuari." << endl;
    }
}

void consultaUsuari()
{
    string sobrenom_usuari;
    cout << "Entra un sobrenom: ";
    cin >> sobrenom_usuari;
    sql::mysql::MySQL_Driver* driver = NULL;
    sql::Connection* con = NULL;
    sql::Statement* stmt = NULL;
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep18", "aFoo1ahNgohGei");
        con->setSchema("inep18");
        stmt = con->createStatement();
        // Sentència SQL per obtenir totes les files de la taula usuari.
        // S’ha de posar el nom de la taula tal i com el teniu a la base
        // de dades respectant minúscules i majúscules
        string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
        sql::ResultSet* res = stmt->executeQuery(sql);
        if (!res->next()) { cout << "Usuari amb sobrenom " << sobrenom_usuari << " no trobat" << endl; }
        // Bucle per recórrer les dades retornades mostrant les dades de cada fila
        while (res->next()) {
            // a la funció getString es fa servir el nom de la columna de la taula
            cout << "Sobrenom: " << res->getString("sobrenom") << endl;
            cout << "Nom: " << res->getString("nom") << endl;
            cout << "Correu: " << res->getString("correu_electronic") << endl;
        }
        con->close();
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        // si hi ha un error es tanca la connexió (si esta oberta)
        if (con != NULL) con->close();
    }
}

void modificaUsuari() {
    string sobrenom, nom, correu;
    cout << "Entra un sobrenom: " << endl;
    cin >> sobrenom;
    if (sobrenom != "") {

        cout << "Entra el nou nom: " << endl;
        cin >> nom;
        cout << "Entra el nou correu electronic: " << endl;
        cin >> correu;

        sql::mysql::MySQL_Driver* driver = NULL;
        sql::Connection* con = NULL;
        sql::Statement* stmt = NULL;
        try {
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep18", "aFoo1ahNgohGei");
            con->setSchema("inep18");
            stmt = con->createStatement();
            // Sentència SQL per obtenir totes les files de la taula usuari.
            // S’ha de posar el nom de la taula tal i com el teniu a la base
            // de dades respectant minúscules i majúscules
            string sql = "UPDATE Usuari SET nom = '" + nom + "', correu_electronic = '" + correu + "' WHERE sobrenom = '" + sobrenom + "'";
            stmt->execute(sql);
            con->close();
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Error: " << e.what() << std::endl;
            // si hi ha un error es tanca la connexió (si esta oberta)
            if (con != NULL) con->close();
        }
    }
    else {
        cout << "Error al consultar l'usuari." << endl;
    }
}

void esborraUsuari() {
    string sobrenom;
    cout << "Entra un sobrenom: " << endl;
    cin >> sobrenom;
    if (sobrenom != "") {
        sql::mysql::MySQL_Driver* driver = NULL;
        sql::Connection* con = NULL;
        sql::Statement* stmt = NULL;
        try {
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep18", "aFoo1ahNgohGei");
            con->setSchema("inep18");
            stmt = con->createStatement();
            // Sentència SQL per obtenir totes les files de la taula usuari.
            // S’ha de posar el nom de la taula tal i com el teniu a la base
            // de dades respectant minúscules i majúscules
            string sql = "DELETE FROM Usuari WHERE sobrenom = '"+sobrenom+"'";
            stmt->execute(sql);
            con->close();
            cout << "S'ha esborrat l'usuari amb sobrenom: " + sobrenom << endl;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Error: " << e.what() << std::endl;
            // si hi ha un error es tanca la connexió (si esta oberta)
            if (con != NULL) con->close();
        }
    }
    else {
        cout << "Error al consultar l'usuari." << endl;
    }
}

void gestioUsuari() {
    int opt2;
    cout << "1. Registre usuari" << endl;
    cout << "2. Consulta usuari" << endl;
    cout << "3. Modifica usuari" << endl;
    cout << "4. Esborra usuari" << endl;
    cout << "5. Tornar" << endl;

    while (cin >> opt2 && opt2 != 5) {
        switch (opt2) {
        case 1:
            registreUsuari();
            break;
        case 2:
            consultaUsuari();
            break;
        case 3:
            modificaUsuari();
            break;
        case 4:
            esborraUsuari();
            break;
        default:
            cout << "Opcio no valida" << endl;
        }
        cout << endl;
        cout << "1. Registre usuari" << endl;
        cout << "2. Consulta usuari" << endl;
        cout << "3. Modifica usuari" << endl;
        cout << "4. Esborra usuari" << endl;
        cout << "5. Tornar" << endl;
    }
}

void gestioContinguts() {
    int opt2;
    cout << "1. Gestio pel.licules" << endl;
    cout << "2. Gestio series" << endl;
    cout << "3. Tornar" << endl;

    while (cin >> opt2 && opt2 != 3) {
        switch (opt2) {
        case 1:
            // gestioPeli(); // A�adir funcionalidad para peliculas
            break;
        case 2:
            // gestioSeries(); // A�adir funcionalidad para series
            break;
        default:
            cout << "Opcio no valida" << endl;
        }
        cout << "1. Gestio pel.licules" << endl;
        cout << "2. Gestio series" << endl;
        cout << "3. Tornar" << endl;
    }
}

void consultes() {
    int opt2;
    cout << "1. Consulta per qualificacio d'edat" << endl;
    cout << "2. Ultimes novetats" << endl;
    cout << "3. Proximes estrenes" << endl;
    cout << "4. Tornar" << endl;

    while (cin >> opt2 && opt2 != 4) {
        switch (opt2) {
        case 1:
            // qualiEdat(); // A�adir funcionalidad de consulta por edad
            break;
        case 2:
            // novetats(); // A�adir funcionalidad de ultimas novedades
            break;
        case 3:
            // estrenes(); // A�adir funcionalidad de proximas estrenas
            break;
        default:
            cout << "Opcio no valida" << endl;
        }
        cout << "1. Consulta per qualificacio d'edat" << endl;
        cout << "2. Ultimes novetats" << endl;
        cout << "3. Proximes estrenes" << endl;
        cout << "4. Tornar" << endl;
    }
}

int main() {
    //primer canvi
    int opt;
    cout << "1. Gestio usuari" << endl;
    cout << "2. Gestio continguts" << endl;
    cout << "3. Consultes" << endl;
    cout << "4. Sortir" << endl;
    cout << "Escull una opcio: " << endl;

    while (cin >> opt && opt != 4) {
        switch (opt) {
        case 1:
            gestioUsuari();
            break;
        case 2:
            gestioContinguts();
            break;
        case 3:
            consultes();
            break;
        default:
            cout << "Opcio no valida" << endl;
        }
        cout << "1. Gestio usuari" << endl;
        cout << "2. Gestio continguts" << endl;
        cout << "3. Consultes" << endl;
        cout << "4. Sortir" << endl;
        cout << "Escull una opcio: " << endl;
    }
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
