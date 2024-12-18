#include "DTOUsuari.h"
#include "PassarelaUsuari.h"
#include "TxRegistreUsuari.cpp"
#include "TxEsborraUsuari.cpp"

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
};
