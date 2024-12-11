#include <vector>
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
	vector<string> consultaUsuari(string sobrenom_usuari);
	void modificaUsuari(ConnexioBD& connexio);
	void esborraUsuari(ConnexioBD& connexio);
};