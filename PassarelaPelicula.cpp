#include "PassarelaPelicula.h"

PassarelaPelicula::PassarelaPelicula() {}

PassarelaPelicula::PassarelaPelicula(const string& titolP, const string& descripcioP,
    const string& qualificacioP, int duracioP,
    const string& dataEstrenaP)
    : titol(titolP), descripcio(descripcioP), qualificacio(qualificacioP),
    duracio(duracioP), dataEstrena(dataEstrenaP) {
}

string PassarelaPelicula::getTitol() const { return titol; }
string PassarelaPelicula::getDescripcio() const { return descripcio; }
string PassarelaPelicula::getQualificacio() const { return qualificacio; }
int PassarelaPelicula::getDuracio() const { return duracio; }
string PassarelaPelicula::getDataEstrena() const { return dataEstrena; }

void PassarelaPelicula::setTitol(const string& nouTitol) { titol = nouTitol; }
void PassarelaPelicula::setDescripcio(const string& novaDescripcio) { descripcio = novaDescripcio; }
void PassarelaPelicula::setQualificacio(const string& novaQualificacio) { qualificacio = novaQualificacio; }
void PassarelaPelicula::setDuracio(int novaDuracio) { duracio = novaDuracio; }
void PassarelaPelicula::setDataEstrena(const string& novaDataEstrena) { dataEstrena = novaDataEstrena; }

void PassarelaPelicula::insereix() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    string query = "INSERT INTO pelicula (titol, descripcio, qualificacio, duracio, data_estrena) VALUES ('" +
        titol + "', '" + descripcio + "', '" + qualificacio + "', " + to_string(duracio) + ", '" + dataEstrena + "')";
    connexio.execSQL(query);
}

void PassarelaPelicula::modifica() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    string query = "UPDATE pelicula SET descripcio = '" + descripcio + "', qualificacio = '" + qualificacio +
        "', duracio = " + to_string(duracio) + ", data_estrena = '" + dataEstrena +
        "' WHERE titol = '" + titol + "'";
    connexio.execSQL(query);
}

void PassarelaPelicula::esborra() {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    string query = "DELETE FROM pelicula WHERE titol = '" + titol + "'";
    connexio.execSQL(query);
}