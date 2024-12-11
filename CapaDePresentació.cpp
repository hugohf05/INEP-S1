#include "CapaDePresentació.h"

    CapaDePresentacio(){}

    void registreUsuari(ConnexioBD& connexio) {
        string nom, sobrenom, correu;
        cout << "Nom: " << endl;
        cin >> nom;
        cout << "Sobrenom: " << endl;
        cin >> sobrenom;
        cout << "Correu Electronic: " << endl;
        cin >> correu;
        if (nom != "" and sobrenom != "" and correu != "") {
            try {
                string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES('" + sobrenom + "', '" + nom + "', '" + correu + "')";
                connexio.execSQL(sql);
                cout << "Usuari enregistrat correctament!" << endl;
            }
            catch (sql::SQLException& e) {
                std::cerr << "SQL Error: " << e.what() << std::endl;
            }
        }
        else {
            cout << "Error al registrar l'usuari." << endl;
        }
    }

    void consultaUsuari(ConnexioBD& connexio)
    {
        string sobrenom_usuari;
        cout << "Entra un sobrenom: ";
        cin >> sobrenom_usuari;
        try {
            string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";

            sql::ResultSet* res = connexio.consultaSQL(sql);
            // Bucle per recórrer les dades retornades mostrant les dades de cada fila
            while (res->next()) {
                // a la funció getString es fa servir el nom de la columna de la taula
                cout << "Sobrenom: " << res->getString("sobrenom") << endl;
                cout << "Nom: " << res->getString("nom") << endl;
                cout << "Correu: " << res->getString("correu_electronic") << endl;
            }
            if (!res->next()) { cout << "Usuari amb sobrenom " << sobrenom_usuari << " no trobat" << endl; }
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQL Error: " << e.what() << std::endl;
            // si hi ha un error es tanca la connexió (si esta oberta)
        }
    }

    void modificaUsuari(ConnexioBD& connexio) {
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
    }

    void esborraUsuari(ConnexioBD& connexio) {
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
    }