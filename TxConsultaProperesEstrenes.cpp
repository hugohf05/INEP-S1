#include "TxConsultaProperesEstrenes.h"
#include "CercadoraContingut.h"

TxConsultaProperesEstrenes::TxConsultaProperesEstrenes(const std::string& modalitat)
    : modalitat(modalitat) {
}

void TxConsultaProperesEstrenes::executar() {
    try {
        vector<DTOPelicula> pelicules = CercadoraContingut::getInstance().cercaProperesPelicules(modalitat);
        for (auto& pelicula : pelicules) {
            estrenes.push_back(std::make_unique<DTOPelicula>(std::move(pelicula)));
        }

        vector<DTOSerie> series = CercadoraContingut::getInstance().cercaProperesSeries(modalitat);
        for (auto& serie : series) {
            estrenes.push_back(std::make_unique<DTOSerie>(std::move(serie)));
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al consultar properes estrenes: " + std::string(e.what()));
    }
}

const std::vector<std::unique_ptr<DTOContingut>>& TxConsultaProperesEstrenes::obteResultat() const {
    return estrenes;
}
