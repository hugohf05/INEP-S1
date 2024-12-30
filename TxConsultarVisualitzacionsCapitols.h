#pragma once

#include <vector>
#include <string>
#include "CercadoraContingut.h"
#include "DTOVisualitzacioCapitol.h"
using namespace std;

class TxConsultarVisualitzacionsCapitols {
public:
    TxConsultarVisualitzacionsCapitols(const string& sobrenomUsuari);
    void executar();
    vector<DTOVisualitzacioCapitol> obteResultat() const;

private:
    string sobrenomUsuari;
    vector<DTOVisualitzacioCapitol> visualitzacions;
};


