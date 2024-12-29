#ifndef TXREGISTREVISUALITZACIO_H
#define TXREGISTREVISUALITZACIO_H

#include <string>

class TxRegistreVisualitzacio {
public:
    explicit TxRegistreVisualitzacio(const std::string& titolPelicula);
    void executar();

private:
    std::string titolPelicula;
};

#endif // TXREGISTREVISUALITZACIO_H#pragma once
