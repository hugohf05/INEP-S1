#include <string>
#include "PassarelaUsuari.h"
using namespace std;

PassarelaUsuari::PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU) {
	sobrenom = sobrenomU; // sobrenom atribut privat de la classe
	nom = nomU; // nom atribut privat de la classe
	correuElectronic = correuElectronicU; // correuElectronic atribut
}

string PassarelaUsuari::getSobrenom() const { return sobrenom; }
string PassarelaUsuari::getNom() const { return nom; }
string PassarelaUsuari::getCorreuElectronic() const { return correu_electronic; }

// Setters
void PassarelaUsuari::setSobrenom(const string& nouSobrenom) { sobrenom = nouSobrenom; }
void PassarelaUsuari::setNom(const string& nouNom) { nom = nouNom; }
void PassarelaUsuari::setCorreuElectronic(const string& nouCorreu) { correu_electronic = nouCorreu; }

// Operación para insertar un usuario
void PassarelaUsuari::insereix() {
    try {
        ConnexioBD& con = ConnexioBD::getInstance();
        string query = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" +
            sobrenom + "', '" + nom + "', '" + correu_electronic + "')";
        con.executar(query);
    }
    catch (sql::SQLException& e) {
        throw;
    }
}

// Operación para modificar un usuario
void PassarelaUsuari::modifica() {
    try {
        ConnexioBD& con = ConnexioBD::getInstance();
        string query = "UPDATE Usuari SET nom = '" + nom +
            "', correu_electronic = '" + correu_electronic +
            "' WHERE sobrenom = '" + sobrenom + "'";
        con.executar(query);
    }
    catch (sql::SQLException& e) {
        throw;
        //Preguntar
    }
}

// Operación para borrar un usuario
void PassarelaUsuari::esborra() {
    ConnexioBD& con = ConnexioBD::getInstance();
    string query = "DELETE FROM Usuari WHERE sobrenom = '" + sobrenom + "'";
    con.executar(query);
}