#ifndef CERCADORA_CONTINGUT_H
#define CERCADORA_CONTINGUT_H

#include <vector>
#include <string>
#include "DTOPelicula.h"
#include "Connexio.h"
#include "DTOSerie.h"
#include "DTOCapitol.h"
#include "DTOVisualitzacioCapitol.h"
#include "DTOVisualitzacioPelicula.h"
#include "PetitFlix.h"
#include <sstream>

using namespace std;

class CercadoraContingut {
public:
    // Obtener la instancia �nica (patr�n Singleton)
    static CercadoraContingut& getInstance() {
        static CercadoraContingut instance;
        return instance;
    }

    // Consulta de pr�ximas pel�culas
    vector<DTOPelicula> cercaProperesPelicules(const std::string& modalitat);

    // Consulta de pr�ximas series
    vector<DTOSerie> cercaProperesSeries(const std::string& modalitat);

    //Consulta de les ultimes pelicules estrenades
    vector<DTOPelicula> cercaUltimesPelicules(const string& modalitat);
    
    //Consulta de les ultimes series estrenades
    vector<DTOSerie> cercaUltimesSeries(const string& modalitat);

    //Consulta per obtenir el numero de la ultima tmeporada estrenada d'una serie
    int obteUltimaTemporadaEstrena(const std::string& titolSerie);

    //Consulta de l'ultim capitol d'una temporada
    DTOCapitol obteUltimCapitolDeTemporada(const std::string& titolSerie, int temporada);

    DTOPelicula cercaPelicula(const std::string& titol);

    vector<DTOPelicula> cercaRelacionades(const std::string& titol);

    //Consulta la serie on s.titol = titol
    DTOSerie cercaSerie(const std::string& titol);

    //Consulta el numero de temporades d'una serie
    int obtenirNumeroTemporades(const string& titol);

    //Consulta tots els capitols d'una temporada
    vector<DTOCapitol> obtenirCapitolsPerTemporada(const string& titol_serie, int numero_temporada);

    vector<DTOVisualitzacioCapitol>cercaVisualitzacionsCapitol(const std::string& sobrenomUsuari);
    vector<DTOVisualitzacioPelicula> cercaVisualitzacionsPelicula(const string& sobrenomUsuari); //cerca les visualitzacions de una pelicula
    string ConsultaVisualitzacioCapitol(string titolSerie, int numTemporada, int numCapitol);
    vector<DTOVisualitzacioPelicula> cercaPelMesVistes();


private:
    // Constructor privado para Singleton
    CercadoraContingut() = default;

    // Prohibir copias y asignaciones
    CercadoraContingut(const CercadoraContingut&) = delete;
    CercadoraContingut& operator=(const CercadoraContingut&) = delete;
};

#endif // CERCADORA_CONTINGUT_H
