#pragma once
#include <vector>
#include <string>
#include "Connexio.h"
#include "DTOVisualitzacioPelicula.h"
#include "PetitFlix.h"

using namespace std;

class PassarelaVisualitzacioPelicula {
private:
    string titolPelicula;
    string dataVisualitzacio;
    int numVisualitzacions;
public:

    PassarelaVisualitzacioPelicula();
    PassarelaVisualitzacioPelicula(const string& titol);

    void registra();

    string obteTitol() const;
    string obteDataVisualitzacio() const;
    int obteNumVisualitzacions() const;
};
