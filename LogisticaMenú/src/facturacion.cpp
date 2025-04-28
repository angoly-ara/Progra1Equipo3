#include "facturacion.h"
#include <iostream>
using namespace std;

extern usuarios usuarioRegistrado;
extern bitacora auditoria;

void Facturacion::gestionFacturacion() {
    int opcion;
    do {
        system("cls");
        cout << "\t\t========================================" << endl;
        cout << "\t\t| FACTURACION Y ANALISIS - LOGISTICA    |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Generar factura" << endl;
        cout << "\t\t 2. Consultar estado de pago" << endl;
        cout << "\t\t 3. Registrar pago" << endl;
        cout << "\t\t 4. Reportes financieros" << endl;
        cout << "\t\t 5. Volver al menu anterior" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tOpcion a escoger: ";
        cin >> opcion;

        switch(opcion) {
            case 1: generarFactura(); break;
            //case 2: consultarEstadoPago(); break;
           // case 3: registrarPago(); break;
            //case 4: verReportesFinancieros(); break;
            case 5: break;
            default: cout << "\n\t\tOpcion invalida!"; cin.get();
        }
    } while(opcion != 5);
}

void Facturacion::generarFactura() {
    cout << "\n\t\t[Generando factura...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "400", "FACT");
    system("pause");
}

void Facturacion::consultarEstadoPago() {
    cout << "\n\t\t[Consultando estado de pago...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "400", "CONSPAG");
    system("pause");
}
// Implementar demás funciones...
