#include <iostream>
#include <mysql.h>

using namespace std;

// Actualizar nota
void nota()
{
    float nuevanota;
    int id;

    cout << "Ingrese ID del Alumno: ";
    cin >> id;

    cout << "Ingrese Nueva Nota: ";
    cin >> nuevanota;

    string query = "UPDATE alumnos SET nota_final = " + to_string(nuevanota) +
                   " WHERE id = " + to_string(id);

    if (mysql_query(conn, query.c_str()) == 0)
    {
        cout << "Nota Actualizada" << endl;
    }
    else
    {
        cout << "Error al Actualizar Nota: " << mysql_error(conn) << endl;
    }
    " WHERE id = " + to_string(id);
}

void celular()
{
    int celular;
    cout << "Ingrese ID del Alumno" << endl;
    cin >> id;

    cout << "Ingrese Nuevo Celular" << endl;
    cin >> celular;

    string query = "UPDATE alumnos SET celular =" + celular + " WHERE id = " + to_string(id);

    if (msyql_query(conn, query.c_str()) == 0)
    {
        cout << "Celular Actualizado";
    }
    else
    {
        cout << "Error al Actualizar Celular";
    }

    return 0;
}