#include "Connexio.h"

class PassarelaVisualitzacio {
private:
    string titolPelicula;

public:
    explicit PassarelaVisualitzacio(const string& titol) : titolPelicula(titol) {}

    void registra();
};
