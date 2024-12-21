#include <string>
using namespace std;


class TxIniciSessio {
    string sobrenom;
    string contrasenya;

public:
    TxIniciSessio(const string& sobrenomU, const string& contrasenyaU);

    void executar();
};