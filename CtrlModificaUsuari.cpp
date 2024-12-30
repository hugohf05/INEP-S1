#include "CtrlModificaUsuari.h"

CtrlModificaUsuari::CtrlModificaUsuari() {
    PetitFlix& sistema = PetitFlix::getInstance();
    usuari = sistema.obtenirUsuariLoggejat();
}

vector<string> CtrlModificaUsuari::consultaUsuari()
{
    TxConsultaUsuari txConsulta;
    txConsulta.executar();
    vector<string> infoUsuari;
    infoUsuari = txConsulta.obteResultat();
    return infoUsuari;
}

void CtrlModificaUsuari::modificaUsuari(
    const std::string& nouNom,
    const std::string& novaContra,
    const std::string& nouCorreu,
    const std::string& novaDataNaixement,
    const std::string& novaSubscripcio
) {
    if (nouNom != "") {
        usuari->setNom(nouNom);
    }
    if (novaContra != "") {
        usuari->setContrasenya(novaContra);
    }
    if (nouCorreu != "") {
        usuari->setCorreuElectronic(nouCorreu);
    }
    if (novaDataNaixement != "") {
        usuari->setDataNaixement(novaDataNaixement);
    }
    if (novaSubscripcio != "") {
        usuari->setSubscripcio(novaSubscripcio);
    }
    if (nouNom != "" or novaContra != "" or nouCorreu != "" or novaDataNaixement != "" or novaSubscripcio != "") {
        usuari->modifica();
    }
}
