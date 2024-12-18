#ifndef CERCADORA_PELICULA_H
#define CERCADORA_PELICULA_H

#include <string>
#include "PassarelaPelicula.h"
#include <vector>
#include "Connexio.h"
#include "DTOPelicula.h"

class CercadoraPelicula {
public:
    PassarelaPelicula cercaPerTitol(const string& titolPelicula);
    vector<PassarelaPelicula> cercaRelacionades(const string& titolPelicula);
};

#endif // CERCADORA_PELICULA_H
