#ifndef SERVICIO_H
#define SERVICIO_H

#include <iostream>
#include <string>
using namespace std;

struct Servicio {
    string id;
    string idCita;
    string idVehiculo;
    string tipoServicio;
    double costo;
    string tecnico;

    // Muestra los datos del servicio
    void mostrar() const {
        cout << "\n--- Servicio ---\n";
        cout << "ID: " << id << endl;
        cout << "ID de la cita: " << idCita << endl;
        cout << "ID del vehiculo: " << idVehiculo << endl;
        cout << "Tipo de servicio: " << tipoServicio << endl;
        cout << "Costo: $" << costo << endl;
        cout << "Tecnico: " << tecnico << endl;
    }

    // Modifica los datos del servicio
    void modificar() {
        cout << "Nuevo ID de la cita: ";
        getline(cin, idCita);

        cout << "Nuevo ID del vehiculo: ";
        getline(cin, idVehiculo);

        cout << "Nuevo tipo de servicio: ";
        getline(cin, tipoServicio);

        cout << "Nuevo costo: ";
        cin >> costo;
        cin.ignore();

        cout << "Nuevo tecnico: ";
        getline(cin, tecnico);
    }
};

#endif