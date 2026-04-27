#include <iostream>
#include <mysql.h>
using namespace std;
MYSQL* conn;

void buscarAlumno();
void analisisRendimiento();
void actualizarNota();
void actualizarCelular();
bool loginDocente();

int main() {
//Conectamos a la base de datos
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "TEAMOAKIVA369", "nexus_academy", 3306, NULL, 0);
    if (conn) {
        cout << "CONEXION EXITOSA" << endl;
    } else {
        cout << "ERROR DE MYSQL" << mysql_error(conn) << endl;
        return 1;
    }
    //Menu
     int x = 0;
    while (x != 5) {
        cout << "BIENVENIDO A NEXUS ACADEMY" << endl;
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Buscar alumno" << endl;
        cout << "2. Analisis de rendimiento" << endl;
        cout << "3. Actualizacion de nota" << endl;
        cout << "4. Actualizacion de celular" << endl;
        cout << "5. Salir" << endl;
        cin >> x;

        switch (x) {
            case 1: buscarAlumno(); break; 
            case 2: analisisRendimiento(); break;
            case 3:  if (loginDocente()) 
            {actualizarNota();} break;
            case 4: actualizarCelular(); break;
            case 5: cout << "Saliendo" << endl; break;
            default: cout << "Opcion no valida" << endl; break;
        }
    }
//Cerramos la conexion
    mysql_close(conn);
    return 0;
}    
bool loginDocente() {
    string user;
    string pass;

    cout << "Usuario: " << endl;
    cin >> user;

    cout << "Password: " << endl;
    cin >> pass;

    if (user == "docente" && pass == "1234") {
        cout << "Acceso concedido" << endl;
        return true;
    } else {
        cout << "Acceso denegado" << endl;
        return false;
    }
}
// Buscador
void buscarAlumno() {
    int id; 
    cout << "Ingrese ID del alumno: "; 
    cin >> id;
    string consulta = "SELECT id, nombre, apellido, celular, nota_final FROM alumnos WHERE id = " + to_string(id);

    if (mysql_query(conn, consulta.c_str())) {
        cout << "Error" << endl;
        return;
    }
    MYSQL_RES* resultado = mysql_store_result(conn);
    MYSQL_ROW fila;
    fila = mysql_fetch_row(resultado);
    if (fila != NULL)
 {
        cout << "DATOS DEL ALUMNO" << endl;
        cout << "ID: " << fila[0] << endl;
        cout << "Nombre: " << fila[1] << " " << fila[2] << endl;
        cout << "Celular: " << fila[3] << endl;
        cout << "Nota Final: " << fila[4] << endl;
    } 
else { cout << "Error" << endl; }
    mysql_free_result(resultado);
}
// Analisis de Rendimiento
void analisisRendimiento() {
    MYSQL_RES* resultado;
    MYSQL_ROW  fila;
    while (true) {
        int opcion;
        string consulta;
        cout << "ANALISIS DE RENDIMIENTO" << endl;
        cout << "1. Cuadro de honor" << endl;
        cout << "2. Alumnos en riesgo" << endl;
        cout << "3. Atras" << endl;
        cin >> opcion;
        if (opcion == 3) {
            cout << "Saliendo del analisis de rendimiento" << endl;
            break; 
        }
        switch (opcion) {
        case 1:
            consulta = "SELECT id, nombre, apellido, celular, nota_final FROM alumnos ORDER BY nota_final DESC LIMIT 5";
            mysql_query(conn, consulta.c_str());
            resultado = mysql_store_result(conn);
            cout << "Cuadro de honor" << endl;
            while ((fila = mysql_fetch_row(resultado)) != NULL) {
            cout << fila[0] << " - " << fila[1] << " - " << fila[2] << " - " << fila[3] << " - Nota: " << fila[4] << endl;
            }
            mysql_free_result(resultado);
            break;

        case 2:
            consulta = "SELECT id, nombre, apellido, celular, nota_final FROM alumnos ORDER BY nota_final ASC LIMIT 5";
            mysql_query(conn, consulta.c_str());
            resultado = mysql_store_result(conn);

            cout << "Alumnos en riesgo" << endl;
            while ((fila = mysql_fetch_row(resultado)) != NULL) {
            cout << fila[0] << " - " << fila[1] <<  " - " << fila[2] << " - " << fila[3] << " - Nota: " << fila[4] << endl;
            }
            mysql_free_result(resultado);
            break;
        } 
    }
}

// Actualizar nota
void actualizarNota()
{
    float nuevanota; 
    int id; 

    cout << "Ingrese ID del alumno: "<< endl;
    cin >> id;

    cout << "Ingrese Nueva Nota: "<< endl;
    cin >> nuevanota;

    string query = "UPDATE alumnos SET nota_final = " + to_string(nuevanota) +
                   " WHERE id = " + to_string(id);

    if (mysql_query(conn, query.c_str()) == 0)
    {
        cout << "Nota actualizada" << endl;
    }
    else
    {
        cout << "Error al actualizar nota" << mysql_error(conn) << endl;
    }
}

// Actualizar celular
void actualizarCelular()
{
    string celular;
    int id; 

    cout << "Ingrese ID del alumno" << endl;
    cin >> id;

    cout << "Ingrese nuevo celular" << endl;
    cin >> celular;

    string query = "UPDATE alumnos SET celular = '" + celular + "' WHERE id = " + to_string(id);

    if (mysql_query(conn, query.c_str()) == 0)
    {
        cout << "Celular actualizado" << endl;
    }
    else
    {
        cout << "Error al actualizar celular" << mysql_error(conn) << endl;
    }
}