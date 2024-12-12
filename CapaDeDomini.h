#include "DTOUsuari.h"
#include "PassarelaUsuari.h"

class CapaDeDomini
{
private:
	//Atributs

	//Constructor Privat
	CapaDeDomini() {}
public:
	//Metode per obtenir la �nica inst�ncia
	static CapaDeDomini& getInstance() {
		static CapaDeDomini instance;
		return instance;
	}
	// aqu� tots els m�todes que
	void registreUsuari(string nom, string sobrenom, string correu);
	DTOUsuari consultaUsuari(string sobrenom_usuari);
	void modificaUsuari();
	void esborraUsuari();
};