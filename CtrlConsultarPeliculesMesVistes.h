#pragma once
#include <vector>
#include "PassarelaVisualitzacio.h"
#include "DTOVisualitzacioPelicula.h"
#include "CercadoraContingut.h"


using namespace std;

class CtrlConsultarPeliculesMesVistes
{
public:

	CtrlConsultarPeliculesMesVistes();
	CtrlConsultarPeliculesMesVistes(PassarelaVisualitzacioPelicula* pelicula);

	~CtrlConsultarPeliculesMesVistes();

	vector<DTOVisualitzacioPelicula> consulta();
private:
	PassarelaVisualitzacioPelicula *pelicula;
};
