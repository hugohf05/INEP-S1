#pragma once
#include <vector>
#include <string>
#include "CercadoraContingut.h"
#include "DTOVisualitzacioPelicula.h"
using namespace std;

class TxConsultarVisualitzacionsPelicules {
public:
    TxConsultarVisualitzacionsPelicules();
    TxConsultarVisualitzacionsPelicules(const std::string& sobrenomUsuari);
    void executar();
    vector<DTOVisualitzacioPelicula> obteResultat() const;

private:
    string sobrenomUsuari;
    vector<DTOVisualitzacioPelicula> visualitzacions;
};


