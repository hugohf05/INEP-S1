#include "CapaDePresentacio.h"
using namespace std;

void CapaDePresentacio::iniciarSessio() {
    string sobrenom, contrasenya;

    cout << "** Inici Sessio **" << endl;
    cout << "Sobrenom:" << endl;
    cin >> sobrenom;
    cout << "Contrasenya:" << endl;
    cin >> contrasenya;

    CapaDeDomini& domini = CapaDeDomini::getInstance();

    try {
        if (domini.verificaDadesInici(sobrenom, contrasenya)) {
            //Falta hacer el metodo en la capa de domini
            cout << "Sessio iniciada correctament." << endl;
        }
        else {
            throw runtime_error("Credencials incorrectes.");
        }
    }
    catch (const exception& e) {
        cout << "Error: No s'han pogut verificar les credencials." << endl;
    }
}

void CapaDePresentacio::registreUsuari() {
    string nom, sobrenom, contrasenya, correu;
    string dataNaixement, modalitat;

    cout << "** Registrar Usuari **" << endl;
    cout << "Nom complet: ";
    getline(cin, nom);
    cout << "Sobrenom: ";
    getline(cin, sobrenom);
    cout << "Contrasenya: ";
    getline(cin, contrasenya);
    cout << "Correu electrònic: ";
    getline(cin, correu);
    cout << "Data de naixement (YYYY-MM-DD): ";
    getline(cin, dataNaixement);
    cout << "Modalitats de subscripcio disponibles: " << endl;
    cout << "   < 1. Completa" << endl;
    cout << "   < 2. Cinefil" << endl;
    cout << "   < 3. Infantil" << endl;
    cout << "Escull modalitat: ";
    int mod;
    cin >> mod;
    modalitat = (mod == 1) ? "Completa" : ((mod == 2) ? "Cinefil" : "Infantil");

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.registreUsuari(sobrenom, nom, correu, contrasenya, dataNaixement, modalitat);
        cout << "Usuari registrat correctament!" << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void CapaDePresentacio::tancarSessio() {
    char opcio;
    cout << "** Tancar sessio **" << endl;
    cout << "Vols tancar la sessio (S/N): ";
    cin >> opcio;

    if (opcio == 'S' || opcio == 's') {
        cout << "Sessio tancada correctament!" << endl;
        //Falta manejar el cierre de sesion
    }
    else if (opcio == 'N' || opcio == 'n') {
        cout << "La sessio no s'ha tancat." << endl;
    }
    else {
        cout << "Opció no vàlida. La sessio no s'ha tancat." << endl;
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
    string contrasenya;

    cout << "** Esborrar Usuari **" << endl;
    cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasentya ...: " << endl;
    cout << "Contrasenya: ";
    getline(cin, contrasenya);

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.esborraUsuari(contrasenya);
        cout << "Usuari esborrat correctament!" << endl;
    }
    catch (const exception& e) {
        std::cout << "Error: " << e.what() << endl;
    }
}
