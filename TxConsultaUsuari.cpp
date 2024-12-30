#include "TxConsultaUsuari.h"

using namespace std;

TxConsultaUsuari::TxConsultaUsuari() {};

void TxConsultaUsuari::executar() {
    vector<string> v;
    PetitFlix& sistema = PetitFlix::getInstance();
    PassarelaUsuari* Pusuari = sistema.obtenirUsuariLoggejat();
    v.push_back(Pusuari->getSobrenom());
    v.push_back(Pusuari->getContrasenya());
    v.push_back(Pusuari->getNom());
    v.push_back(Pusuari->getCorreuElectronic());
    v.push_back(Pusuari->getDataNaixement());
    v.push_back(Pusuari->getSubscricpio());
    resultat = v;
}

vector<string> TxConsultaUsuari::obteResultat() const { return resultat; }
