#pragma once
#include <vector>
//#include "DTOCapitol"
#include "DTOVisualitzacioCapitol.h"
#include "Connexio.h"

class CercadoraCapitol {
public:
   // DTOVisualitzacioCapitol cercaPerTitol(const string& titolPelicula); //PassarelaCapitol?
    vector<DTOVisualitzacioCapitol> cercaVisualitzacions(const string& sobrenomUsuari); //cerca les visualitzacions de un capitol
};
