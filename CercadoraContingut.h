#ifndef CERCADORA_CONTINGUT_H
#define CERCADORA_CONTINGUT_H

#include <vector>
#include <string>
#include "DTOPelicula.h"
#include "Connexio.h"
#include "DTOSerie.h"
#include "DTOCapitol.h"

class CercadoraContingut {
public:
    // Obtener la instancia �nica (patr�n Singleton)
    static CercadoraContingut& getInstance() {
        static CercadoraContingut instance;
        return instance;
    }

    // Consulta de pr�ximas pel�culas
    std::vector<DTOPelicula> cercaProperesPelicules(const std::string& modalitat);

    // Consulta de pr�ximas series
    std::vector<DTOSerie> cercaProperesSeries(const std::string& modalitat);

    //Consulta de les ultimes pel·lícules estrenades
    vector<DTOPelicula> cercaUltimesPelicules(const string& modalitat);
    
    //Consulta de les ultimes sèries estrenades
    vector<DTOSerie> cercaUltimesSeries(const string& modalitat);

    //Consulta per obtenir el numero de la ultima tmeporada estrenada d'una sèrie
    int obteUltimaTemporadaEstrena(const std::string& titolSerie);

    //Consulta de l'ultim capítol d'una temporada
    DTOCapitol obteUltimCapitolDeTemporada(const std::string& titolSerie, int temporada);

    DTOPelicula cercaPelicula(const std::string& titol);

    std::vector<DTOPelicula> cercaRelacionades(const std::string& titol);

    //Consulta la serie on s.titol = titol
    DTOSerie cercaSerie(const std::string& titol);

    //Consulta el número de temporades d'una sèrie
    int obtenirNumeroTemporades(const string& titol);

    //Consulta tots els capítols d'una temporada
    vector<DTOCapitol> obtenirCapitolsPerTemporada(const string& titol_serie, int numero_temporada);


private:
    // Constructor privado para Singleton
    CercadoraContingut() = default;

    // Prohibir copias y asignaciones
    CercadoraContingut(const CercadoraContingut&) = delete;
    CercadoraContingut& operator=(const CercadoraContingut&) = delete;
};

#endif // CERCADORA_CONTINGUT_H