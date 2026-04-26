#include <iostream>

using namespace std;
// declarar
bool loginDocente;

// user docente
// contraseña 1234

bool loginDocente()
{
    string user;
    string pass;

    cout << "Usuario: " << endl;
    cin >> user;

    cout << "Password: " << endl;
    cin >> pass;

    if (user == "docente" && pass == "1234")
    {
        cout << "Acceso concedido" << endl;
        ;
        return true;
    }
    else
    {
        cout << "Acceso denegado" << endl;
        ;
        return false;
    }
}
