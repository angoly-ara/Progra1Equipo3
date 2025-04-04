#include <iostream>
#include <string>
using namespace std;

// Declaración de funciones
void mostrarMenuPrincipal();
void gestionPedidos();
void controlInventario();
void enviosYTransportes();
void facturacionYAnalisis();
void reportesYAnalisis();

// Funciones de facturación y análisis
void generarFactura() {
    cout << "[Generando factura...]" << endl;
}

void consultarEstadoPago() {
    cout << "[Consultando estados de pago...]" << endl;
}

void registrarPago() {
    cout << "[Registrando un pago...]" << endl;
}

void verReportesFinancieros() {
    cout << "[Mostrando reportes financieros...]" << endl;
}

// Funciones de control de inventario
void stockDisponible() {
    cout << "[Revisando stock disponible...]" << endl;
}

void registroMercancia() {
    cout << "[Registrando mercancia nueva...]" << endl;
}

void ajusteInventario() {
    cout << "[Realizando ajustes en el inventario...]" << endl;
}

void verReportesExistencia() {
    cout << "[Mostrando reportes de existencias...]" << endl;
}

// Funciones de envíos y transportes
void generarGuiaEnvio() {
    cout << "Generando guia de envio..." << endl;
}

void asignarTransportista() {
    cout << "Asignando transportista..." << endl;
}

void rastrearEnvios() {
    cout << "Rastreando envios..." << endl;
}

void confirmarEntrega() {
    cout << "Confirmando entrega..." << endl;
}

void gestionarDevoluciones() {
    cout << "Gestionando devoluciones..." << endl;
}

int main() {
    string nombre;

    // Solicitar nombre al usuario
    system("cls");
    cout << "========================\n";
    cout << "  SISTEMA DE LOGISTICA\n";
    cout << "========================\n";
    cout << "Por favor ingrese su nombre: ";
    getline(cin, nombre);  // Usamos getline para permitir nombres con espacios

    // Mostrar bienvenida
    cout << "\nBienvenido, " << nombre << "!\n";
    system("pause");

    // Menú principal
    int opcion;
    do {
        system("cls");
        mostrarMenuPrincipal();
        cout << "Seleccione una opcion (" << nombre << "): ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                gestionPedidos();
                break;
            case 2:
                controlInventario();
                break;
            case 3:
                enviosYTransportes();
                break;
            case 4:
                facturacionYAnalisis();
                break;
            case 5:
                reportesYAnalisis();
                break;
            case 0:
                cout << "\nHasta luego, " << nombre << "!\n";
                break;
            default:
                cout << "\nOpcion no valida!\n";
                system("pause");
        }
    } while(opcion != 0);

    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n========================\n";
    cout << "  MENU PRINCIPAL\n";
    cout << "========================\n";
    cout << "1. Gestion de Pedidos\n";
    cout << "2. Control de Inventario\n";
    cout << "3. Envios y Transportes\n";
    cout << "4. Facturacion y Administracion\n";
    cout << "5. Reportes y Analisis\n";
    cout << "0. Salir\n";
    cout << "========================\n";
}

void gestionPedidos() {
    int opcion;
    do {
        system("cls");
        cout << "\n========================\n";
        cout << "  GESTION DE PEDIDOS\n";
        cout << "========================\n";
        cout << "1. Crear nuevo pedido\n";
        cout << "2. Consultar pedidos en proceso\n";
        cout << "3. Modificar pedido\n";
        cout << "4. Cancelar pedido\n";
        cout << "5. Historial de pedidos\n";
        cout << "0. Volver al menu principal\n";  // Cambiado a 0 para consistencia
        cout << "========================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "\nCreando nuevo pedido...\n";
                system("pause");
                break;
            case 2:
                cout << "\nConsultando pedidos...\n";
                system("pause");
                break;
            case 3:
                cout << "\nModificando pedido...\n";
                system("pause");
                break;
            case 4:
                cout << "\nCancelando pedido...\n";
                system("pause");
                break;
            case 5:
                cout << "\nMostrando historial...\n";
                system("pause");
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "\nSeleccione una opcion valida, por favor.\n";
                system("pause");
        }
    } while(opcion != 0);
}

