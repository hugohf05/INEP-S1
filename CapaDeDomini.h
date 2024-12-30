#include "DTOUsuari.h"
#include "DTOPelicula.h"
#include "PassarelaUsuari.h"
#include "PassarelaVisualitzacio.h"
#include "TxRegistreUsuari.cpp"
#include "TxEsborraUsuari.cpp"
#include "CercadoraPelicula.h"

class CapaDeDomini
{
private:
	//Atributs

	//Constructor Privat
	CapaDeDomini() {}
public:
	//Metode per obtenir la unica instància
	static CapaDeDomini& getInstance() {
		static CapaDeDomini instance;
		return instance;
	}
	// aqui tots els metodes que
	void registreUsuari(const string& sobrenomU, const string& nomU,
		const string& correu_electronicU, const string& contrasenyaU,
		const string& data_naixementU, const string& subscricpioU);
	bool verificaCredencials(const std::string& sobrenom, const std::string& contrasenya);
	DTOUsuari consultaUsuari(string sobrenom_usuari);
	void modificaUsuari();
	void esborraUsuari(const string& contrasenyaU);

	//Visualitzacio Continguts
	DTOPelicula consultaPelicula(const string& titolPelicula);
	void registreVisualitzacio(const string &titolPelicula);
	vector<DTOPelicula> consultaRelacionades(const string& titolPelicula);
	vector<DTOPelicula> consultaMesVistes();
};
