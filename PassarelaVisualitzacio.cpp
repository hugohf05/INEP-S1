#include "PassarelaVisualitzacio.h"
#include "Connexio.h"

PassarelaVisualitzacio::PassarelaVisualitzacio(const string& titol) : titolPelicula(titol) {}

void PassarelaVisualitzacio::registra() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    string query = "INSERT INTO visualitzacio_pelicula (titol_pelicula, data, num_visualitzacions) "
        "VALUES ('" + titolPelicula + "', NOW(), 1)";
    connexio.execSQL(query);
}
