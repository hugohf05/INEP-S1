#include "CapaDePresentacio.h"

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
    cout << "Data de naixement (AAAA/MM/DD): ";
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
    catch (const std::exception& e) {
        // Comprovar si el missatge d'error conte errors coneguts
        std::string errorMsg = e.what();
        if (errorMsg.find("Duplicate entry") != std::string::npos) {
            cerr << "Error: El correu electronic ja existeix. Si us plau, utilitza un altre correu." << endl;
        }
        else {
            cerr << "Error durant el registre de l'usuari: " << errorMsg << endl;
        }
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
        cout << "Opcio no valida. La sessio no s'ha tancat." << endl;
    }
}
void CapaDePresentacio::modificaUsuari() {
    try {
        CtrlModificaUsuari modificaU;
        vector<string> infoU;
        infoU = modificaU.consultaUsuari();
        string nomU = "";
        string contraU = "";
        string correuU = "";
        string neixU = "";
        string subU = "";

        cout << "** Modifica usuari **" << endl;
        cout << "Nom complet: " << infoU[2] << endl;
        cout << "Sobrenom: " << infoU[0] << endl;
        cout << "Correu electronic: " << infoU[3] << endl;
        cout << "Data de naixament (AAAA/MM/DD): " << infoU[4] << endl << endl;
        cout << "Modalitat subscripcio: " << infoU[5] << endl;

        cout << "Omplir la informacio que es vol modificar..." << endl;
        cout << "Nom complet: " << endl;
        cin.ignore();
        getline(cin, nomU);
        cout << "Contrasenya: " << endl;
        cin >> contraU;
        cout << "Correu electronic: " << endl;
        cin >> correuU;
        cout << "Data de naixament (AAAA/MM/DD): " << endl;
        cin >> neixU;
        cout << "Modalitat subscripcio: " << endl;
        cin >> subU;

        // Intentar modificar l'usuari
        modificaU.modificaUsuari(nomU, contraU, correuU, neixU, subU);

        // Consultar la informacio modificada
        infoU = modificaU.consultaUsuari();
        cout << endl << "** Dades usuari modificades **" << endl;
        cout << "Nom complet: " << infoU[2] << endl;
        cout << "Sobrenom: " << infoU[0] << endl;
        cout << "Correu electronic: " << infoU[3] << endl;
        cout << "Data de naixament (AAAA/MM/DD): " << infoU[4] << endl;
        cout << "Modalitat subscripcio: " << infoU[5] << endl;
    }
    catch (const std::exception& e) {
        // Comprovar si el missatge d'error conte errors coneguts
        std::string errorMsg = e.what();
        if (errorMsg.find("Duplicate entry") != std::string::npos) {
            cerr << "Error: El correu electronic ja existeix. Si us plau, utilitza un altre correu." << endl;
        }
        else if (errorMsg.find("foreign key constraint fails") != std::string::npos) {
            cerr << "Error: La subscripcio especificada no existeix. Si us plau, selecciona una subscripcio valida." << endl;
        }
        else if (errorMsg.find("time") != std::string::npos) {
            cerr << "Error: Format de data no correcte" << endl;
        }
        else {
            cerr << "Error durant la modificacio de l'usuari: " << errorMsg << endl;
        }
    }
    catch (...) {
        // Capturar altres errors no especificats
        cerr << "S'ha produit un error desconegut durant la modificacio." << endl;
    }
}



