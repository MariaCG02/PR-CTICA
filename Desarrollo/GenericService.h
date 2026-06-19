#ifndef GENERIC_SERVICE_H
#define GENERIC_SERVICE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class GenericService {
public:
    static bool idValido(const string& id);
    static bool idRepetido(const vector<T>& registro, const string& id);

    static void agregar(vector<T>& registro, T nuevoElemento);
    static void mostrar(const vector<T>& registro);
    static void buscar(const vector<T>& registro, const string& id);
    static void eliminar(vector<T>& registro, const string& id);
    static void modificar(vector<T>& registro, const string& id);
};

// Valida que el ID tenga formato COD + 3 numeros
template <typename T>
bool GenericService<T>::idValido(const string& id) {
    if (id.length() != 6) return false;
    if (id.substr(0, 3) != "COD") return false;

    for (int i = 3; i < 6; i++) {
        if (!isdigit(id[i])) return false;
    }

    return true;
}

// Verifica si el ID ya existe
template <typename T>
bool GenericService<T>::idRepetido(const vector<T>& registro, const string& id) {
    for (const T& elemento : registro) {
        if (elemento.id == id) {
            return true;
        }
    }
    return false;
}

// Agrega un registro nuevo
template <typename T>
void GenericService<T>::agregar(vector<T>& registro, T nuevoElemento) {
    if (!idValido(nuevoElemento.id)) {
        cout << "Error: el ID debe tener formato COD001.\n";
        return;
    }

    if (idRepetido(registro, nuevoElemento.id)) {
        cout << "Error: ese ID ya esta registrado.\n";
        return;
    }

    registro.push_back(nuevoElemento);
    cout << "Registro agregado correctamente.\n";
}

// Muestra todos los registros
template <typename T>
void GenericService<T>::mostrar(const vector<T>& registro) {
    if (registro.empty()) {
        cout << "No hay registros guardados.\n";
        return;
    }

    for (const T& elemento : registro) {
        elemento.mostrar();
    }
}

// Busca un registro por ID
template <typename T>
void GenericService<T>::buscar(const vector<T>& registro, const string& id) {
    for (const T& elemento : registro) {
        if (elemento.id == id) {
            cout << "\nRegistro encontrado:\n";
            elemento.mostrar();
            return;
        }
    }

    cout << "No se encontro ningun registro con ese ID.\n";
}

// Elimina un registro por ID
template <typename T>
void GenericService<T>::eliminar(vector<T>& registro, const string& id) {
    for (int i = 0; i < registro.size(); i++) {
        if (registro[i].id == id) {
            registro.erase(registro.begin() + i);
            cout << "Registro eliminado correctamente.\n";
            return;
        }
    }

    cout << "No se encontro ningun registro con ese ID.\n";
}

// Modifica un registro por ID
template <typename T>
void GenericService<T>::modificar(vector<T>& registro, const string& id) {
    for (T& elemento : registro) {
        if (elemento.id == id) {
            elemento.modificar();
            cout << "Registro modificado correctamente.\n";
            return;
        }
    }

    cout << "No se encontro ningun registro con ese ID.\n";
}

#endif