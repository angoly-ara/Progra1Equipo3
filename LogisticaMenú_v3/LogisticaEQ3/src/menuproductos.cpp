#include "MenuProductos.h"
#include "Producto.h"
#include <iostream>
#include <limits>

using namespace std;

void MenuProductos::mostrar(vector<Producto>& listaProductos, usuarios& usuarioActual) {
    int opcion;
    string input;

    // Cargar productos al iniciar
    Producto::cargarDesdeArchivo(listaProductos);

    do {
        system("cls");
        cout << "\t\t=== MEN� PRODUCTOS ===\n"
             << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
             << "\t\t1. Agregar producto\n"
             << "\t\t2. Mostrar productos\n"
             << "\t\t3. Modificar producto\n"
             << "\t\t4. Eliminar producto\n"
             << "\t\t5. Volver al men� principal\n"
             << "\t\t======================\n"
             << "\t\tSeleccione una opci�n: ";

        // Validaci�n de entrada
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t\tEntrada inv�lida. Por favor ingrese un n�mero: ";
        }
        cin.ignore(); // Limpiar el buffer

        switch(opcion) {
            case 1:
                Producto::agregar(listaProductos, usuarioActual.getNombre());
                break;

            case 2:
                Producto::mostrar(listaProductos);
                break;

            case 3: {
                Producto::mostrar(listaProductos);
                if (!listaProductos.empty()) {
                    cout << "\n\t\tIngrese C�digo del producto a modificar: ";
                    getline(cin, input);

                    if (Producto::esCodigoValido(input)) {
                        Producto::modificar(listaProductos, usuarioActual.getNombre(), input);
                    } else {
                        cout << "\t\tC�digo no v�lido. Debe estar entre " << 3209
                             << " y " << 3259 << "\n";
                        system("pause");
                    }
                }
                break;
            }

            case 4: {
                Producto::mostrar(listaProductos);
                if (!listaProductos.empty()) {
                    cout << "\n\t\tIngrese C�digo del producto a eliminar: ";
                    getline(cin, input);

                    if (Producto::esCodigoValido(input)) {
                        Producto::eliminar(listaProductos, usuarioActual.getNombre(), input);
                    } else {
                        cout << "\t\tC�digo no v�lido. Debe estar entre " << 3209
                             << " y " << 3259 << "\n";
                        system("pause");
                    }
                }
                break;
            }

            case 5:
                // Guardar cambios al salir
                Producto::guardarEnArchivo(listaProductos);
                return;

            default:
                cout << "\t\tOpci�n no v�lida. Intente nuevamente.\n";
                system("pause");
        }
    } while (true);
}
