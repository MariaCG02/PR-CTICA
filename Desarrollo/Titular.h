#ifndef TITULAR_H
#define TITULAR_H

#include <iostream>
#include <string>
using namespace std;

struct Titular {
    string id;
    string nombre;
    string telefono;
    string correo;
    string direccion;

    // Muestra los datos del titular
    void mostrar() const {
        cout << "\n--- Titular ---\n";
        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Correo: " << correo << endl;
        cout << "Direccion: " << direccion << endl;
    }

    // Modifica los datos del titular
    void modificar() {
        cout << "Nuevo nombre: ";
        getline(cin, nombre);

        cout << "Nuevo telefono: ";
        getline(cin, telefono);

        cout << "Nuevo correo: ";
        getline(cin, correo);

        cout << "Nueva direccion: ";
        getline(cin, direccion);
    }
};

#endif