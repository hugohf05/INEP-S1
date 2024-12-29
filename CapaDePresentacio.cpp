#include "CapaDePresentacio.h"
#include "CercadoraContingut.h"

void CapaDePresentacio::iniciarSessio() {
    string sobrenom, contrasenya;

    cout << "** Inici Sessio **" << endl;
    cout << "Sobrenom:";
    cin >> sobrenom;
    contrasenya = llegirContrasenya();

    try {
        TxIniciSessio txI(sobrenom, contrasenya);
        txI.executar();
        cout << "Sessio iniciada correctament!" << endl;
    }
    catch (const exception& e) {
        cout << "Error: No s'han pogut verificar les credencials." << endl;
    }
}

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


void CapaDePresentacio::tancarSessio() {
    char opcio;
    cout << "** Tancar sessio **" << endl;
    cout << "Vols tancar la sessio (S/N): ";
    cin >> opcio;

    if (opcio == 'S' || opcio == 's') {
        TxTancaSessio txC;
        txC.executar();
        cout << "Sessio tancada correctament!" << endl;
    }
    else if (opcio == 'N' || opcio == 'n') {
        cout << "La sessio no s'ha tancat." << endl;
    }
    else {
        cout << "Opció no vàlida. La sessio no s'ha tancat." << endl;
    }
}
/*
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
*/
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
string CapaDePresentacio::llegirContrasenya() {
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
        TxTancaSessio txC;
        txC.executar();
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
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        char fechaActual[11]; // YYYY-MM-DD
        strftime(fechaActual, sizeof(fechaActual), "%Y-%m-%d", now);
        if (pelicula.obteDataEstrena() > fechaActual) {
            cout << "La pel·lícula no ha sigut estrenada." << endl;
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
            vector<DTOPelicula> relacionades = txRelacionades.obteResultat();

            if (!relacionades.empty()) {
                cout << "\nPelicules relacionades:\n";
                for (DTOPelicula relacionada : relacionades) {
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

void CapaDePresentacio::visualitzarCapitol() {
    string titolSerie;

    cout << "** Visualitzar Capítol **" << endl;
    cout << "Nom de la sèrie: ";
    cin.ignore();
    getline(cin, titolSerie);

    try {
        //Transacció per obtenir la informació de la sèrie
        TxConsultaSerie txConsulta(titolSerie);
        txConsulta.executar();
        DTOSerie serie = txConsulta.obteResultat();

        //Comprovar si la sèrie existeix
        if (serie.obteTitol().empty()) {
            cout << "La sèrie no existeix o no està disponible." << endl;
            return;
        }

        //Transacció per obtenir el número de temporades de la sèrie
        TxConsultaTemporades txConsultaT(titolSerie);
        txConsultaT.executar();
        int temporades = txConsultaT.obteResultat();

        cout << "La sèrie té " << temporades << " temporades." << endl;
        cout << "Escull temporada: ";
        int temporada;
        cin >> temporada;
        //Comprovar si el número de la temporada introduït es vàlid
        if (temporada <= 0 || temporada > temporades) {
            cout << "La temporada seleccionada no existeix." << endl;
            return;
        }

        //Transacció per obtenir el número de capítols de la temporada seleccionada
        TxConsultaCapitols txConsultaC(titolSerie, temporada);
        txConsultaC.executar();
        const auto& capitols = txConsultaC.obteResultat();

        //Comprovar si hi han capitols a la temporada seleccionada
        if (capitols.empty()) {
            cout << "No s'han trobat capítols per a la temporada seleccionada." << endl;
        }

        //Mostrar la informació dels capítols
        for (auto it = capitols.rbegin(); it != capitols.rend(); ++it) {
            const auto& capitol = *it;
            cout << capitol.obteNumeroCapitol() << ". ";
            cout << capitol.obteTitolCapitol() << "; ";
            cout << capitol.obteDataEstrena() << "; ";

            //Transacció per obtenir si un capítol ja ha estat visualitzat per l'usuari
            TxConsultaVisualitzacioCapitol txConsulta(titolSerie, temporada, capitol.obteNumeroCapitol());
            txConsulta.executar();
            string estatVisualitzacio = txConsulta.obteResultat();

            if (estatVisualitzacio != "no visualitzat") {
                cout << "Visualitzat el " << estatVisualitzacio << endl;
            }
            else {
                cout << "No visualitzat" << endl;
            }
        }

        cout << "Número de capítol a visualitzar: ";
        int numCapitol;
        cin >> numCapitol;

        //Obtenir la data d'estrena del capítol seleccionat
        auto it = std::find_if(capitols.begin(), capitols.end(),
            [numCapitol](const auto& capitol) {
                return capitol.obteNumeroCapitol() == numCapitol;
            });

        if (it == capitols.end()) {
            cout << "El número de capítol seleccionat no és vàlid." << endl;
            return;
        }

        const auto& capitolSeleccionat = *it;
        string dataEstrena = capitolSeleccionat.obteDataEstrena();

        //Obtenir la data actual
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        char fechaActual[11]; // YYYY-MM-DD
        strftime(fechaActual, sizeof(fechaActual), "%Y-%m-%d", now);

        //Comprovar si el capitol ja ha estat estrenat
        if (dataEstrena > fechaActual) {
            cout << "El capítol seleccionat encara no ha estat estrenat." << endl;
            return;
        }

        char resposta;
        cout << "Vols continuar amb la visualització (S/N): ";
        cin >> resposta;

        if (tolower(resposta) == 's') {
            // Transacció per registrar la visualització
            TxRegistreVisualitzacioCapitol txRegistre(titolSerie, temporada, numCapitol);
            txRegistre.executar();
            cout << "La visualització s'ha registrat correctament" << endl;
        }
        else {
            cout << "Visualització cancel·lada.\n";
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
            for (const unique_ptr<DTOContingut>& estrena : estrenes) {
                cout << i << ".- ";
                if (estrena->obteTipus() == "pelicula") {
                    DTOPelicula* pelicula = dynamic_cast<DTOPelicula*>(estrena.get());
                    cout << pelicula->obteDataEstrena() << " [Pelicula]: "
                        << pelicula->obteTitol() << "; "
                        << pelicula->obteQualificacio() << "; "
                        << pelicula->obteDuracio() << " min." << endl;
                }
                else if (estrena->obteTipus() == "serie") {
                    DTOSerie* serie = dynamic_cast<DTOSerie*>(estrena.get());
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

void CapaDePresentacio::consultaUltimesNovetats() {
    string modalitat;
    PetitFlix& sistema = PetitFlix::getInstance();

    //Comprovar si hi ha un usuari loggejat
    if (!sistema.estaUsuariLoggejat()) {
        cout << "** Consulta Properes Estrenes **" << endl;
        cout << "Introdueix la modalitat de subscripció: ";
        cin >> modalitat;
    }
    else {
        modalitat = sistema.obteModalitatUsuariLoggejat();
    }

    try {
        TxConsultaUltimesNovetats txConsulta(modalitat);
        txConsulta.executar();

        const auto& novetatsContingut = txConsulta.obteResultatContingut();

        // Mostrar informació de les pel·lícules
        cout << "** Novetats pel·lícules **" << endl;
        cout << "********************************" << endl;
        int i = 1;
        for (const auto& novetat : novetatsContingut) {
            if (auto pelicula = dynamic_cast<DTOPelicula*>(novetat.get())) {
                cout << i << ".- ";
                cout << pelicula->obteDataEstrena() << ": "
                    << pelicula->obteTitol() << "; "
                    << pelicula->obteQualificacio() << "; "
                    << pelicula->obteDuracio() << " min." << endl;
                ++i;
            }
        }

        // Mostrar informació de les sèries
        cout << "** Novetats sèries **" << endl;
        cout << "********************************" << endl;
        i = 1;
        for (const auto& novetat : novetatsContingut) {
            if (auto serie = dynamic_cast<DTOSerie*>(novetat.get())) {
                cout << i << ".- ";
                cout << serie->obteDataEstrena() << ": " << serie->obteTitol() << "; " << serie->obteQualificacio();
                TxConsultaNovetatsSerie consulta(serie->obteTitol());
                consulta.executar();
                int ultimaTemporada = consulta.obteResultatTemporada();
                auto ultimCapitol = consulta.obteResultatCapitol();
                cout << "; Temporada: " << ultimaTemporada << "; Capítol: " << ultimCapitol.obteNumeroCapitol() << endl;
                ++i;
            }
        }

    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}