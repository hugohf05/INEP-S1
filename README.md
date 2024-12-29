# Proyecto INEP

Este proyecto conecta una aplicación C++ con una base de datos MySQL utilizando la clase `ConnexioBD`. Los datos sensibles, como la dirección del servidor, el usuario y la contraseña, son leídos desde un archivo de configuración para mejorar la seguridad.

## Requisitos

- C++17 o superior.
- Biblioteca MySQL Connector/C++.
- Biblioteca JSON para C++ (nlohmann/json).

## Instalación de Dependencias

1. Asegúrate de tener las siguientes bibliotecas instaladas:
    - **MySQL Connector/C++**: [Enlace a MySQL](https://dev.mysql.com/downloads/connector/cpp/)
    - **nlohmann/json**: [GitHub de nlohmann/json](https://github.com/nlohmann/json)

2. Instala las bibliotecas necesarias a través de `vcpkg` o `conan` o descárgalas manualmente y configura el proyecto.

3. Para instalar la biblioteca nlohmann/json en Windows, aquí te guiaré paso a paso usando vcpkg, que es una herramienta muy popular para gestionar dependencias en proyectos C++ en Windows.

4.  Instalar vcpkg en Windows
Clonar el repositorio de vcpkg:

Abre una terminal (como PowerShell o Símbolo del sistema) y clona el repositorio de vcpkg:

git clone https://github.com/microsoft/vcpkg.git

5. Compilar vcpkg:
cd vcpkg

Ahora, ejecuta el script de construcción para compilar vcpkg:

.\bootstrap-vcpkg.bat

Este comando descargará las dependencias necesarias y compilará vcpkg.

6. Integrar vcpkg con Visual Studio (opcional pero recomendado):

Si estás usando Visual Studio, es útil integrar vcpkg para que el IDE lo reconozca automáticamente y configure las rutas de inclusión.

Ejecuta:

.\vcpkg integrate install

Esto hará que las bibliotecas gestionadas por vcpkg se encuentren automáticamente en tu proyecto de Visual Studio.

7. Instalar nlohmann/json usando vcpkg

Una vez que tienes vcpkg instalado, puedes usarlo para instalar la biblioteca nlohmann/json.

Instalar la biblioteca:

Ejecuta el siguiente comando en la misma terminal donde tienes vcpkg:

.\vcpkg install nlohmann-json

Esto descargará, compilará y configurará la biblioteca nlohmann/json para tu sistema.

8. Verificar la instalación:

Después de instalar la biblioteca, puedes verificar que se haya instalado correctamente mediante el siguiente comando:

.\vcpkg list

Este comando mostrará una lista de las bibliotecas instaladas. Deberías ver nlohmann-json en la lista.
