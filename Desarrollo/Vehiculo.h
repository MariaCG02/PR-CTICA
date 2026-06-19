#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>
using namespace std;

struct Vehiculo {
    string id;
    string marca;
    string modelo;
    int anio;
    string placa;
    string idTitular;

    // Muestra los datos del vehiculo
    void mostrar() const {
        cout << "\n--- Vehiculo ---\n";
        cout << "ID: " << id << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio: " << anio << endl;
        cout << "Placa: " << placa << endl;
        cout << "ID del titular: " << idTitular << endl;
    }

    // Modifica los datos del vehiculo
    void modificar() {
        cout << "Nueva marca: ";
        getline(cin, marca);

        cout << "Nuevo modelo: ";
        getline(cin, modelo);

        cout << "Nuevo anio: ";
        cin >> anio;
        cin.ignore();

        cout << "Nueva placa: ";
        getline(cin, placa);

        cout << "Nuevo ID del titular: ";
        getline(cin, idTitular);
    }
};

#endif