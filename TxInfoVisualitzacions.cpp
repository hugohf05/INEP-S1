#pragma once
#include <iostream>
#include "PetitFlix.h"
#include "CercadoraVisualitzacions.h"

class TxInfoVisualitzacions {
private:
    pair<int, int> resultat;

public:
    void executar() {
        vector<string> v;
        PetitFlix& sistema = PetitFlix::getInstance();
        PassarelaUsuari* usuari = sistema.obtenirUsuariLoggejat();
        string sobrenomU = usuari->getSobrenom();

        CercadoraVisualitzacions cercadoraV;
        resultat = cercadoraV.cercaVisualitzacions(sobrenomU);
    }

    pair<int, int> obteResultat() const { return resultat; }
};
