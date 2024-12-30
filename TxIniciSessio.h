#ifndef INICI_SESSIO_H
#define INICI_SESSIO_H

#include <string>
using namespace std;


class TxIniciSessio {
    string sobrenom;
    string contrasenya;

public:
    
    //Constructor
    TxIniciSessio(const string& sobrenomU, const string& contrasenyaU);
    
    //Metode per executar la transaccio
    void executar();
};
#endif
