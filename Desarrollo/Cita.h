#ifndef CITA_H
#define CITA_H

#include <iostream>
#include <string>
using namespace std;

struct Cita {
    string id;
    string idVehiculo;
    string idTitular;
    string fecha;
    string motivo;
    string estado;

    // Muestra los datos de la cita
    void mostrar() const {
        cout << "\n--- Cita ---\n";
        cout << "ID: " << id << endl;
        cout << "ID del vehiculo: " << idVehiculo << endl;
        cout << "ID del titular: " << idTitular << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Motivo: " << motivo << endl;
        cout << "Estado: " << estado << endl;
    }

    // Modifica los datos de la cita
    void modificar() {
        cout << "Nuevo ID del vehiculo: ";
        getline(cin, idVehiculo);

        cout << "Nuevo ID del titular: ";
        getline(cin, idTitular);

        cout << "Nueva fecha: ";
        getline(cin, fecha);

        cout << "Nuevo motivo: ";
        getline(cin, motivo);

        cout << "Nuevo estado: ";
        getline(cin, estado);
    }
};

#endif