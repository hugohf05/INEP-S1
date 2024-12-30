#ifndef CERCADORA_VISUALITZACIONS_H
#define CERCADORA_VISUALITZACIONS_H

#include <string>
#include "Connexio.h"
#include "PassarelaVisualitzacio.h"

using namespace std;

class CercadoraVisualitzacions {
public:
    pair<int,int> cercaVisualitzacions(const string& sobrenom); //cerca les visualitzacions totals de les pelicules vistes i capitols vistos
};

#endif #pragma once
