#ifndef CERCADORA_PELICULA_H
#define CERCADORA_PELICULA_H

#include "PassarelaPelicula.h"
#include <vector>
#include "DTOPelicula.h"

class CercadoraPelicula {
public:
    DTOPelicula cercaPerTitol(const string& titolPelicula);
    vector<DTOPelicula> cercaRelacionades(const string& titolPelicula);
};

#endif // CERCADORA_PELICULA_H
