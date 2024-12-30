#ifndef TXCONSULTAPELICULA_H
#define TXCONSULTAPELICULA_H

#include <memory>
#include <string>
#include "DTOPelicula.h"

class TxConsultaPelicula {
public:
    explicit TxConsultaPelicula(const std::string& titol);
    void executar();
    DTOPelicula obteResultat();

private:
    std::string titol;
    DTOPelicula pelicula;
};

#endif // TXCONSULTAPELICULA_H
