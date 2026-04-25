#include <iostream>
#include <mysql.h>       
using namespace std;

int main() {
    MYSQL* conn;
    conn = mysql_init(0);
    if (!mysql_real_connect(conn, "localhost", "root", "admin", "nexus_academy", 3306, NULL, 0)){
    cout << "Error de conexion" << endl;
    return 0;
    }
    
    MYSQL_RES* resultado;
    MYSQL_ROW  fila;

    while (true) {
        int opcion;
        string consulta;
        cout << "ANAISIS DE RENDIMIENTO" << endl;
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

            cout << "Mejores Notas" << endl;
            while ((fila = mysql_fetch_row(resultado)) != NULL) {
            cout << fila[0] << " - " << fila[1] << " - " << fila[2] << fila[3] << " - Nota: " << fila[4] << endl;
            }
            mysql_free_result(resultado);
            break;
    
        case 2:
            consulta = "SELECT id, nombre, apellido, celular, nota_final FROM alumnos ORDER BY nota_final ASC LIMIT 5";
            mysql_query(conn, consulta.c_str());
            resultado = mysql_store_result(conn);

            cout << "Notas bajas" << endl;
            while ((fila = mysql_fetch_row(resultado)) != NULL) {
            cout << fila[0] << " - " << fila[1] <<  " - " << fila[2] << fila[3] << " - Nota: " << fila[3] << endl;
            }
            mysql_free_result(resultado);
            break;
        } 
    }
    return 0;
}