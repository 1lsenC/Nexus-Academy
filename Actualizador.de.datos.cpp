#include <iostream>
#include <mysql.h>

using namespace std;

MYSQL* conn;
int id;
    void conectar() {
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "TEAMOAKIVA369", "nexus_academy", 3306, NULL, 0);

    if (conn) {
        cout << "CONEXION EXITOSA" << endl;
    } else {
        cout << "ERROR DE MYSQL" << mysql_error(conn) << endl;
    }
}
// Actualizar nota
void nota() {
    float nuevanota;

    cout << "Ingrese ID del Alumno: ";
    cin >> id;

    cout << "Ingrese nueva nota: ";
    cin >> nuevanota;

    string query = "UPDATE alumnos SET nota_final = " + to_string(nuevanota) +
                   " WHERE id = " + to_string(id);

    if (mysql_query(conn, query.c_str()) == 0) {
        cout << "Nota actualizada" << endl;
    } else {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    " WHERE id = " + to_string(id);

    if (mysql_query(conn, query.c_str()) == 0) {
         cout << "Celular actualizado";
    } else {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    if (conn != NULL) {
        int opcion;
        cout << "1. Actualizar nota o 2. Actualizar celular" << endl;
        cout << "Elija opcion: " << endl;
        cin >> opcion;

        if (opcion == 1) {
            nota();
        } else if (opcion == 2) {
            celular();
        } else {
            cout << "Opcion invalida";
        }

        mysql_close(conn);
    }
    
    return 0;
}