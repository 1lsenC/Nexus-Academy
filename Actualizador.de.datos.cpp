#include <iostream>
#include <mysql.h>

using namespace std;

int id;

void nota()
{
    float nuevanota;

    cout << "Ingrese ID del Alumno" << endl;
    cin >> id;

    cout << "Ingrese nueva nota" << endl;
    cin >> nuevanota;

    string query = "UPDATE -basededatos- SET -nota- =" + string(nuevanota) + "WHERE id = " + to_string(id);

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
    cout << "Ingrese ID del Alumno" << endl;
    cin >> id;

    cout << "Ingrese nuevo celular" << endl;
    cin >> celular;

    string query = "UPDATE -basededatos- SET -celular- =" + celular + " WHERE id = " + to_string(id);

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