#ifndef PASSARELA_VISUALITZACIO_CAPITOL_H
#define PASSARELA_VISUALITZACIO_CAPITOL_H

#include "Connexio.h"

class PassarelaVisualitzacioCapitol {
private:
    string titolSerie;
    int numTemporada;
    int numCapitol;
    string dataVisualitzacio;
    int numVisualitzacions;

public:
    
    //Constructors
    PassarelaVisualitzacioCapitol();
    PassarelaVisualitzacioCapitol(const string& titol);
    PassarelaVisualitzacioCapitol(const string& titol, int numTemporada, int numCapitol);
    
    //Metode per executar la transaccio
    void registraVisualitzacioCapitol();

    string obteTitol() const;
    string obteDataVisualitzacio() const;
    int obteNumVisualitzacions() const;
};

#endif
