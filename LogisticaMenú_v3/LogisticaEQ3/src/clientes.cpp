#include "clientes.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;using namespace std;

// Implementación de métodos CRUD
void Clientes::agregar(vector<Clientes>& lista) {
    Clientes nuevo;
    cout << "\n--- AGREGAR CLIENTE ---\n";
    cout << "ID: ";
    cin >> nuevo.id;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nuevo.nombre);
    cout << "Dirección: ";
    getline(cin, nuevo.direccion);

    lista.push_back(nuevo);
    cout << "Cliente agregado exitosamente!\n";
}

void Clientes::mostrar(const vector<Clientes>& lista) {
    cout << "\n--- LISTA DE CLIENTES ---\n";
    for (const auto& cliente : lista) {
        cout << "ID: " << cliente.id
             << " | Nombre: " << cliente.nombre
             << " | Dirección: " << cliente.direccion << "\n";
    }
}

void Clientes::modificar(vector<Clientes>& lista) {
    string id;
    cout << "\n--- MODIFICAR CLIENTE ---\n";
    cout << "Ingrese ID del cliente a modificar: ";
    cin >> id;

    auto it = find_if(lista.begin(), lista.end(),
        [&id](const Clientes& c) { return c.id == id; });

    if (it != lista.end()) {
        cout << "Nuevo nombre: ";
        cin.ignore();
        getline(cin, it->nombre);
        cout << "Nueva dirección: ";
        getline(cin, it->direccion);
        cout << "Cliente modificado!\n";
    } else {
        cout << "Cliente no encontrado.\n";
    }
}

void Clientes::eliminar(vector<Clientes>& lista) {
    string id;
    cout << "\n--- ELIMINAR CLIENTE ---\n";
    cout << "Ingrese ID del cliente a eliminar: ";
    cin >> id;

    auto it = find_if(lista.begin(), lista.end(),
        [&id](const Clientes& c) { return c.id == id; });

    if (it != lista.end()) {
        lista.erase(it);
        cout << "Cliente eliminado!\n";
    } else {
        cout << "Cliente no encontrado.\n";
    }
}

// Guarda clientes en archivo
void Clientes::guardarEnArchivo(const vector<Clientes>& lista) {
    ofstream archivo("ListaClientes.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escritura!\n";
        return;
    }

    for (const auto& cliente : lista) {
        archivo << cliente.id << ","
                << cliente.nombre << ","
                << cliente.direccion << "\n";
    }
    archivo.close();
    cout << "Datos guardados en 'ListaClientes.txt'\n";
}

// Carga clientes desde archivo
void Clientes::cargarDesdeArchivo(vector<Clientes>& lista) {
    ifstream archivo("ListaClientes.txt");
    if (!archivo.is_open()) {
        cerr << "No existe el archivo de clientes (se creará uno nuevo)\n";
        return;
    }

    lista.clear(); // Limpiar lista actual
    string linea;
    while (getline(archivo, linea)) {
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            Clientes cliente;
            cliente.id = linea.substr(0, pos1);
            cliente.nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            cliente.direccion = linea.substr(pos2 + 1);
            lista.push_back(cliente);
        }
    }
    archivo.close();
    cout << "Datos cargados desde 'ListaClientes.txt'\n";
}
