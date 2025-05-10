#include "menuproductos.h"
#include "MenuProductos.h"
#include <iostream>
using namespace std;

void MenuProductos::mostrar(vector<Producto>& lista, usuarios& usuarioActual) {
    int opcion;
    do {
        system("cls");
        cout << "\t\t=== MENÚ PRODUCTOS ===\n"
             << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
             << "\t\t1. Agregar producto\n"
             << "\t\t2. Mostrar productos\n"
             << "\t\t3. Modificar producto\n"
             << "\t\t4. Eliminar producto\n"
             << "\t\t5. Volver\n"
             << "\t\t======================\n"
             << "\t\tIngrese opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: Producto::agregar(lista); break;
            case 2: Producto::mostrar(lista); break;
            case 3: Producto::modificar(lista); break;
            case 4: Producto::eliminar(lista); break;
            case 5: return;
            default: cout << "Opción inválida\n";
        }
        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
    } while(opcion != 5);
}
