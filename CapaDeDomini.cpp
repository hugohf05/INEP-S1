#include "CapaDeDomini.h"
#include "CercadoraUsuari.h"

void CapaDeDomini::registreUsuari(const string& sobrenomU, const string& nomU,
    const string& correu_electronicU, const string& contrasenyaU,
    const string& data_naixementU, const string& subscripcioU) {

    try {
        TxRegistreUsuari txRU(sobrenomU, nomU, correu_electronicU, contrasenyaU, data_naixementU, subscripcioU);
        txRU.executar();
    }
    catch (const sql::SQLException& e) {
        throw runtime_error("Error en la base de dades: " + string(e.what()));
    }
}

/*
bool CapaDeDomini::verificaCredencials(const string& sobrenom, const string& contrasenya) {
    try {
        DTOUsuari usuari = consultaUsuari(sobrenom);
        return usuari.obteContrasenya() == contrasenya;
    } catch (const runtime_error& e) {
        return false; // Si el usuario no existe, retorna false.
    }
}
*/

DTOUsuari CapaDeDomini::consultaUsuari(string sobrenom_usuari) {
    CercadoraUsuari usuari;
    PassarelaUsuari usu = usuari.cercaPerSobrenom(sobrenom_usuari);
    return DTOUsuari(usu);
}

void CapaDeDomini::modificaUsuari(){}
void CapaDeDomini::esborraUsuari(const string& contrasenyaU) {
    try {
        TxEsborrarUsuari tx(contrasenyaU);
        tx.executar();  // Ejecutar la transacción
    }
    catch (const exception& e) {
        throw;  // Propagar el error a la capa de presentación
    }
}

//Visualitzacio Continguts
DTOPelicula CapaDeDomini::consultaPelicula(const string& titolPelicula) {
    CercadoraPelicula cercador;
    PassarelaPelicula pelicula = cercador.cercaPerTitol(titolPelicula);

    // Retorna un DTO basado en la película encontrada
    return DTOPelicula(pelicula.getTitol(), pelicula.getDescripcio(),
        pelicula.getQualificacio(), pelicula.getDuracio(),
        pelicula.getDataEstrena());
}

void CapaDeDomini::registreVisualitzacio(const string& titolPelicula) {
    PassarelaVisualitzacio visualitzacio(titolPelicula);
    visualitzacio.registra();
}

vector<DTOPelicula> CapaDeDomini::consultaRelacionades(const string& titolPelicula) {
    CercadoraPelicula cercador;
    vector<PassarelaPelicula> pelisRelacionades = cercador.cercaRelacionades(titolPelicula);

    vector<DTOPelicula> resultats;
    for (const PassarelaPelicula& peli : pelisRelacionades) {
        resultats.emplace_back(peli.getTitol(), peli.getDescripcio(),
            peli.getQualificacio(), peli.getDuracio(),
            peli.getDataEstrena());
    }
    return resultats;
}
