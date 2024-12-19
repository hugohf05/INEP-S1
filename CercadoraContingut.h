#ifndef CERCADORA_CONTINGUT_H
#define CERCADORA_CONTINGUT_H

#include <vector>
#include <string>
#include "DTOPelicula.h"
#include "Connexio.h"
#include "DTOSerie.h"

class CercadoraContingut {
public:
    // Obtener la instancia única (patrón Singleton)
    static CercadoraContingut& getInstance() {
        static CercadoraContingut instance;
        return instance;
    }

    // Consulta de próximas películas
    std::vector<DTOPelicula> cercaProperesPelicules(const std::string& modalitat);

    // Consulta de próximas series
    std::vector<DTOSerie> cercaProperesSeries(const std::string& modalitat);

    DTOPelicula cercaPelicula(const std::string& titol);

    std::vector<DTOPelicula> cercaRelacionades(const std::string& titol);


private:
    // Constructor privado para Singleton
    CercadoraContingut() = default;

    // Prohibir copias y asignaciones
    CercadoraContingut(const CercadoraContingut&) = delete;
    CercadoraContingut& operator=(const CercadoraContingut&) = delete;
};

#endif // CERCADORA_CONTINGUT_H
