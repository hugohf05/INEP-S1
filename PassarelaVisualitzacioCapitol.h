#ifndef PASSARELA_VISUALITZACIO_CAPITOL_H
#define PASSARELA_VISUALITZACIO_CAPITOL_H

#include "Connexio.h"

class PassarelaVisualitzacioCapitol {
private:
    string titolSerie;
    int numTemporada;
    int numCapitol;

public:
    
    //Constructor
    PassarelaVisualitzacioCapitol(const string& titol, int numTemporada, int numCapitol);
    
    //Metode per executar la transacció
    void registraVisualitzacioCapitol();
    
    //Obtenim el resultat de la transacció
    string ConsultaVisualitzacioCapitol();
};

#endif