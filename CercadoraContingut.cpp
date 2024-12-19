#include "CercadoraContingut.h"
#include <iostream>
#include <memory>
#include <stdexcept>

std::vector<DTOPelicula> CercadoraContingut::cercaProperesPelicules(const string& modalitat) {
    std::vector<DTOPelicula> resultats;
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    string query = R"(
        SELECT c.titol, c.descripcio, c.qualificacio, p.data_estrena, p.duracio
        FROM Contingut c
        JOIN Pelicula p ON c.titol = p.titol
        WHERE p.data_estrena > NOW()
    )";

    if (!modalitat.empty()) {
        query += " AND EXISTS (SELECT 1 FROM Usuari u WHERE u.subscripcio = '" + modalitat + "')";
    }

    unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));
    while (res->next()) {
        resultats.emplace_back(
            res->getString("titol"),
            res->getString("descripcio"),
            res->getString("qualificacio"),
            res->getString("data_estrena"),
            res->getInt("duracio")
        );
    }

    return resultats;
}

vector<DTOSerie> CercadoraContingut::cercaProperesSeries(const string& modalitat) {
    vector<DTOSerie> resultats;
    ConnexioBD& connexio = *ConnexioBD::getInstance();

    string query = R"(
        SELECT c.titol, c.descripcio, c.qualificacio, MIN(cap.data_estrena) AS data_estrena, COUNT(cap.numero) AS total_capitols
        FROM Contingut c
        JOIN Serie s ON c.titol = s.titol
        JOIN Capitol cap ON s.titol = cap.titol_serie
        WHERE cap.data_estrena > NOW()
        GROUP BY c.titol, c.descripcio, c.qualificacio
    )";

    if (!modalitat.empty()) {
        query += " AND EXISTS (SELECT 1 FROM Usuari u WHERE u.subscripcio = '" + modalitat + "')";
    }

    unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));
    while (res->next()) {
        resultats.emplace_back(
            res->getString("titol"),
            res->getString("descripcio"),
            res->getString("qualificacio"),
            res->getString("data_estrena"),
            res->getInt("total_capitols")
        );
    }

    return resultats;
}

DTOPelicula CercadoraContingut::cercaPelicula(const std::string& titol) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    std::string query =
        "SELECT c.titol, c.descripcio, c.qualificacio, p.data_estrena, p.duracio "
        "FROM Contingut c "
        "JOIN Pelicula p ON c.titol = p.titol "
        "WHERE c.titol = '" + titol + "' AND c.tipus = 'pelicula'";
    unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));

    if (res->next()) {
       return DTOPelicula(
            res->getString("titol"),
            res->getString("descripcio"),
            res->getString("qualificacio"),
            res->getString("data_estrena"),
            res->getInt("duracio")
        );
    }
    throw std::runtime_error("Pelicula no trobada: " + titol);
}

std::vector<DTOPelicula> CercadoraContingut::cercaRelacionades(const std::string& titol) {
    ConnexioBD& connexio = *ConnexioBD::getInstance();
    std::string query =
        "SELECT c.titol, c.descripcio, c.qualificacio, p.data_estrena, p.duracio "
        "FROM Contingut c NATURAL JOIN Pelicula p "
        "WHERE c.titol IN ("
        "    SELECT titol_y FROM relacionat WHERE titol_x = '" + titol + "' "
        "    UNION "
        "    SELECT titol_x FROM relacionat WHERE titol_y = '" + titol + "'"
        ")";
    unique_ptr<sql::ResultSet> res(connexio.consultaSQL(query));

    std::vector<DTOPelicula> relacionades;
    while (res->next()) {
        relacionades.emplace_back(
            res->getString("titol"),
            res->getString("descripcio"),
            res->getString("qualificacio"),
            res->getString("data_estrena"),
            res->getInt("duracio")
        );
    }
    return relacionades;
}


