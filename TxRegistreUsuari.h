#ifndef TXREGISTRAUSUARI_H
#define TXREGISTRAUSUARI_H

#include <string>

class TxRegistraUsuari {
public:
    TxRegistraUsuari(const std::string& nom, const std::string& sobrenom, const std::string& contrasenya,
        const std::string& correuElectronic, const std::string& dataNaixement,
        const std::string& subscripcio);
    void executar();

private:
    std::string nom;
    std::string sobrenom;
    std::string contrasenya;
    std::string correuElectronic;
    std::string dataNaixement;
    std::string subscripcio;
};

#endif // TXREGISTRAUSUARI_H#pragma once
