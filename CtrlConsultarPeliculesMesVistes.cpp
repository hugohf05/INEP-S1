#include "CtrlConsultarPeliculesMesVistes.h"


// Constructor por defecto.
CtrlConsultarPeliculesMesVistes::CtrlConsultarPeliculesMesVistes() : pelicula(new PassarelaVisualitzacioPelicula()) {}

// Constructor parametrizado para inyectar una dependencia espec
// fica.
CtrlConsultarPeliculesMesVistes::CtrlConsultarPeliculesMesVistes(PassarelaVisualitzacioPelicula* pelicula) : pelicula(pelicula) {}

// Destructor para limpiar memoria.
CtrlConsultarPeliculesMesVistes::~CtrlConsultarPeliculesMesVistes() {
    delete pelicula;
}

// M�todo principal del controlador.
vector<DTOVisualitzacioPelicula> CtrlConsultarPeliculesMesVistes::consulta() {
    CercadoraContingut& cercadora = CercadoraContingut::getInstance();
    return cercadora.cercaPelMesVistes(); // Delegar la l�gica de consulta a la cercadora.
}
