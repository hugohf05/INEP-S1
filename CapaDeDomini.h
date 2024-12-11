#include <vector>
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
	vector<string> consultaUsuari(string sobrenom_usuari);
	void modificaUsuari(ConnexioBD& connexio);
	void esborraUsuari(ConnexioBD& connexio);
};