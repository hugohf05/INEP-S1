#ifndef TXCONSULTAPROPERES_ESTRENES_H
#define TXCONSULTAPROPERES_ESTRENES_H

#include <vector>
#include <memory>
#include <string>
#include "DTOContingut.h"

class TxConsultaProperesEstrenes {
public:
    // Constructor
    explicit TxConsultaProperesEstrenes(const std::string& modalitat);

    // Ejecutar la transacción
    void executar();

    // Obtener el resultado de la transacción
    const std::vector<std::unique_ptr<DTOContingut>>& obteResultat() const;

private:
    std::string modalitat; // Modalitat de subscripció
    std::vector<std::unique_ptr<DTOContingut>> estrenes; // Resultados de la consulta
};

#endif // TXCONSULTAPROPERES_ESTRENES_H
