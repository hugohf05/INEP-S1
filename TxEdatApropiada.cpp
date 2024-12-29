#include "TxEdatApropiada.h"
#include "PetitFlix.h"
#include "DTOUsuari.h"
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"
#include "CercadoraContingut.h"

void TxEdatApropiada::executar() {
    // Obtener el usuario logueado
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari* usuariLoggejat = petitFlix.obtenirUsuariLoggejat();
    std::string sobrenomUsuari = usuariLoggejat->getSobrenom();

    // Buscar el usuario por su sobrenombre
    CercadoraUsuari Cercadora;
    PassarelaUsuari usuari = Cercadora.cercaPerSobrenom(sobrenomUsuari);
    std::string dataNaixement = usuari.getDataNaixement(); // Fecha de nacimiento del usuario

    // Verificar que la fecha de nacimiento no esté vacía
    std::cout << "Fecha de nacimiento obtenida: '" << dataNaixement << "'" << std::endl;

    if (dataNaixement.empty()) {
        std::cerr << "Error: No se obtuvo una fecha de nacimiento válida." << std::endl;
        return;  // Detener la ejecución si la fecha no es válida
    }

    // Calcular la edad del usuario
    int year, month, day;
    int result = sscanf(dataNaixement.c_str(), "%d-%d-%d", &year, &month, &day); // Ignora la parte de la hora
    if (result != 3) {
        std::cerr << "Error: No se pudo parsear la fecha de nacimiento correctamente." << std::endl;
        return;  // Detener la ejecución si la fecha no es válida
    }

    // Obtener la fecha actual
    time_t t = time(nullptr);
    struct tm* now = localtime(&t);

    // El año actual, mes y día
    int currentYear = now->tm_year + 1900;  // tm_year es los años desde 1900
    int currentMonth = now->tm_mon + 1;     // tm_mon es 0-11, por eso sumamos 1
    int currentDay = now->tm_mday;

    // Calcular la edad
    int edadUsuario = currentYear - year;

    // Si no ha cumplido años aún este año, restamos 1
    if (currentMonth < month || (currentMonth == month && currentDay < day)) {
        edadUsuario--;
    }

    // Mostrar la edad calculada
    std::cout << "Edad del usuario: " << edadUsuario << std::endl;

    // Aquí, asumimos que el título del contenido a consultar es:

    // Usamos la clase CercadoraContingut para buscar el contenido
    CercadoraContingut& cercadoraContingut = CercadoraContingut::getInstance();

    // Buscar la película o serie
    int edadMinima = -1; // Inicializamos la edad mínima a un valor no válido

    // Si no es una película, intentamos buscarlo como una serie
    DTOSerie serie = cercadoraContingut.cercaSerie(_titolContingut);

    if (serie.obteTitol() != "") {
        // Si encontramos la serie, obtenemos la "calificación" (edad mínima)
        std::string calificacion = serie.obteQualificacio();
        edadMinima = obtenerEdadMinima(calificacion);
        std::cout << edadMinima << std::endl;
    }

    if (edadMinima != -1) {
        // Si hemos encontrado la edad mínima, verificamos si la edad del usuario es adecuada
        if (edadUsuario >= edadMinima) {
            apte = true;
        }
        else {
            apte = false;
        }
    }
    else {
        // Si no encontramos el contenido en la base de datos
        std::cout << "El contenido '" << _titolContingut << "' no existe en la base de datos." << std::endl;
    }
}

// Función que convierte la calificación de edad a un valor numérico
int TxEdatApropiada::obtenerEdadMinima(const std::string& calificacion) {
    if (calificacion == "TP") {
        return 0; // Tots els publics
    }
    if (calificacion == "+3") {
        return 3;
    }
    if (calificacion == "+7") {
        return 7;
    }
    if (calificacion == "+12") {
        return 12;
    }
    if (calificacion == "+16") {
        return 16;
    }
    if (calificacion == "+18") {
        return 18;
    }
    return -1; // Si no se reconoce la calificación
}

bool TxEdatApropiada::obteResultat() {
	return apte;
}