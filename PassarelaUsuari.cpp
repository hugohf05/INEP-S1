#include "PassarelaUsuari.h"
using namespace std;

PassarelaUsuari::PassarelaUsuari() {
    sobrenom = "";
    nom = "";
    correu_electronic = "";
    contrasenya = "";
    data_naixement = "";
    subscripcio = "";

}


PassarelaUsuari::PassarelaUsuari(const string& sobrenomU, const string& nomU,
    const string& correu_electronicU, const string& contrasenyaU,
    const string& data_naixementU, const string& subscricpioU) {

	sobrenom = sobrenomU; // sobrenom atribut privat de la classe
	nom = nomU; // nom atribut privat de la classe
    correu_electronic = correu_electronicU; // correuElectronic atribut
    contrasenya = contrasenyaU;
    data_naixement = data_naixementU;
    subscripcio = subscricpioU;
}

string PassarelaUsuari::getSobrenom() const { return sobrenom; }
string PassarelaUsuari::getNom() const { return nom; }
string PassarelaUsuari::getCorreuElectronic() const { return correu_electronic; }
string PassarelaUsuari::getContrasenya() const { return contrasenya; }
string PassarelaUsuari::getDataNaixement() const { return data_naixement; }
string PassarelaUsuari::getSubscricpio() const { return subscripcio; }


// Setters
void PassarelaUsuari::setSobrenom(const string& nouSobrenom) { sobrenom = nouSobrenom; }
void PassarelaUsuari::setNom(const string& nouNom) { nom = nouNom; }
void PassarelaUsuari::setCorreuElectronic(const string& nouCorreu) { correu_electronic = nouCorreu; }
void PassarelaUsuari::setContrasenya(const string& nouContrasenya) { contrasenya = nouContrasenya; }
void PassarelaUsuari::setDataNaixement(const string& nouDataNaixement) { data_naixement = nouDataNaixement; }
void PassarelaUsuari::setSubscripcio(const string& nouSubscripcio) { subscripcio = nouSubscripcio; }


// Operación para insertar un usuario
void PassarelaUsuari::insereix() {
    try {
        ConnexioBD& con = *ConnexioBD::getInstance();
        string query = "INSERT INTO usuari (sobrenom, nom, contrasenya, correu_electronic, "
            "data_naixement, subscripcio) VALUES ('" +
            sobrenom + "', '" + nom + "', '" + contrasenya + "', '" +
            correu_electronic + "', '" + data_naixement + "', '" + subscripcio + "');";
        con.execSQL(query);
    }
    catch (sql::SQLException& e) {
        throw;
    }
}

// Operación para modificar un usuario
void PassarelaUsuari::modifica() {
    try {
        ConnexioBD& con = *ConnexioBD::getInstance();
        string query = "UPDATE Usuari SET nom = '" + nom +
            "', correu_electronic = '" + correu_electronic +
            "' WHERE sobrenom = '" + sobrenom + "'";
        con.execSQL(query);
    }
    catch (sql::SQLException& e) {
        throw;
        //Preguntar
    }
}

// Operación para borrar un usuario
void PassarelaUsuari::esborra() {
    try {
        ConnexioBD& con = *ConnexioBD::getInstance();
        string query = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom + "';";
        con.execSQL(query);
        cout << "Usuari '" << sobrenom << "' esborrat correctament." << endl;
    }
    catch (const sql::SQLException& e) {
        throw runtime_error("Error al esborrar l'usuari: " + string(e.what()));
    }
}
