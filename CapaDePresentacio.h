#ifndef CAPADEPRESENTACIO_H
#define CAPADEPRESENTACIO_H

#include <conio.h> // Para getch
#include <vector>
#include "DTOUsuari.h"
#include "DTOPelicula.h"
#include "DTOSerie.h"
#include "PetitFlix.h"
#include "TxConsultaProperesEstrenes.h"
#include "TxConsultaPelicula.h"
#include "TxRegistreUsuari.h"
#include "TxEsborraUsuari.h"
#include "TxTancaSessio.h"
#include "TxIniciSessio.h"
#include "TxRegistreVisualitzacio.h"
#include "TxConsultaRelacionades.h"

class CapaDePresentacio
{
private:
	//Atributs
	
	//Constructor Privat
	CapaDePresentacio() {}
public:
	//Metode per obtenir la única instància
	static CapaDePresentacio& getInstance() {
		static CapaDePresentacio instance;
		return instance;
	}
	// aquí tots els métodes que
	void iniciarSessio();
	void registreUsuari();
	void tancarSessio();
	
	//Menú Gestió Usuaris
	//void consultaUsuari();
	void modificaUsuari();
	//void modificaContrasenya();
	void esborraUsuari();

	//Menu Visualitzacio Continguts
	void visualitzarPelicula();
	//void visualitzarCapitol();
	//void consultarVisualitzacions();

	//Consultes
	void consultaProperesEstrenes();
	//void consulaUltimesNovetats();
	//void consultarPeliculesMesVistes();
};

#endif
