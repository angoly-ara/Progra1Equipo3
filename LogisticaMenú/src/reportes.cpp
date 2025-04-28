#include "reportes.h"
#include <iostream>
using namespace std;

extern usuarios usuarioRegistrado;
extern bitacora auditoria;

void Reportes::generarReportes() {
    int opcion;
    do {
        system("cls");
        cout << "\t\t========================================" << endl;
        cout << "\t\t| REPORTES Y ANALISIS - LOGISTICA      |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Informe de ventas" << endl;
        cout << "\t\t 2. Análisis de tiempos de entrega" << endl;
        cout << "\t\t 3. Reporte de inventarios" << endl;
        cout << "\t\t 4. Evaluación de proveedores" << endl;
        cout << "\t\t 5. Volver al menu anterior" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tOpcion a escoger: ";
        cin >> opcion;

        switch(opcion) {
            case 1: informeVentas(); break;
            case 2: analisisTiemposEntrega(); break;
            //case 3: reporteInventarios(); break;
            //case 4: evaluacionProveedores(); break;
            case 5: break;
            default: cout << "\n\t\tOpcion invalida!"; cin.get();
        }
    } while(opcion != 5);
}

void Reportes::informeVentas() {
    cout << "\n\t\t[Generando informe de ventas...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "500", "REPVENT");
    system("pause");
}

void Reportes::analisisTiemposEntrega() {
    cout << "\n\t\t[Analizando tiempos de entrega...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "500", "ANALTIME");
    system("pause");
}
// Implementar demás funciones...
