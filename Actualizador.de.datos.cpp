#include <iostream>
#include <mysql.h>

using namespace std;

int id;

// Actualizar nota
void actualizarNota()
{
    float nuevanota;
    int id;

    cout << "Ingrese ID del alumno: ";
    cin >> id;

    cout << "Ingrese nueva Nota: ";
    cin >> nuevanota;

    string query = "UPDATE alumnos SET nota_final = " + to_string(nuevanota) +
                   " WHERE id = " + to_string(id);

    if (mysql_query(conn, query.c_str()) == 0)
    {
        cout << "Nota actualizada" << endl;
    }
    else
    {
        cout << "Error al actualizar nota: " << mysql_error(conn) << endl;
    }
    " WHERE id = " + to_string(id);
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

    string query = "UPDATE alumnos SET celular ='" + celular + "' WHERE id = " + to_string(id);

    if (msyql_query(conn, query.c_str()) == 0)
    {
        cout << "Celular actualizado" << endl;
    }
    else
    {
        cout << "Error al actualizar celular" << endl;
    }

    return 0;
}