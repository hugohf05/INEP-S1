#ifndef DTOUSUARI_H // Si no se ha definido DTOUSUARI_H
#define DTOUSUARI_H // Definelo ahora

#include "PassarelaUsuari.h"
#include <string>

using namespace std;

class DTOUsuari {
public:
	DTOUsuari(PassarelaUsuari usu) {
		sobrenom = usu.getSobrenom();
		nom = usu.getNom();
		correu = usu.getCorreuElectronic();
		dataNaixement = usu.getDataNaixement();
		modalitat = usu.getSubscricpio();
	}
	string obteSobrenom() { return sobrenom; }
	string obteNom() { return nom; }
	string obteCorreu() { return correu; }
	string obteDataNaixement() { return dataNaixement; }
	string obteModalitat() { return modalitat; }
private:
	string sobrenom = "";
	string nom = "";
	string correu = "";
	string dataNaixement = "";
	string modalitat = "";
};

#endif // DTOUSUARI_H
