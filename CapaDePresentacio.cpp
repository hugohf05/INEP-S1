#include "CapaDePresentacio.h"
using namespace std;

/*void CapaDePresentacio::iniciarSessio() {
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
*/

void CapaDePresentacio::registreUsuari() {
    string nom, sobrenom, contrasenya, correu;
    string dataNaixement, modalitat;

    cout << "** Registrar Usuari **" << endl;
    cout << "Nom: ";
    cin >> nom;
    cout << endl;
    cout << "Sobrenom: ";
    cin >> sobrenom;
    cout << endl;
    cout << "Contrasenya: ";
    cin >> contrasenya;
    cout << endl;
    cout << "Correu electrònic: ";
    cin >> correu;
    cout << endl;
    cout << "Data de naixement (YYYY-MM-DD): ";
    cin >> dataNaixement;
    cout << endl;
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
            cerr << "SQL Error: " << e.what() << endl;
            // si hi ha un error es tanca la connexió (si esta oberta)
        }
    }
    else {
        cout << "Error al consultar l'usuari." << endl;
    }
    */
}
//Funcion para satisfacer RIT: No mostrar contrasenya
string llegirContrasenya() {
    string contrasenya;
    char ch;

    cout << "Contrasenya: ";

    while ((ch = _getch()) != '\r') { // '\r' indica Enter
        if (ch == '\b' && !contrasenya.empty()) { // Manejo del retroceso
            contrasenya.pop_back();
            cout << "\b \b"; // Borra el carácter en pantalla
        }
        else if (ch != '\b') {
            contrasenya += ch;
            cout << '*'; // Muestra un asterisco
        }
    }
    cout << endl;

    return contrasenya;
}

void CapaDePresentacio::esborraUsuari() {
    string contrasenya;

    cout << "** Esborrar Usuari **" << endl;
    cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasentya ...: " << endl;
    contrasenya = llegirContrasenya();

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.esborraUsuari(contrasenya);
        cout << "Usuari esborrat correctament!" << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}


//Menu Visualitzacio Continguts
void CapaDePresentacio::visualitzarPelicula() {
    string titolPelicula;
    cout << "Introdueix el títol de la pel·lícula: ";
    cin.ignore();
    getline(cin, titolPelicula);

    try {
        DTOPelicula pelicula = CapaDeDomini::getInstance().consultaPelicula(titolPelicula);

        cout << "\nInformació de la pel·lícula:\n";
        cout << "Nom pel·lícula : " << pelicula.getTitol() << "\n";
        cout << "Descripció: " << pelicula.getDescripcio() << "\n";
        cout << "Qualificació edat: " << pelicula.getQualificacio() << "\n";
        cout << "Data d'estrena: " << pelicula.getDataEstrena() << "\n";
        cout << "Duració: " << pelicula.getDuracio() << " minuts\n";

        char resposta;
        cout << "\nVols visualitzar aquesta pel·lícula? (S/N): ";
        cin >> resposta;

        if (resposta == 'S' || resposta == 's') {
            CapaDeDomini::getInstance().registreVisualitzacio(titolPelicula);
            cout << "La visualització ha estat registrada correctament.\n";
            vector<DTOPelicula> relacionades = CapaDeDomini::getInstance().consultaRelacionades(titolPelicula);
            if (!relacionades.empty()) {
                cout << "\nPel·lícules relacionades:\n";
                for (DTOPelicula peli : relacionades) {
                    cout << " - " << peli.getTitol() << " (" << peli.getDataEstrena() << ")\n";
                    cout << "   Descripció: " << peli.getDescripcio() << "\n";
                    cout << "   Qualificació: " << peli.getQualificacio() << "\n";
                    cout << "   Duració: " << peli.getDuracio() << " minuts\n";
                }
            }
            else {
                cout << "No hi ha pel·lícules relacionades.\n";
            }
        }
        else {
            cout << "Visualització cancel·lada.\n";
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}
