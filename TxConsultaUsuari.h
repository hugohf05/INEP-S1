#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CercadoraContingut.h"
#include "DTOVisualitzacioPelicula.h"
#include "PetitFlix.h"
#include "CercadoraUsuari.h"
#include"PassarelaUsuari.h"
#include"DTOUsuari.h"
using namespace std;

class TxConsultaUsuari {
public:
    TxConsultaUsuari();
    void executar();
    vector<string> obteResultat() const;

private:
    vector<string> resultat;
};
