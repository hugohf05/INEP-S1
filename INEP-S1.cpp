#include "CapaDePresentacio.h"
#include <iostream>

using namespace std;

int main() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int opt;

    cout << "1. Gestio usuari" << endl;
    cout << "2. Sortir" << endl;
    cout << "Escull una opcio: ";

    while (cin >> opt && opt != 2) {
        switch (opt) {
        case 1:
            int optUsuari;
            cout << "1. Registre usuari" << endl;
            cout << "2. Consulta usuari" << endl;
            cout << "3. Modifica usuari" << endl;
            cout << "4. Esborra usuari" << endl;
            cout << "Escull una opcio: ";

            cin >> optUsuari;
            switch (optUsuari) {
            case 1:
                presentacio.registreUsuari();
                break;
            case 2:
                presentacio.consultaUsuari();
                break;
            case 3:
                presentacio.modificaUsuari();
                break;
            case 4:
                presentacio.esborraUsuari();
                break;
            default:
                cout << "Opció no vàlida." << endl;
            }
            break;
        default:
            cout << "Opció no vàlida." << endl;
        }
        cout << "1. Gestio usuari" << endl;
        cout << "2. Sortir" << endl;
        cout << "Escull una opcio: ";
    }

    return 0;
}
