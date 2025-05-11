#include "Producto.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Producto::agregar(vector<Producto>& lista) {
    Producto nuevo;
    cout << "\n--- AGREGAR PRODUCTO ---\n";
    cout << "Código: ";
    cin >> nuevo.codigo;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nuevo.nombre);
    cout << "Precio: ";
    cin >> nuevo.precio;
    cout << "Stock: ";
    cin >> nuevo.stock;

    lista.push_back(nuevo);
    guardarEnArchivo(lista);
}

void Producto::mostrar(const vector<Producto>& lista) {
    cout << "\n--- INVENTARIO DE PRODUCTOS ---\n";
    for (const auto& prod : lista) {
        cout << "Código: " << prod.codigo
             << " | Nombre: " << prod.nombre
             << " | Precio: Q" << prod.precio
             << " | Stock: " << prod.stock << "\n";
    }
}

void Producto::modificar(vector<Producto>& lista) {
    string codigo;
    cout << "\nIngrese código del producto a modificar: ";
    cin >> codigo;

    auto it = find_if(lista.begin(), lista.end(),
        [&codigo](const Producto& p) { return p.codigo == codigo; });

    if (it != lista.end()) {
        cout << "Nuevo nombre: ";
        cin.ignore();
        getline(cin, it->nombre);
        cout << "Nuevo precio: ";
        cin >> it->precio;
        cout << "Nuevo stock: ";
        cin >> it->stock;
        guardarEnArchivo(lista);
    } else {
        cout << "Producto no encontrado.\n";
    }
}

void Producto::eliminar(vector<Producto>& lista) {
    string codigo;
    cout << "\nIngrese código del producto a eliminar: ";
    cin >> codigo;

    auto it = find_if(lista.begin(), lista.end(),
        [&codigo](const Producto& p) { return p.codigo == codigo; });

    if (it != lista.end()) {
        lista.erase(it);
        guardarEnArchivo(lista);
        cout << "Producto eliminado!\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

void Producto::guardarEnArchivo(const vector<Producto>& lista) {
    ofstream archivo("Productos.txt");
    for (const auto& prod : lista) {
        archivo << prod.codigo << "," << prod.nombre << ","
                << prod.precio << "," << prod.stock << "\n";
    }
    archivo.close();
}

void Producto::cargarDesdeArchivo(vector<Producto>& lista) {
    ifstream archivo("Productos.txt");
    string linea;
    while (getline(archivo, linea)) {
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        size_t pos3 = linea.find(',', pos2 + 1);

        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
            Producto prod;
            prod.codigo = linea.substr(0, pos1);
            prod.nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            prod.precio = stod(linea.substr(pos2 + 1, pos3 - pos2 - 1));
            prod.stock = stoi(linea.substr(pos3 + 1));
            lista.push_back(prod);
        }
    }
    archivo.close();
}
