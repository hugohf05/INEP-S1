#ifndef TX_REGISTRE_VISUALITZACIO_CAPITOL_H
#define TX_REGISTRE_VISUALITZACIO_CAPITOL_H

#include <string>

class TxRegistreVisualitzacioCapitol {
private:
    std::string _titolSerie;
    int _numTemporada;
    int _numCapitol;

public:
    
    //Constructor
    TxRegistreVisualitzacioCapitol(const std::string& titolSerie, int numTemporada, int numCapitol)
        : _titolSerie(titolSerie), _numTemporada(numTemporada), _numCapitol(numCapitol) {}
    
    //Metode per executar la transaccio
    void executar();
};

#endif // TX_REGISTRE_VISUALITZACIO_CAPITOL_H
