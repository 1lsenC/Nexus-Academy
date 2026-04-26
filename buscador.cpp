// Buscador
void buscarAlumno() {
    int id;
    cout << "Ingrese ID del alumno: ";
    cin >> id;

    string consulta = "SELECT * FROM alumnos WHERE id = " + to_string(id);

    if (mysql_query(conn, consulta.c_str())) {
        cout << "Error" << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES *resultado = mysql_store_result(conn);
    MYSQL_ROW fila = mysql_fetch_row(resultado);

    if (fila != NULL) {
        cout << "DATOS DEL ALUMNO"<< endl;
        cout << "ID: " << fila[0] << endl;
        cout << "Nombre: " << fila[1] << " " << fila[2] << endl;
        cout << "Celular: " << fila[3] << endl;
        cout << "Nota Final: " << fila[4] << endl;
    }
    else { 
        cout << "Error"<< endl;
    }
    mysql_free_result(resultado);
    cout << "Presione cualquier tecla para volver al menu principal: ";
     cin.ignore();
     cin.get();
     consultasIndividuales();
}


    