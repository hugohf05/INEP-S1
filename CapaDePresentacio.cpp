#include "CapaDePresentacio.h"

/*
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
        TxRegistraUsuari txRegistra(nom, sobrenom, contrasenya, correu, dataNaixement, modalitat);
        txRegistra.executar();
        cout << "Usuari registrat correctament!" << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

/*
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
*/
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
    string sobrenom, nom, correu;
    cout << "Entra un sobrenom: " << endl;
    cin >> sobrenom;
    if (sobrenom != "") {

        cout << "Entra el nou nom: " << endl;
        cin >> nom;
        cout << "Entra el nou correu electronic: " << endl;
        cin >> correu;

        try {
            string sql = "UPDATE Usuari SET nom = '" + nom + "', correu_electronic = '" + correu + "' WHERE sobrenom = '" + sobrenom + "'";
            //connexio.execSQL(sql);
        }
        catch (sql::SQLException& e) {
            cerr << "SQL Error: " << e.what() << endl;
            // si hi ha un error es tanca la connexió (si esta oberta)
        }
    }
    else {
        cout << "Error al consultar l'usuari." << endl;
    }
 
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
        TxEsborrarUsuari txeU(contrasenya);
        txeU.executar();
        cout << "Usuari esborrat correctament!" << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

//Menu Visualitzacio Continguts

//NO TOCAR, PERFECTO
void CapaDePresentacio::visualitzarPelicula() {
    string titolPelicula;

    cout << "** Visualitzar pelicula **" << endl;
    cout << "Introdueix el titol de la pelicula: ";
    cin.ignore();
    getline(cin, titolPelicula);

    try {
        // Transacció per obtenir la informació de la pel·lícula
        TxConsultaPelicula txConsulta(titolPelicula);
        txConsulta.executar();
        DTOPelicula pelicula = txConsulta.obteResultat();

        // Comprovar si la pel·lícula existeix
        if (pelicula.obteTitol().empty()) {
            cout << "La pelicula no existeix o no esta disponible." << endl;
            return;
        }

        // Mostrar informació de la pel·lícula
        cout << "\nInformacio de la pelicula:\n";
        cout << "Nom pelicula: " << pelicula.obteTitol() << "\n";
        cout << "Descripcio: " << pelicula.obteDescripcio() << "\n";
        cout << "Qualificacio edat: " << pelicula.obteQualificacio() << "\n";
        cout << "Data d'estrena: " << pelicula.obteDataEstrena() << "\n";
        cout << "Duracio: " << pelicula.obteDuracio() << " minuts\n";

        char resposta;
        cout << "\nVols visualitzar aquesta pelicula? (S/N): ";
        cin >> resposta;

        if (tolower(resposta) == 's') {
            // Transacció per registrar la visualització
            TxRegistreVisualitzacio txRegistre(titolPelicula);
            txRegistre.executar();
            cout << "La visualitzacio ha estat registrada correctament.\n";

            // Transacció per obtenir pel·lícules relacionades
            TxConsultaRelacionades txRelacionades(titolPelicula);
            txRelacionades.executar();
            auto relacionades = txRelacionades.obteResultat();

            if (!relacionades.empty()) {
                cout << "\nPelicules relacionades:\n";
                for (const auto& relacionada : relacionades) {
                    cout << " - " << relacionada.obteTitol() << " (" << relacionada.obteDataEstrena() << ")\n";
                    cout << "   Descripcio: " << relacionada.obteDescripcio() << "\n";
                    cout << "   Qualificacio: " << relacionada.obteQualificacio() << "\n";
                    cout << "   Duracio: " << relacionada.obteDuracio() << " minuts\n";
                }
            }
            else {
                cout << "No hi ha pelicules relacionades.\n";
            }
        }
        else {
            cout << "Visualitzacio cancel·lada.\n";
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}


//NO TOCAR, PERFECTO
void CapaDePresentacio::consultaProperesEstrenes() {
    string modalitat;
    PetitFlix& sistema = PetitFlix::getInstance();

    // Determina la modalitat en función de si hay usuario loggeado
    if (!sistema.estaUsuariLoggejat()) {
        cout << "** Consulta Properes Estrenes **" << endl;
        cout << "Introdueix la modalitat de subscripció: ";
        cin >> modalitat;
    }
    else {
        modalitat = sistema.obteModalitatUsuariLoggejat();
    }

    try {
        TxConsultaProperesEstrenes txConsulta(modalitat);
        txConsulta.executar();
        const auto& estrenes = txConsulta.obteResultat();

        if (estrenes.empty()) {
            cout << "No hi ha continguts per estrenar proximament." << endl;
        }
        else {
            cout << "Properes estrenes:" << endl;

            int i = 1;
            for (const auto& estrena : estrenes) {
                cout << i << ".- ";
                if (estrena->obteTipus() == "pelicula") {
                    auto pelicula = dynamic_cast<DTOPelicula*>(estrena.get());
                    cout << pelicula->obteDataEstrena() << " [Pelicula]: "
                        << pelicula->obteTitol() << "; "
                        << pelicula->obteQualificacio() << "; "
                        << pelicula->obteDuracio() << " min." << endl;
                }
                else if (estrena->obteTipus() == "serie") {
                    auto serie = dynamic_cast<DTOSerie*>(estrena.get());
                    cout << serie->obteDataEstrena() << " [Serie]: "
                        << serie->obteTitol() << "; "
                        << serie->obteQualificacio() << "; "
                        << serie->obteTotalCapitols() << " capitols." << endl;
                }
                ++i;
            }
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
