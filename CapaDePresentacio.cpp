#include "CapaDePresentacio.h"
using namespace std;

void CapaDePresentacio::registreUsuari() {
    string nom, sobrenom, correu;
    cout << "Nom: " << endl;
    cin >> nom;
    cout << "Sobrenom: " << endl;
    cin >> sobrenom;
    cout << "Correu Electronic: " << endl;
    cin >> correu;

    CapaDeDomini& domini = CapaDeDomini::getInstance();

    if (nom != "" and sobrenom != "" and correu != "") {
        try {
            domini.registreUsuari(nom, sobrenom, correu);
            cout << "Usuari enregistrat correctament!" << endl;
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << std::endl;
        }
    }
    else {
        cout << "Error al registrar l'usuari." << endl;
    }
}

void CapaDePresentacio::consultaUsuari(){
    string sobrenom_usuari;
    cout << "Entra un sobrenom: ";
    cin >> sobrenom_usuari;

    CapaDeDomini& domini = CapaDeDomini::getInstance();

    try {
        DTOUsuari usu = domini.consultaUsuari(sobrenom_usuari);
        cout << "Informació usuari: " << usu.obteNom() << endl;
        cout << "Nom: " << usu.obteNom() << endl;
        cout << "Correu: " << usu.obteCorreu() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void CapaDePresentacio::modificaUsuari() {
    /*string sobrenom, nom, correu;
    cout << "Entra un sobrenom: " << endl;
    cin >> sobrenom;
    if (sobrenom != "") {

        cout << "Entra el nou nom: " << endl;
        cin >> nom;
        cout << "Entra el nou correu electronic: " << endl;
        cin >> correu;

        try {
            string sql = "UPDATE Usuari SET nom = '" + nom + "', correu_electronic = '" + correu + "' WHERE sobrenom = '" + sobrenom + "'";
            connexio.execSQL(sql);
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Error: " << e.what() << std::endl;
            // si hi ha un error es tanca la connexió (si esta oberta)
        }
    }
    else {
        cout << "Error al consultar l'usuari." << endl;
    }
    */
}

void CapaDePresentacio::esborraUsuari() {
    /*
    string sobrenom;
    cout << "Entra un sobrenom: " << endl;
    cin >> sobrenom;
    if (sobrenom != "") {
        try {
            string sql = "DELETE FROM Usuari WHERE sobrenom = '" + sobrenom + "'";
            connexio.execSQL(sql);
            cout << "S'ha esborrat l'usuari amb sobrenom: " + sobrenom << endl;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Error: " << e.what() << std::endl;
            // si hi ha un error es tanca la connexió (si esta oberta)
        }
    }
    else {
        cout << "Error al consultar l'usuari." << endl;
    }
    */
}