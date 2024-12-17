#include "DTOUsuari.h"
#include "PassarelaUsuari.h"

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
	void registreUsuari(string nom, string sobrenom, string correu);
	bool verificaCredencials(const std::string& sobrenom, const std::string& contrasenya);
	DTOUsuari consultaUsuari(string sobrenom_usuari);
	void modificaUsuari();
	void esborraUsuari();
};
