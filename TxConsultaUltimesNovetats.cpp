#include "TxConsultaUltimesNovetats.h"
#include "CercadoraContingut.h"
#include "DTOPelicula.h"
#include "DTOCapitol.h"

TxConsultaUltimesNovetats::TxConsultaUltimesNovetats(const std::string& modalitat)
    : modalitat(modalitat) {
}

void TxConsultaUltimesNovetats::executar() {
    try {
        // Consultar películas
        vector<DTOPelicula> pelicules = CercadoraContingut::getInstance().cercaUltimesPelicules(modalitat);
        for (auto& pelicula : pelicules) {
            // Insertar las películas como punteros a DTOContingut
            novetatsContingut.push_back(make_unique<DTOPelicula>(std::move(pelicula)));
        }
        vector<DTOSerie> series = CercadoraContingut::getInstance().cercaUltimesSeries(modalitat);
        for (auto& serie : series) {
            // Insertar los capítulos como punteros a DTOContingut
            // Insertar el capitol como un puntero único a DTOContingut
            novetatsContingut.push_back(std::make_unique<DTOSerie>(std::move(serie)));
        }
    }
    catch (const exception& e) {
        throw runtime_error("Error al consultar ultimes novetats: " + std::string(e.what()));
    }
}

const vector<unique_ptr<DTOContingut>>& TxConsultaUltimesNovetats::obteResultatContingut() const {
    return novetatsContingut;
}
