#include "bitacora.h"
#include <iostream>
#include <iomanip>
using namespace std;

void bitacora::insertar(string usuario, string codigo, string accion) {
    ofstream file("bitacora.txt", ios::app);
    if (file.is_open()) {
        file << left << setw(20) << usuario
             << setw(10) << codigo
             << setw(15) << accion << endl;
        file.close();
    } else {
        cerr << "\n\t\tError al abrir la bitácora!";
    }
}

void bitacora::desplegar() {
    system("cls");
    ifstream file("bitacora.txt");
    cout << "\t\t========================================" << endl;
    cout << "\t\t| REGISTRO DE BITACORA - LOGISTICA     |" << endl;
    cout << "\t\t========================================" << endl;

    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            cout << "\t\t" << linea << endl;
        }
        file.close();
    } else {
        cout << "\t\tNo hay registros en la bitácora." << endl;
    }
    cout << "\t\t========================================" << endl;
    system("pause");
}

void bitacora::menuBitacora() {
    int opcion;
    do {
        system("cls");
        cout << "\t\t========================================" << endl;
        cout << "\t\t| ADMINISTRACION DE BITACORA           |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Ver registros" << endl;
        cout << "\t\t 2. Exportar a archivo" << endl;
        cout << "\t\t 3. Volver" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tOpcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: desplegar(); break;
            case 2:
                cout << "\n\t\t[Exportando bitácora...]" << endl;
                system("pause");
                break;
            case 3: break;
            default: cout << "\n\t\tOpcion invalida!"; cin.get();
        }
    } while(opcion != 3);
}
