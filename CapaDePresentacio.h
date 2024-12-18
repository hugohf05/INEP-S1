#ifndef CAPADEPRESENTACIO_H
#define CAPADEPRESENTACIO_H

#include "CapaDeDomini.h"
#include <conio.h> // Para getch
#include <vector>
#include "DTOUsuari.h"
#include "DTOPelicula.h"
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
	void consultaUsuari();
	void modificaUsuari();
	void esborraUsuari();

	//Menu Visualitzacio Continguts
	void visualitzarPelicula();
	void visualitzarCapitol();
	void consultarVisualitzacions();

	//Consultes
	void consultaProperesEstrenes();
	void consulaUltimesNovetats();
	void consultarPeliculesMesVistes();
};

#endif
