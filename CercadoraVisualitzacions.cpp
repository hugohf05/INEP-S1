#include "CercadoraVisualitzacions.h"
#include "PassarelaVisualitzacio.h"

pair<int, int> CercadoraVisualitzacions::cercaVisualitzacions(const std::string& sobrenom) {
    ConnexioBD& con = *ConnexioBD::getInstance();

    int peliculesVistes = 0;
    int capitolsVistos = 0;

    try {
        // Consultar número total de peliculas vistas.

        string query = "SELECT COUNT(*) AS total FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "'";

        sql::ResultSet* res1= con.consultaSQL(query);
        if (res1->next()) {
            peliculesVistes = res1->getInt("total");
        }
        delete res1;

        // Consultar número total de capitulos vistos.
        string query2= "SELECT COUNT(*) AS total FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "'";

        sql::ResultSet* res2 = con.consultaSQL(query2);
        if (res2->next()) {
            capitolsVistos = res2->getInt("total");
        }
        delete res2;

    }
    catch (const sql::SQLException& e) {
        throw std::runtime_error("Error en cercaVisualitzacionsUsuari: " + std::string(e.what()));
    }

    return { peliculesVistes, capitolsVistos };
}
