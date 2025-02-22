#include "CapaDePresentacio.h"
#include "PetitFlix.h"
#include <iostream>
#include <limits>

void iniciarSessio(CapaDePresentacio& presentacio) {
    presentacio.iniciarSessio();
}

void registreUsuari(CapaDePresentacio& presentacio) {
    presentacio.registreUsuari();
}

void GestioUsuari(CapaDePresentacio& presentacio) {
    PetitFlix& sistema = PetitFlix::getInstance();
    int op;
    do {
        cout << "--------------------" << endl;
        cout << "   Gestio Usuari   " << endl;
        cout << "--------------------" << endl;
        cout << "1. Consulta usuari" << endl;
        cout << "2. Modifica usuari" << endl;
        cout << "3. Esborra usuari" << endl;
        cout << "4. Tornar" << endl;
        cout << "Escull una opcio: ";
        cin >> op;

        switch (op) {
        case 1:
            presentacio.consultaUsuari();
            break;
        case 2:
            presentacio.modificaUsuari();
            break;
        case 3:
            presentacio.esborraUsuari();
            break;
        case 4:
            // Tornar al menu principal
            return;
        default:
            cout << "Opcio no valida." << endl;
            break;
        }
    } while (op != 5 && sistema.estaUsuariLoggejat());
}

void Visualitzar(CapaDePresentacio& presentacio) {
    int op;
    do {
        cout << "--------------------" << endl;
        cout << "     Visualitzar   " << endl;
        cout << "--------------------" << endl;
        cout << "1. Visualitzar pelicula" << endl;
        cout << "2. Visualitzar capitol" << endl;
        cout << "3. Consulta visualitzacions" << endl;
        cout << "4. Tornar" << endl;
        cout << "Escull una opcio: ";
        cin >> op;

        switch (op) {
        case 1:
            presentacio.visualitzarPelicula();
            break;
        case 2:
            presentacio.visualitzarCapitol();
            break;
        case 3:
            presentacio.consultarVisualitzacions();
            break;
        case 4:
            // Tornar al menu principal
            return;
        default:
            cout << "Opcio no valida." << endl;
            break;
        }
    } while (op != 4);
}

void Consultes(CapaDePresentacio& presentacio) {
    int op;
    do {
        cout << "--------------------" << endl;
        cout << "   Consultes   " << endl;
        cout << "--------------------" << endl;
        cout << "1. Properes estrenes" << endl;
        cout << "2. Ultimes novetats" << endl;
        cout << "3. Pelicules mes vistes" << endl;
        cout << "4. Tornar" << endl;
        cout << "Escull una opcio: ";
        cin >> op;

        switch (op) {
        case 1:
            presentacio.consultaProperesEstrenes();
            break;
        case 2:
            presentacio.consultaUltimesNovetats();
            break;
        case 3:
            presentacio.consultarPeliculesMesVistes();
            break;
        case 4:
            // Tornar al menu principal
            return;
        default:
            cout << "Opcio no valida." << endl;
            break;
        }
    } while (op != 4);
}

void tancarSessio(CapaDePresentacio& presentacio) {
    presentacio.tancarSessio();
}

int main() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    PetitFlix& sistema = PetitFlix::getInstance();
    int opt;

    while (true) {
        cout << "********************" << endl;
        cout << "   Menu Principal   " << endl;
        cout << "********************" << endl;

        if (!sistema.estaUsuariLoggejat()) {
            cout << "1. Iniciar sessio" << endl;
            cout << "2. Registrar Usuari" << endl;
            cout << "3. Consultes" << endl;
            cout << "4. Sortir " << endl;
        }
        else {
            cout << "1. Gestio usuaris" << endl;
            cout << "2. Visualitzar" << endl;
            cout << "3. Consultes" << endl;
            cout << "4. Tancar sessio" << endl;
            cout << "5. Sortir" << endl;
        }

        cout << "Escull una opcio: ";
        cin >> opt;

        // Manejo de entrada invalida
        if (cin.fail()) {
            cout << "Entrada no valida. Introdueix un numero." << endl;
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada invalida
            continue;
        }

        if (!sistema.estaUsuariLoggejat()) {
            switch (opt) {
            case 1:
                iniciarSessio(presentacio);
                break;
            case 2:
                registreUsuari(presentacio);
                break;
            case 3:
                Consultes(presentacio);
                break;
            case 4:
                cout << "Sortint..." << endl;
                return 0;
            default:
                cout << "Opcio no valida." << endl;
                break;
            }
        }
        else {
            switch (opt) {
            case 1:
                GestioUsuari(presentacio);
                break;
            case 2:
                Visualitzar(presentacio);
                break;
            case 3:
                Consultes(presentacio);
                break;
            case 4:
                tancarSessio(presentacio);
                break;
            case 5:
                cout << "Sortint..." << endl;
                return 0;
            default:
                cout << "Opcio no valida." << endl;
                break;
            }
        }
    }
}