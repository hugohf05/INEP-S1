#ifndef TXCONSULTARELACIONADES_H
#define TXCONSULTARELACIONADES_H

#include <vector>
#include <memory>
#include "DTOPelicula.h"

class TxConsultaRelacionades {
public:
    explicit TxConsultaRelacionades(const std::string& titolPelicula);
    void executar();
    std::vector<DTOPelicula> obteResultat() const;

private:
    std::string titolPelicula;
    std::vector<DTOPelicula> relacionades;
};

#endif // TXCONSULTARELACIONADES_H
