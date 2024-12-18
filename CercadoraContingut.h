#include <stdexcept>
#include "PassarelaPelicula.h"
#include "Connexio.h"
#include "DTOPelicula.h"

class CercadoraContingut {
public:
    PassarelaPelicula cercaPelicula(const string& titolPelicula);
};