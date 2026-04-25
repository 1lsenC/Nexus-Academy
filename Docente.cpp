#include <iostream>

using namespace std;

// user docente
// contraseña 1234

void logindocente()
{
    string user;
    char pass;

    cout << "Usuario: " << endl;
    cin >> user;

    cout << "Password: " << endl;
    cin >> pass;

    if (user == "docente" && pass == "1234")
    {
        cout << "Acceso Consedido";
    }
    else
    {
        cout << "Acceso denegado" << endl;
    }
    return 0;
}
