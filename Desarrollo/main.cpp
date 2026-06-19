#include <iostream>
#include <vector>
#include <string>

#include "GenericService.h"
#include "Vehiculo.h"
#include "Titular.h"
#include "Cita.h"
#include "Servicio.h"

using namespace std;

void limpiar() {
    cin.ignore();
}

Vehiculo capturarVehiculo() {
    Vehiculo v;

    cout << "ID del vehiculo: ";
    getline(cin, v.id);
    cout << "Marca: ";
    getline(cin, v.marca);
    cout << "Modelo: ";
    getline(cin, v.modelo);
    cout << "Anio: ";
    cin >> v.anio;
    limpiar();
    cout << "Placa: ";
    getline(cin, v.placa);
    cout << "ID del titular: ";
    getline(cin, v.idTitular);

    return v;
}

Titular capturarTitular() {
    Titular t;

    cout << "ID del titular: ";
    getline(cin, t.id);
    cout << "Nombre: ";
    getline(cin, t.nombre);
    cout << "Telefono: ";
    getline(cin, t.telefono);
    cout << "Correo: ";
    getline(cin, t.correo);
    cout << "Direccion: ";
    getline(cin, t.direccion);

    return t;
}

Cita capturarCita() {
    Cita c;

    cout << "ID de la cita: ";
    getline(cin, c.id);
    cout << "ID del vehiculo: ";
    getline(cin, c.idVehiculo);
    cout << "ID del titular: ";
    getline(cin, c.idTitular);
    cout << "Fecha: ";
    getline(cin, c.fecha);
    cout << "Motivo: ";
    getline(cin, c.motivo);
    cout << "Estado: ";
    getline(cin, c.estado);

    return c;
}

Servicio capturarServicio() {
    Servicio s;

    cout << "ID del servicio: ";
    getline(cin, s.id);
    cout << "ID de la cita: ";
    getline(cin, s.idCita);
    cout << "ID del vehiculo: ";
    getline(cin, s.idVehiculo);
    cout << "Tipo de servicio: ";
    getline(cin, s.tipoServicio);
    cout << "Costo: ";
    cin >> s.costo;
    limpiar();
    cout << "Tecnico: ";
    getline(cin, s.tecnico);

    return s;
}

template <typename T>
void menuRegistro(vector<T>& registro, string nombre) {
    int opcion;
    string id;

    do {
        cout << "\n--- MENU " << nombre << " ---\n";
        cout << "1. Agregar\n";
        cout << "2. Mostrar\n";
        cout << "3. Buscar\n";
        cout << "4. Eliminar\n";
        cout << "5. Modificar\n";
        cout << "6. Regresar\n";
        cout << "Opcion: ";
        cin >> opcion;
        limpiar();

        switch (opcion) {
        case 1:
            if (nombre == "VEHICULOS")
                GenericService<T>::agregar(registro, capturarVehiculo());
            else if (nombre == "TITULARES")
                GenericService<T>::agregar(registro, capturarTitular());
            else if (nombre == "CITAS")
                GenericService<T>::agregar(registro, capturarCita());
            else if (nombre == "SERVICIOS")
                GenericService<T>::agregar(registro, capturarServicio());
            break;

        case 2:
            GenericService<T>::mostrar(registro);
            break;

        case 3:
            cout << "ID a buscar: ";
            getline(cin, id);
            GenericService<T>::buscar(registro, id);
            break;

        case 4:
            cout << "ID a eliminar: ";
            getline(cin, id);
            GenericService<T>::eliminar(registro, id);
            break;

        case 5:
            cout << "ID a modificar: ";
            getline(cin, id);
            GenericService<T>::modificar(registro, id);
            break;

        case 6:
            cout << "Regresando...\n";
            break;

        default:
            cout << "Opcion no valida.\n";
        }

    } while (opcion != 6);
}

int main() {
    vector<Vehiculo> vehiculos;
    vector<Titular> titulares;
    vector<Cita> citas;
    vector<Servicio> servicios;

    int opcion;

    do {
        cout << "\n===== AGENCIA AUTOMOTRIZ =====\n";
        cout << "1. Vehiculos\n";
        cout << "2. Titulares\n";
        cout << "3. Citas\n";
        cout << "4. Servicios\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        limpiar();

        switch (opcion) {
        case 1:
            menuRegistro(vehiculos, "VEHICULOS");
            break;
        case 2:
            menuRegistro(titulares, "TITULARES");
            break;
        case 3:
            menuRegistro(citas, "CITAS");
            break;
        case 4:
            menuRegistro(servicios, "SERVICIOS");
            break;
        case 5:
            cout << "Programa finalizado.\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }

    } while (opcion != 5);

    return 0;
}