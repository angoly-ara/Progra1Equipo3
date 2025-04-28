#include <iostream>
#include "usuarios.h"
#include "pedidos.h"
#include "inventario.h"
#include "envios.h"
#include "facturacion.h"
#include "reportes.h"
#include "bitacora.h"

using namespace std;

usuarios usuarioRegistrado;
bitacora auditoria;
Pedidos gestorPedidos;          // Instancia de la clase Pedidos
Inventario gestorInventario;    // Instancia de la clase Inventario
Envios gestorEnvios;            // Instancia de la clase Envios
Facturacion gestorFacturacion;  // Instancia de la clase Facturacion
Reportes gestorReportes;        // Instancia de la clase Reportes

void menuGeneral();

int main() {
    bool accessUsuarios;
    accessUsuarios = usuarioRegistrado.loginUsuarios();

    if (accessUsuarios) {
        menuGeneral();
    }

    system("cls");
    cout << "** Hasta la proxima **";
    return 0;
}

void menuGeneral() {
    int choice;
    do {
        system("cls");
        cout << "\t\t========================================" << endl;
        cout << "\t\t| SISTEMA DE GESTION LOGISTICA         |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t| Usuario: " << usuarioRegistrado.getNombre() << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Gestion de Pedidos" << endl;
        cout << "\t\t 2. Control de Inventario" << endl;
        cout << "\t\t 3. Envios y Transportes" << endl;
        cout << "\t\t 4. Facturacion y Analisis" << endl;
        cout << "\t\t 5. Reportes y Analisis" << endl;
        cout << "\t\t 6. Salir del Sistema" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tOpcion a escoger: [1/2/3/4/5/6]" << endl;
        cout << "\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch(choice) {
            case 1:
                gestorPedidos.gestionPedidos();  // Llamada al método de la clase
                break;
            case 2:
                gestorInventario.controlInventario();  // Llamada al método
                break;
            case 3:
                gestorEnvios.gestionEnvios();  // Llamada al método
                break;
            case 4:
                gestorFacturacion.gestionFacturacion();  // Llamada al método
                break;
            case 5:
                gestorReportes.generarReportes();  // Llamada al método
                break;
            case 6:
                break;
            default:
                cout << "\n\t\tOpcion invalida... Intente de nuevo...";
                cin.get();
        }
    } while(choice != 6);
}
