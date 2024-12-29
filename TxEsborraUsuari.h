#ifndef TXESBORRARUSUARI_H
#define TXESBORRARUSUARI_H

#include <string>
using namespace std;

class TxEsborrarUsuari {
    string contrasenya;

public:
    TxEsborrarUsuari(const string& contrasenyaU);

    void executar();
};

#endif // TXESBORRARUSUARI_H#pragma once
