#include <iostream>
#include <mysql.h>

using namespace std;

    MYSQL* conn;
    void conectar() {
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "TEAMOAKIVA369", "nexus_academy", 3306, NULL, 0);

    if (conn) {
        cout << "CONEXION EXITOSA" << endl;
    } else {
        cout << "ERROR DE MYSQL" << mysql_error(conn) << endl;
    }
}
// Buscador
void buscarAlumno() {
    int id;
    cout << "Ingrese ID del alumno: ";
    cin >> id;

    string consulta = "SELECT * FROM alumnos WHERE id = " + to_string(id);

    if (mysql_query(conn, consulta.c_str())) {
        cout << "Error en la consulta: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES *resultado = mysql_store_result(conn);
    MYSQL_ROW fila;

    fila = mysql_fetch_row(resultado);

    if (fila != NULL) {
        cout << "--- DATOS DEL ALUMNO ---"<< endl;
        cout << "ID: " << fila[0] << endl;
        cout << "Nombre: " << fila[1] << " " << fila[2] << endl;
        cout << "Celular: " << fila[3] << endl;
        cout << "Nota Final: " << fila[4] << endl;
    } else {
        cout << "Alumno no encontrado";
    }

    mysql_free_result(resultado);
}

int main() {
    conectar();

    if (conn != NULL) {
        buscarAlumno();
        mysql_close(conn);
    }

    return 0;
}