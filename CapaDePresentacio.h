#ifndef CAPADEPRESENTACIO_H
#define CAPADEPRESENTACIO_H

#include <conio.h> // Para getch
#include <vector>
#include <ctime>   // Para comprobar fechas
#include <chrono>
#include "DTOUsuari.h"
#include "DTOPelicula.h"
#include "DTOSerie.h"
#include "DTOVisualitzacioCapitol.h"
#include "DTOVisualitzacioPelicula.h"
#include "PetitFlix.h"
#include "TxConsultaProperesEstrenes.h"
#include "TxConsultaPelicula.h"
#include "TxRegistreUsuari.h"
#include "TxEsborraUsuari.h"
#include "TxRegistreVisualitzacio.h"
#include "TxConsultaRelacionades.h"
#include "TxTancaSessio.h"
#include "TxIniciSessio.h"
#include "TxConsultaUltimesNovetats.h"
#include "TxConsultaNovetatsSerie.h"
#include "TxConsultaSerie.h"
#include "TxConsultaTemporades.h"
#include "TxConsultaCapitols.h"
#include "TxRegistreVisualitzacioCapitol.h"
#include "TxConsultaVisualitzacioCapitol.h"
#include "CtrlConsultarPeliculesMesVistes.h"
#include "CtrlModificaUsuari.h"
#include "TxInfoVisualitzacions.cpp"
#include "TxConsultarVisualitzacionsCapitols.h"
#include "TxConsultarVisualitzacionsPelicules.h"
#include "CercadoraVisualitzacions.h"
#include "CercadoraContingut.h"



class CapaDePresentacio
{
private:
	//Atributs

	//Constructor Privat
	CapaDePresentacio() {}
public:
	//Metode per obtenir la unica instancia
	static CapaDePresentacio& getInstance() {
		static CapaDePresentacio instance;
		return instance;
	}
	// aqui tots els metodes que
	void iniciarSessio();
	void registreUsuari();
	void tancarSessio();

	//Menu Gestio Usuaris
	void consultaUsuari();
	void modificaUsuari();
	string llegirContrasenya();
	//void modificaContrasenya();
	void esborraUsuari();

	//Menu Visualitzacio Continguts
	void visualitzarPelicula();
	void visualitzarCapitol();
	void consultarVisualitzacions();

	//Consultes
	void consultaProperesEstrenes();
	void consultaUltimesNovetats();
	void consultarPeliculesMesVistes();
};

#endif
