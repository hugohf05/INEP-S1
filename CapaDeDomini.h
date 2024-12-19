#ifndef CAPADEDOMINI_H
#define CAPADEDOMINI_H

#include "DTOUsuari.h"
#include "PassarelaVisualitzacio.h"
#include "TxRegistreUsuari.h"
#include "TxEsborraUsuari.h"
#include "CercadoraPelicula.h"
#include "CercadoraContingut.h"

class CapaDeDomini
{
private:
	//Atributs

	//Constructor Privat
	CapaDeDomini() {}
public:
	//Metode per obtenir la única instància
	static CapaDeDomini& getInstance() {
		static CapaDeDomini instance;
		return instance;
	}
	// aquí tots els métodes que
	void registreUsuari(const string& sobrenomU, const string& nomU,
		const string& correu_electronicU, const string& contrasenyaU,
		const string& data_naixementU, const string& subscricpioU);
	bool verificaCredencials(const std::string& sobrenom, const std::string& contrasenya);
	DTOUsuari consultaUsuari(string sobrenom_usuari);
	void modificaUsuari();
	void esborraUsuari(const string& contrasenyaU);

	//Visualitzacio Continguts
	DTOPelicula consultaPelicula(const string& titolPelicula);
	void registreVisualitzacio(const string& titolPelicula);
	vector<DTOPelicula> consultaRelacionades(const string& titolPelicula);
	vector<unique_ptr<DTOContingut>> consultaProperesEstrenes(const string& modalitat);
};

#endif