void controlInventario() {
    int opcion;
    do {
        system("cls");
        cout << "\n========================\n";
        cout << "  CONTROL DE INVENTARIO\n";
        cout << "========================\n";
        cout << "1. Consultar stock disponible\n";
        cout << "2. Registrar nueva mercancia\n";
        cout << "3. Ajustes de inventario\n";
        cout << "4. Ver reportes de existencias\n";
        cout << "0. Volver al menu principal\n";  // Cambiado a 0 para consistencia
        cout << "========================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                stockDisponible();
                system("pause");
                break;
            case 2:
                registroMercancia();
                system("pause");
                break;
            case 3:
                ajusteInventario();
                system("pause");
                break;
            case 4:
                verReportesExistencia();
                system("pause");
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "\nOpcion no valida\n";
                system("pause");
        }
    } while (opcion != 0);
}

void enviosYTransportes() {
    int opcion;
    do {
        system("cls");
        cout << "\n========================\n";
        cout << "  ENVIOS Y TRANSPORTES\n";
        cout << "========================\n";
        cout << "1. Generar guia de envio\n";
        cout << "2. Asignar transportista\n";
        cout << "3. Rastrear envios\n";
        cout << "4. Confirmacion de entrega\n";
        cout << "5. Gestion de devoluciones\n";
        cout << "0. Volver al menu principal\n";  // Cambiado a 0 para consistencia
        cout << "========================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                generarGuiaEnvio();
                system("pause");
                break;
            case 2:
                asignarTransportista();
                system("pause");
                break;
            case 3:
                rastrearEnvios();
                system("pause");
                break;
            case 4:
                confirmarEntrega();
                system("pause");
                break;
            case 5:
                gestionarDevoluciones();
                system("pause");
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo.\n";
                system("pause");
        }
    } while (opcion != 0);
}

void facturacionYAnalisis() {
    int opcion;
    do {
        system("cls");
        cout << "\n========================\n";
        cout << "  FACTURACION Y ADMINISTRACION\n";
        cout << "========================\n";
        cout << "1. Generar factura\n";
        cout << "2. Consultar estados de pago\n";
        cout << "3. Registro de pagos\n";
        cout << "4. Ver reportes financieros\n";
        cout << "0. Volver al menu principal\n";  // Cambiado a 0 para consistencia
        cout << "========================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                generarFactura();
                system("pause");
                break;
            case 2:
                consultarEstadoPago();
                system("pause");
                break;
            case 3:
                registrarPago();
                system("pause");
                break;
            case 4:
                verReportesFinancieros();
                system("pause");
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "\nOpcion no valida\n";
                system("pause");
        }
    } while (opcion != 0);
}

void reportesYAnalisis() {
    int opcion;
    do {
        system("cls");
        cout << "\n========================\n";
        cout << "   REPORTES Y ANALISIS\n";
        cout << "========================\n";
        cout << "1. Informe de ventas\n";
        cout << "2. Analisis de tiempos de entrega\n";
        cout << "3. Reporte de inventarios\n";
        cout << "4. Evaluacion de proveedores\n";
        cout << "0. Volver al menu principal\n";  // Cambiado a 0 para consistencia
        cout << "========================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "\nMostrando informe de ventas...\n";
                system("pause");
                break;
            case 2:
                cout << "\nAnalizando tiempos de entrega...\n";
                system("pause");
                break;
            case 3:
                cout << "\nGenerando reporte de inventarios...\n";
                system("pause");
                break;
            case 4:
                cout << "\nEvaluando proveedores...\n";
                system("pause");
                break;
            case 0:
                cout << "\nVolviendo al menu principal...\n";
                break;
            default:
                cout << "\nOpcion no valida.\n";
                system("pause");
        }
    } while(opcion != 0);
}
