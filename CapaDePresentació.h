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
	void registreUsuari(ConnexioBD& connexio);
	void consultaUsuari(ConnexioBD& connexio);
	void modificaUsuari(ConnexioBD& connexio);
	void esborraUsuari(ConnexioBD& connexio);
};