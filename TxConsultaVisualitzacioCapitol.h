#ifndef TX_CONSULTA_VISUALITZACIO_CAPITOL_H
#define TX_CONSULTA_VISUALITZACIO_CAPITOL_H

#include <string>

class TxConsultaVisualitzacioCapitol {
private:
    std::string _titolSerie;
    int _numTemporada;
    int _numCapitol;
    std::string dataVisualitzacio;

public:
    
    //Constructor
    TxConsultaVisualitzacioCapitol(const std::string& titolSerie, int numTemporada, int numCapitol)
        : _titolSerie(titolSerie), _numTemporada(numTemporada), _numCapitol(numCapitol) {}
    
    //Metode per executar la transacció
    void executar();
    
    //Obtenim el resultat de la transacció
    std::string obteResultat();
};

#endif // TX_CONSULTA_VISUALITZACIO_CAPITOL_H
