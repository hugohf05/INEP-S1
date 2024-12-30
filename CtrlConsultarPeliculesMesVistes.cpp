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

// Método principal del controlador.
vector<DTOVisualitzacioPelicula> CtrlConsultarPeliculesMesVistes::consulta() {
    CercadoraContingut& cercadora = CercadoraContingut::getInstance();
    return cercadora.cercaPelMesVistes(); // Delegar la lógica de consulta a la cercadora.
}
