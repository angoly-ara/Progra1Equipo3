#include "MenuProveedores.h"
#include <iostream>
using namespace std;

void MenuProveedores::mostrar(vector<Proveedor>& lista, usuarios& usuarioActual) {
    int opcion;
    do {
        system("cls");
        cout << "\t\t=== MENÚ PROVEEDORES ===\n"
             << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
             << "\t\t1. Agregar proveedor\n"
             << "\t\t2. Mostrar proveedores\n"
             << "\t\t3. Modificar proveedor\n"
             << "\t\t4. Eliminar proveedor\n"
             << "\t\t5. Volver\n"
             << "\t\t========================\n"
             << "\t\tIngrese opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: Proveedor::agregar(lista); break;
            case 2: Proveedor::mostrar(lista); break;
            case 3: Proveedor::modificar(lista); break;
            case 4: Proveedor::eliminar(lista); break;
            case 5: return;
            default: cout << "Opción inválida\n";
        }
        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
    } while(opcion != 5);
}
