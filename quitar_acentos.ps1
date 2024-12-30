# Reemplaza los acentos y caracteres especiales por sus equivalentes sin acento
function Quitar-Acentos {
    param([string]$rutaArchivo)

    # Leer el contenido del archivo con codificación UTF-8
    $contenido = Get-Content $rutaArchivo -Encoding UTF8

    # Reemplazar los acentos comunes y caracteres catalanes
    $contenido = $contenido -replace 'á', 'a' -replace 'é', 'e' -replace 'í', 'i' -replace 'ó', 'o' -replace 'ú', 'u'
    $contenido = $contenido -replace 'Á', 'A' -replace 'É', 'E' -replace 'Í', 'I' -replace 'Ó', 'O' -replace 'Ú', 'U'

    # Reemplazar acentos específicos del catalán
    $contenido = $contenido -replace 'à', 'a' -replace 'è', 'e' -replace 'í', 'i' -replace 'ò', 'o' -replace 'ù', 'u'
    $contenido = $contenido -replace 'À', 'A' -replace 'È', 'E' -replace 'Í', 'I' -replace 'Ò', 'O' -replace 'Ù', 'U'

    # También para la letra 'ç' y 'Ç'
    $contenido = $contenido -replace 'ç', 'c' -replace 'Ç', 'C'

    # Guardar el archivo modificado
    Set-Content -Path $rutaArchivo -Value $contenido -Force -Encoding UTF8
}

# Buscar y recorrer todos los archivos .cpp y .h en el directorio actual y subdirectorios
Get-ChildItem -Recurse -Include *.cpp, *.h | ForEach-Object {
    Quitar-Acentos $_.FullName
}
