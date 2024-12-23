#ifndef CERCADORA_USUARI_H
#define CERCADORA_USUARI_H

#include <string>
#include "Connexio.h"
#include "PassarelaUsuari.h"

class CercadoraUsuari {
public:
    // Operación para buscar un usuario por sobrenom
    PassarelaUsuari* cercaPerSobrenom(const string& sobrenomU);
};

#endif // CERCADORA_USUARI_H