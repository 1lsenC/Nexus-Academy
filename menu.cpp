#include <iostream>
#include <mysql.h>
using namespace std;
MYSQL* conn;

void consultasIndividuales();
void buscarAlumno();
void analisisRendimiento();
void actualizarNota();
void actualizarCelular();

int main() {

    conn = mysql_init(0);
    if (!mysql_real_connect(conn, "localhost", "root", "admin", "nexus_academy", 3306, NULL, 0)) {
        cout << "Error de conexion" << endl;
        return 0;
    }

    int x = 0;
    while (x != 5) {
        cout << "NEXUS ACADEMY" << endl;
        cout << "MENU" << endl;
        cout << "1.Consultas individuales" << endl;
        cout << "2.Analisis de rendimiento" << endl;
        cout << "3.Actualizacion de datos" << endl;
        cout << "4.Actualizacion de nota" << endl;
        cout << "5.Saliendo..." << endl;
        cin >> x;

        switch (x) {
            case 1: buscarAlumno(); break; 
            case 2: analisisRendimiento(); break;
            case 3: actualizarNota(); break;
            case 4: actualizarCelular();
            case 5: cout << "Saliendo" << endl; break;
            default: cout << "Opcion no valida" << endl; break;
        }
    }
    mysql_close(conn);
    return 0;
} 

// Buscador


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
// Actuaizacion de Datos
