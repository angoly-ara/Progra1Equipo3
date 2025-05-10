#include "MenuClientes.h"
#include "Clientes.h"  // Asegúrate que el archivo se llame Clientes.h (no Cliente.h)
#include <iostream>
using namespace std;

void MenuClientes::mostrar(vector<Clientes>& lista, usuarios& usuarioActual) {  // Cambiado Cliente por Clientes
    int opcion;
    do {
        system("cls");
        cout << "\t\t=== MENÚ CLIENTES ===\n"
             << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
             << "\t\t1. Agregar\n"
             << "\t\t2. Mostrar\n"
             << "\t\t3. Modificar\n"
             << "\t\t4. Eliminar\n"
             << "\t\t5. Volver\n";
        cin >> opcion;

        switch(opcion) {
            case 1: Clientes::agregar(lista); break;
            case 2: Clientes::mostrar(lista); break;
            case 3: Clientes::modificar(lista); break;
            case 4: Clientes::eliminar(lista); break;
            case 5: return;
        }
    } while(opcion != 5);
}
