#ifndef CERCADORA_USUARI_H
#define CERCADORA_USUARI_H

#include <string>
#include "Connexio.h"
#include "PassarelaUsuari.h"

class CercadoraUsuari {
public:
    
    PassarelaUsuari* cerca(const string& sobrenomU);

};

#endif // CERCADORA_USUARI_H