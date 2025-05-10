#include "Proveedor.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Proveedor::agregar(vector<Proveedor>& lista) {
    Proveedor nuevo;
    cout << "\n--- AGREGAR PROVEEDOR ---\n";
    cout << "ID: ";
    cin >> nuevo.id;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nuevo.nombre);
    cout << "Teléfono: ";
    getline(cin, nuevo.telefono);

    lista.push_back(nuevo);
    guardarEnArchivo(lista);
}

void Proveedor::mostrar(const vector<Proveedor>& lista) {
    cout << "\n--- LISTA DE PROVEEDORES ---\n";
    for (const auto& prov : lista) {
        cout << "ID: " << prov.id
             << " | Nombre: " << prov.nombre
             << " | Tel: " << prov.telefono << "\n";
    }
}

void Proveedor::modificar(vector<Proveedor>& lista) {
    string id;
    cout << "\nIngrese ID del proveedor a modificar: ";
    cin >> id;

    auto it = find_if(lista.begin(), lista.end(),
        [&id](const Proveedor& p) { return p.id == id; });

    if (it != lista.end()) {
        cout << "Nuevo nombre: ";
        cin.ignore();
        getline(cin, it->nombre);
        cout << "Nuevo teléfono: ";
        getline(cin, it->telefono);
        guardarEnArchivo(lista);
    } else {
        cout << "Proveedor no encontrado.\n";
    }
}

void Proveedor::eliminar(vector<Proveedor>& lista) {
    string id;
    cout << "\nIngrese ID del proveedor a eliminar: ";
    cin >> id;

    auto it = find_if(lista.begin(), lista.end(),
        [&id](const Proveedor& p) { return p.id == id; });

    if (it != lista.end()) {
        lista.erase(it);
        guardarEnArchivo(lista);
        cout << "Proveedor eliminado!\n";
    } else {
        cout << "Proveedor no encontrado.\n";
    }
}

void Proveedor::guardarEnArchivo(const vector<Proveedor>& lista) {
    ofstream archivo("Proveedores.txt");
    for (const auto& prov : lista) {
        archivo << prov.id << "," << prov.nombre << "," << prov.telefono << "\n";
    }
    archivo.close();
}

void Proveedor::cargarDesdeArchivo(vector<Proveedor>& lista) {
    ifstream archivo("Proveedores.txt");
    string linea;
    while (getline(archivo, linea)) {
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            Proveedor prov;
            prov.id = linea.substr(0, pos1);
            prov.nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            prov.telefono = linea.substr(pos2 + 1);
            lista.push_back(prov);
        }
    }
    archivo.close();
};
