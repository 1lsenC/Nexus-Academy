# Titulo
Nexus Academy
## Objetivo
Este programa en C++ permite gestionar la informacion almacenda en una base datos MySQL. Incluye las funciones de busqueda de un alumno en especifico, analisis del rendimiento academico y la actualizacion de datos.
### Requisitos 
-Debe tener MySQL Server instalado(incluye las librerias).
-MySQL Server en `localhost`.
-La base de datos `nexus_academy` con la tabla `alumnos`.
-Visual Studio Code.
-Compilador C++(g++ o MSVC).
#### Base de datos
-Clonar o descargar el repositorio. 
-Crear la base de datos y luego la tabla en MySQL.
CREATE DATABASE nexus_academy;
USE nexus_academy;

CREATE TABLE alumnos (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(50),
    apellido VARCHAR(50),
    celular VARCHAR(20),
    nota_final FLOAT);

-Compilar la terminal en VS Code:
g++ main.cpp -o main.exe -lmysql
-Ejecutar:
En Windows el ejecutable sera main.exe
En Linux/Mac el ejecutable sera ./main
##### Uso de programa en C++
Al iniciar el programa muestra un menu principal:
1. Buscar alumno
-Solocita el ID y muestra los datos completos del alumno( ID, nombre, apellido, celular y nota final).
2. Analisis de rendimiento 
-Cuadro de honor: muestra los cinco alumnos con mejores notas.
-Alumnos en riesgo: muestra los alumnos con notas mas bajas.
3. Actualizacion de nota
-Para poder actualizar la nota le pedira al usuario su USUARIO y PASSWORD, si el acceso es concecido permitira modificar la nota final de un alumno.
-En USUARIO debe poner "docente", y en PASSWORD debe poner "1234".
4. Actualizacion de celular
-Permitira modificar el numero de celular de un alumno.
5. Salir
-Cierra el programa y la conexion a MySQL.

De la opcion 1 a 4 se le dejara volver al usuario al menu principal cuando termine de utlizar una opcion, teniedno la posibilidad de usar varias opciones con diferentes alumnos sin la necesidad de conectarse nuevamente al MySQL.

-----------------------------------------------------------------------------------------

Link de GitHub: https://github.com/1lsenC/Nexus-Academy/branches