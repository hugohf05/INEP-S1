#ifndef DTOUSUARI_H // Si no se ha definido DTOUSUARI_H
#define DTOUSUARI_H // Defínelo ahora

#include "PassarelaUsuari.h"
#include <string>

using namespace std;

class DTOUsuari {
public:
	DTOUsuari(PassarelaUsuari usu) {
		sobrenom = usu.getSobrenom();
		nom = usu.getNom();
		correu = usu.getCorreuElectronic();
	}
	string obteSobrenom() { return sobrenom; }
	string obteNom() { return nom; }
	string obteCorreu() { return correu; }
private:
	string sobrenom = "";
	string nom = "";
	string correu = "";
};

#endif // DTOUSUARI_H