void CapaDePresentacio::consultaUsuari() {
    try {

        // Crear y ejecutar TxConsultaUsuari.
        TxConsultaUsuari txConsulta;
        txConsulta.executar();
        vector<string> usuari(5, "");
        usuari = txConsulta.obteResultat();

        cout << "** Consulta usuari **" << endl;
        cout << "Nom complet: " << usuari[2] << endl;
        cout << "Sobrenom: " << usuari[0] << endl;
        cout << "Correu electronic: " << usuari[3] << endl;
        cout << "Data de naixament (AAAA/MM/DD): " << usuari[4] << endl;
        cout << "Modalitat subscripcio: " << usuari[5] << endl;

        // Crear y ejecutar TxInfoVisualitzacions.
        TxInfoVisualitzacions txInfo;
        txInfo.executar();
        pair<int, int> visualitzacions; //first: pelicules, second = capitols
        visualitzacions = txInfo.obteResultat();

        cout << endl;
        cout << visualitzacions.first << " pelicules visualitzades" << endl;
        cout << visualitzacions.second << " capitols visualitzats" << endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
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
            cout << "\b \b"; // Borra el caracter en pantalla
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
    cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ...: " << endl;
    contrasenya = llegirContrasenya();

    try {
        TxEsborrarUsuari txeU(contrasenya);
        txeU.executar();
        cout << "Usuari esborrat correctament!" << endl;
        TxTancaSessio txC;
        txC.executar();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
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
        // Transaccio per obtenir la informacio de la pelicula
        TxConsultaPelicula txConsulta(titolPelicula);
        txConsulta.executar();
        DTOPelicula pelicula = txConsulta.obteResultat();

        // Comprovar si la pelicula existeix
        if (pelicula.obteTitol().empty()) {
            cout << "La pelicula no existeix o no esta disponible." << endl;
            return;
        }
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        char fechaActual[11]; // YYYY-MM-DD
        strftime(fechaActual, sizeof(fechaActual), "%Y-%m-%d", now);
        if (pelicula.obteDataEstrena() > fechaActual) {
            cout << "La pelicula no ha sigut estrenada." << endl;
            return;
        }

        // Mostrar informacio de la pelicula
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
            // Transaccio per registrar la visualitzacio
            TxRegistreVisualitzacio txRegistre(titolPelicula);
            txRegistre.executar();
            cout << "La visualitzacio ha estat registrada correctament.\n";

            // Transaccio per obtenir pelicules relacionades
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
            cout << "Visualitzacio cancelada.\n";
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

void CapaDePresentacio::visualitzarCapitol() {
    string titolSerie;

    cout << "** Visualitzar Capitol **" << endl;
    cout << "Nom de la serie: ";
    cin.ignore();
    getline(cin, titolSerie);

    try {
        //Transaccio per obtenir la informacio de la serie
        TxConsultaSerie txConsulta(titolSerie);
        txConsulta.executar();
        DTOSerie serie = txConsulta.obteResultat();

        //Comprovar si la serie existeix
        if (serie.obteTitol().empty()) {
            cout << "La serie no existeix o no esta disponible." << endl;
            return;
        }

        //Transaccio per obtenir el numero de temporades de la serie
        TxConsultaTemporades txConsultaT(titolSerie);
        txConsultaT.executar();
        int temporades = txConsultaT.obteResultat();

        cout << "La serie te " << temporades << " temporades." << endl;
        cout << "Escull temporada: ";
        int temporada;
        cin >> temporada;
        //Comprovar si el numero de la temporada introduït es valid
        if (temporada <= 0 || temporada > temporades) {
            cout << "La temporada seleccionada no existeix." << endl;
            return;
        }

        //Transaccio per obtenir el numero de capitols de la temporada seleccionada
        TxConsultaCapitols txConsultaC(titolSerie, temporada);
        txConsultaC.executar();
        const auto& capitols = txConsultaC.obteResultat();

        //Comprovar si hi han capitols a la temporada seleccionada
        if (capitols.empty()) {
            cout << "No s'han trobat capitols per a la temporada seleccionada." << endl;
        }

        //Mostrar la informacio dels capitols
        for (auto it = capitols.rbegin(); it != capitols.rend(); ++it) {
            const auto& capitol = *it;
            cout << capitol.obteNumeroCapitol() << ". ";
            cout << capitol.obteTitolCapitol() << "; ";
            cout << capitol.obteDataEstrena() << "; ";

            //Transaccio per obtenir si un capitol ja ha estat visualitzat per l'usuari
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

        cout << "Numero de capitol a visualitzar: ";
        int numCapitol;
        cin >> numCapitol;

        //Obtenir la data d'estrena del capitol seleccionat
        auto it = std::find_if(capitols.begin(), capitols.end(),
            [numCapitol](const auto& capitol) {
                return capitol.obteNumeroCapitol() == numCapitol;
            });

        if (it == capitols.end()) {
            cout << "El numero de capitol seleccionat no es valid." << endl;
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
            cout << "El capitol seleccionat encara no ha estat estrenat." << endl;
            return;
        }

        char resposta;
        cout << "Vols continuar amb la visualitzacio (S/N): ";
        cin >> resposta;

        if (tolower(resposta) == 's') {
            // Transaccio per registrar la visualitzacio
            TxRegistreVisualitzacioCapitol txRegistre(titolSerie, temporada, numCapitol);
            txRegistre.executar();
            cout << "La visualitzacio s'ha registrat correctament" << endl;
        }
        else {
            cout << "Visualitzacio cancelada.\n";
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

void CapaDePresentacio::consultarVisualitzacions() {
    try {
        PetitFlix& sistema = PetitFlix::getInstance();
        if (!sistema.estaUsuariLoggejat()) {
            throw std::runtime_error("Error: No hi ha cap usuari loggejat.");
        }
        string sobrenomUsuari = sistema.obtenirUsuariLoggejat()->getSobrenom();

        TxConsultarVisualitzacionsPelicules txPelicules(sobrenomUsuari);
        txPelicules.executar();
        vector<DTOVisualitzacioPelicula> pelicules = txPelicules.obteResultat();

        TxConsultarVisualitzacionsCapitols txCapitols(sobrenomUsuari);
        txCapitols.executar();
        vector<DTOVisualitzacioCapitol> capitols = txCapitols.obteResultat();

        // Mostrar resultados de películas.
        std::cout << "** Visualitzacions pelicules **" << std::endl;
        std::cout << "***********************************" << std::endl;
        for (const auto& pelicula : pelicules) {
            std::cout << "Data: " << pelicula.obteData();
            std::cout << "; Titol: " << pelicula.obteTitolPelicula();
            std::cout << "; Visualitzacions: " << pelicula.obteNumVisualitzacions();
            std::cout << "; Qualificacio: " << pelicula.obteQualificacio();
            std::cout << "; Descripcio: " << pelicula.obteDescripcio() << std::endl;
        }
        cout << endl;

        // Mostrar resultados de capítulos.
        std::cout << "** Visualitzacions series **" << std::endl;
        std::cout << "***********************************" << std::endl;
        for (const auto& capitol : capitols) {
            std::cout << "Data: " << capitol.obteDataVisualitzacio();
            std::cout << "; Serie: " << capitol.obteTitolSerie();
            std::cout << "; Qualificacio: " << capitol.obteQualificacio();
            std::cout << "; Temporada: " << capitol.obteNumTemporada();
            std::cout << "; Capitol: " << capitol.obteNumCapitol();
            std::cout << "; Visualitzacions: " << capitol.obteNumVisualitzacions() << std::endl;
        }
        cout << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << std::endl;
    }
}

//NO TOCAR, PERFECTO
void CapaDePresentacio::consultaProperesEstrenes() {
    string modalitat;
    PetitFlix& sistema = PetitFlix::getInstance();

    // Determina la modalitat en funcion de si hay usuario loggeado
    if (!sistema.estaUsuariLoggejat()) {
        cout << "** Consulta Properes Estrenes **" << endl;
        cout << "Introdueix la modalitat de subscripcio: ";
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
        cout << "Introdueix la modalitat de subscripcio: ";
        cin >> modalitat;
    }
    else {
        modalitat = sistema.obteModalitatUsuariLoggejat();
    }

    try {
        TxConsultaUltimesNovetats txConsulta(modalitat);
        txConsulta.executar();

        const auto& novetatsContingut = txConsulta.obteResultatContingut();

        // Mostrar informacio de les pelicules
        cout << "** Novetats pelicules **" << endl;
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

        // Mostrar informacio de les series
        cout << "** Novetats series **" << endl;
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
                cout << "; Temporada: " << ultimaTemporada << "; Capitol: " << ultimCapitol.obteNumeroCapitol() << endl;
                ++i;
            }
        }

    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void CapaDePresentacio::consultarPeliculesMesVistes() {
    try {
        // 1. Obtener el controlador.
        CtrlConsultarPeliculesMesVistes ctrlPelVistes;

        // 2. Realizar la consulta.
        std::vector<DTOVisualitzacioPelicula> pelicules = ctrlPelVistes.consulta();

        // 3. Obtener el usuario logueado, si lo hay.
        PetitFlix& sistema = PetitFlix::getInstance();
        PassarelaUsuari* usuariLoggejat = nullptr;
        if (sistema.estaUsuariLoggejat()) {
            usuariLoggejat = sistema.obtenirUsuariLoggejat();
        }

        // 4. Mostrar la lista de peliculas.
        std::cout << "** Pelicules mes visualitzades **" << std::endl;
        int index = 1;
        for (DTOVisualitzacioPelicula& pelicula : pelicules) {
            std::cout << index << ".- " << pelicula.obteTitolPelicula();
            std::cout << "; " << pelicula.obteQualificacio(); // poner el '+' ?
            std::cout << "; " << pelicula.obteDuracio() << " min.";
            std::cout << "; Visualitzacions: " << pelicula.obteNumVisualitzacions();

            // Mostrar la fecha de visualizacion del usuario logueado, si aplica.
            if (usuariLoggejat != nullptr && pelicula.obteSobrenomUsuari() == usuariLoggejat->getSobrenom()) {
                std::cout << " [VISTA: " << pelicula.obteData() << "]";
            }
            std::cout << std::endl;

            ++index;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
