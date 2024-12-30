#include <vector>
#include <iostream>
#include "TxConsultaUsuari.h"
#include "PassarelaUsuari.h"
using namespace std;

class CtrlModificaUsuari 
{
public:
	CtrlModificaUsuari();
	//Altres
	vector<string> consultaUsuari();
	void modificaUsuari(const std::string& sobrenom,
		const string& nouNom,
		const string& nouCorreu,
		const string& novaDataNaixement,
		const string& novaSubscripcio);
private:
	PassarelaUsuari *usuari;
};
