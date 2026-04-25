#include <iostream>
#include <mysql.h>

using namespace std;

MYSQL *conn;
void conectar()
{
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "TEAMOAKIVA369", "nexus_academy", 3306, NULL, 0);

    if (conn)
    {
        cout << "CONEXION EXITOSA" << endl;
    }
    else
    {
        cout << "ERROR DE MYSQL" << mysql_error(conn) << endl;
    }
}

void nota()
{
    float nuevanota;
    int id;

    cout << "Ingrese ID del Alumno" << endl;
    cin >> id;

    cout << "Ingrese nueva nota" << endl;
    cin >> nuevanota;

    string query = " UPDATE alumnos SET nota_final = " + to_string(nuevanota) + " WHERE id = " + to_string(id);

    if (msyql_query(conn, query.c_str()) == 0)
    {
        cout << "Nota Actualizada";
    }
    else
    {
        cout << "Error al actualizar nota";
    }
    return 0;
}

void celular()
{
    int celular;
    int id;

    cout << "Ingrese ID del Alumno" << endl;
    cin >> id;

    cout << "Ingrese nuevo celular" << endl;
    cin >> celular;

    string query = " UPDATE alumnos SET celular = " + to_string(cel) + " WHERE id = " + to_string(id);

    if (msyql_query(conn, query.c_str()) == 0)
    {
        cout << "Celular Actualizado";
    }
    else
    {
        cout << "Error al actualizar celular";
    }

    return 0;
}