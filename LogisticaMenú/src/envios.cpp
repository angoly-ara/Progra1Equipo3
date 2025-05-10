#include "envios.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include <stdexcept>

using namespace std;

extern usuarios usuarioRegistrado;
extern bitacora auditoria;

// Definición del vector de transportistas
const vector<string> Envios::transportistas = {
    "Transportes Rápidos S.A.",
    "Envíos Seguros Ltda.",
    "Logística Nacional",
    "Mensajería Express",
    "Carga Confiable"
};

// Constructor
Envios::Envios() {
    inicializarRandom();
}

// Destructor
Envios::~Envios() {
    // Limpieza si es necesaria
}

void Envios::inicializarRandom() {
    static bool initialized = false;
    if (!initialized) {
        srand(static_cast<unsigned>(time(nullptr)));
        initialized = true;
    }
}

void Envios::gestionEnvios() {
    int opcion;
    do {
        system("cls");
        cout << "\n\t\t========================================";
        cout << "\n\t\t|       GESTIÓN DE ENVÍOS             |";
        cout << "\n\t\t========================================";
        cout << "\n\t\t| 1. Generar guía de envío            |";
        cout << "\n\t\t| 2. Asignar transportista            |";
        cout << "\n\t\t| 3. Rastrear envío                   |";
        cout << "\n\t\t| 4. Confirmar entrega                |";
        cout << "\n\t\t| 5. Cancelar envío                   |";
        cout << "\n\t\t| 6. Volver al menú principal         |";
        cout << "\n\t\t========================================";
        cout << "\n\t\tSeleccione una opción: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\t\tEntrada inválida! Por favor ingrese un número.";
            continue;
        }
        cin.ignore();

        switch(opcion) {
            case 1: generarGuia(); break;
            case 2: asignarTransportista(); break;
            case 3: rastrearEnvio(); break;
            case 4: confirmarEntrega(); break;
            case 5: cancelarEnvio(); break;
            case 6: break;
            default:
                cout << "\n\t\tOpción inválida!";
                cin.get();
        }
    } while(opcion != 6);
}

void Envios::generarGuia() {
    system("cls");
    cout << "\n\t\t========================================";
    cout << "\n\t\t|       GENERAR GUÍA DE ENVÍO         |";
    cout << "\n\t\t========================================";

    cout << "\n\t\tNúmero de pedido: ";
    getline(cin, numeroPedido);
    if (numeroPedido.empty()) {
        cout << "\n\t\tEl número de pedido no puede estar vacío!";
        system("pause");
        return;
    }

    cout << "\t\tNombre del destinatario: ";
    getline(cin, destinatario);
    if (destinatario.empty()) {
        cout << "\n\t\tEl nombre del destinatario no puede estar vacío!";
        system("pause");
        return;
    }

    cout << "\t\tDirección de entrega: ";
    getline(cin, direccion);
    if (direccion.empty()) {
        cout << "\n\t\tLa dirección no puede estar vacía!";
        system("pause");
        return;
    }

    cout << "\t\tCiudad: ";
    getline(cin, ciudad);
    if (ciudad.empty()) {
        cout << "\n\t\tLa ciudad no puede estar vacía!";
        system("pause");
        return;
    }

    cout << "\t\tTeléfono de contacto: ";
    getline(cin, telefono);
    if (telefono.empty()) {
        cout << "\n\t\tEl teléfono no puede estar vacío!";
        system("pause");
        return;
    }

    // Generar número de guía automático
    numeroGuia = "G" + to_string(rand() % 9000 + 1000);
    estado = "Pendiente";
    fechaGeneracion = obtenerFechaActual();
    transportista = "Por asignar";

    if (!guardarEnvio()) {
        cout << "\n\t\tError al guardar el envío!";
        system("pause");
        return;
    }

    cout << "\n\t\t========================================";
    cout << "\n\t\t| ¡GUÍA GENERADA CON ÉXITO!            |";
    cout << "\n\t\t========================================";
    cout << "\n\t\tNúmero de guía: " << numeroGuia;
    cout << "\n\t\tEstado: " << estado;
    cout << "\n\t\tFecha: " << fechaGeneracion;
    cout << "\n\t\t========================================";

    auditoria.insertar(usuarioRegistrado.getNombre(), "300", "GUIA-GENERADA-" + numeroGuia);
    system("pause");
}

void Envios::asignarTransportista() {
    system("cls");
    cout << "\n\t\t========================================";
    cout << "\n\t\t|    ASIGNAR TRANSPORTISTA            |";
    cout << "\n\t\t========================================";

    cout << "\n\t\tNúmero de guía: ";
    getline(cin, numeroGuia);
    if (numeroGuia.empty()) {
        cout << "\n\t\tEl número de guía no puede estar vacío!";
        system("pause");
        return;
    }

    if (!existeEnvio(numeroGuia)) {
        cout << "\n\t\t¡Guía no encontrada!";
        system("pause");
        return;
    }

    // Selección aleatoria de transportista
    transportista = transportistas[rand() % transportistas.size()];

    actualizarEnvio("transportista", transportista);
    actualizarEnvio("estado", "En camino");

    cout << "\n\t\tTransportista asignado: " << transportista;
    cout << "\n\t\tEstado actualizado: En camino";

    auditoria.insertar(usuarioRegistrado.getNombre(), "300", "TRANS-ASIGNADO-" + numeroGuia);
    system("pause");
}

void Envios::rastrearEnvio() {
    system("cls");
    cout << "\n\t\t========================================";
    cout << "\n\t\t|      RASTREO DE ENVÍO               |";
    cout << "\n\t\t========================================";

    cout << "\n\t\tNúmero de guía: ";
    getline(cin, numeroGuia);
    if (numeroGuia.empty()) {
        cout << "\n\t\tEl número de guía no puede estar vacío!";
        system("pause");
        return;
    }

    ifstream archivo("envios.txt");
    if (!archivo.is_open()) {
        cout << "\n\t\tError al abrir el archivo de envíos!";
        system("pause");
        return;
    }

    bool encontrado = false;
    string linea;

    while (getline(archivo, linea)) {
        size_t pos = linea.find("|");
        if (pos == string::npos) continue;

        string guia = linea.substr(0, pos);
        if (guia == numeroGuia) {
            encontrado = true;
            vector<string> datos = split(linea, '|');

            // Verificar que tenemos suficientes datos
            if (datos.size() < 6) {
                cout << "\n\t\tError: Datos de envío incompletos!";
                break;
            }

            cout << "\n\t\tINFORMACIÓN DEL ENVÍO";
            cout << "\n\t\t--------------------------------";
            cout << "\n\t\tGuía: " << datos[0];
            cout << "\n\t\tPedido: " << datos[1];
            cout << "\n\t\tDestinatario: " << datos[2];
            cout << "\n\t\tTransportista: " << datos[3];
            cout << "\n\t\tEstado: " << datos[4];
            cout << "\n\t\tFecha: " << datos[5];
            cout << "\n\t\t--------------------------------";
            cout << "\n\t\tHISTORIAL DE MOVIMIENTOS:";
            cout << "\n\t\t1. " << datos[5] << " - Envío registrado";

            if (datos[4] == "En camino") {
                cout << "\n\t\t2. " << datos[5] << " - En proceso de empaque";
                cout << "\n\t\t3. " << datos[5] << " - En ruta de entrega";
            }

            if (datos[4] == "Entregado") {
                cout << "\n\t\t4. " << datos[5] << " - Paquete entregado";
            }
            break;
        }
    }
    archivo.close();

    if (!encontrado) {
        cout << "\n\t\t¡Guía no encontrada!";
    }

    auditoria.insertar(usuarioRegistrado.getNombre(), "300", "RASTREO-GUIA-" + numeroGuia);
    system("pause");
}

void Envios::confirmarEntrega() {
    system("cls");
    cout << "\n\t\t========================================";
    cout << "\n\t\t|     CONFIRMACIÓN DE ENTREGA         |";
    cout << "\n\t\t========================================";

    cout << "\n\t\tNúmero de guía: ";
    getline(cin, numeroGuia);
    if (numeroGuia.empty()) {
        cout << "\n\t\tEl número de guía no puede estar vacío!";
        system("pause");
        return;
    }

    if (!existeEnvio(numeroGuia)) {
        cout << "\n\t\t¡Guía no encontrada!";
        system("pause");
        return;
    }

    cout << "\t\tNombre de quien recibe: ";
    getline(cin, receptor);
    if (receptor.empty()) {
        cout << "\n\t\tEl nombre del receptor no puede estar vacío!";
        system("pause");
        return;
    }

    cout << "\t\tDNI/Cédula de quien recibe: ";
    getline(cin, documentoReceptor);
    if (documentoReceptor.empty()) {
        cout << "\n\t\tEl documento no puede estar vacío!";
        system("pause");
        return;
    }

    cout << "\t\tObservaciones: ";
    getline(cin, observaciones);

    actualizarEnvio("estado", "Entregado");
    actualizarEnvio("fechaEntrega", obtenerFechaActual());

    cout << "\n\t\t¡Entrega confirmada con éxito!";

    auditoria.insertar(usuarioRegistrado.getNombre(), "300", "ENTREGA-CONFIRMADA-" + numeroGuia);
    system("pause");
}

void Envios::cancelarEnvio() {
    system("cls");
    cout << "\n\t\t========================================";
    cout << "\n\t\t|       CANCELACIÓN DE ENVÍO          |";
    cout << "\n\t\t========================================";

    cout << "\n\t\tNúmero de guía: ";
    getline(cin, numeroGuia);
    if (numeroGuia.empty()) {
        cout << "\n\t\tEl número de guía no puede estar vacío!";
        system("pause");
        return;
    }

    if (!existeEnvio(numeroGuia)) {
        cout << "\n\t\t¡Guía no encontrada!";
        system("pause");
        return;
    }

    cout << "\t\tMotivo de cancelación: ";
    string motivo;
    getline(cin, motivo);
    if (motivo.empty()) {
        cout << "\n\t\tDebe especificar un motivo!";
        system("pause");
        return;
    }

    // Eliminar el envío del archivo
    ifstream archivo("envios.txt");
    if (!archivo.is_open()) {
        cout << "\n\t\tError al abrir el archivo de envíos!";
        system("pause");
        return;
    }

    ofstream temp("temp.txt");
    if (!temp.is_open()) {
        cout << "\n\t\tError al crear archivo temporal!";
        archivo.close();
        system("pause");
        return;
    }

    string linea;
    bool eliminado = false;
    while (getline(archivo, linea)) {
        if (linea.find(numeroGuia) == string::npos) {
            temp << linea << endl;
        } else {
            eliminado = true;
        }
    }

    archivo.close();
    temp.close();

    if (eliminado) {
        remove("envios.txt");
        if (rename("temp.txt", "envios.txt") != 0) {
            cout << "\n\t\tError al actualizar el archivo de envíos!";
            system("pause");
            return;
        }
        cout << "\n\t\t¡Envío cancelado con éxito!";
    } else {
        remove("temp.txt");
        cout << "\n\t\tNo se pudo encontrar el envío para cancelar!";
    }

    auditoria.insertar(usuarioRegistrado.getNombre(), "300", "ENVIO-CANCELADO-" + numeroGuia + "-MOTIVO:" + motivo);
    system("pause");
}

// Funciones auxiliares
bool Envios::existeEnvio(const string& guia) {
    ifstream archivo("envios.txt");
    if (!archivo.is_open()) {
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find("|");
        if (pos != string::npos && linea.substr(0, pos) == guia) {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

void Envios::actualizarEnvio(const string& campo, const string& valor) {
    ifstream archivo("envios.txt");
    if (!archivo.is_open()) {
        cout << "\n\t\tError al abrir el archivo de envíos!";
        return;
    }

    ofstream temp("temp.txt");
    if (!temp.is_open()) {
        cout << "\n\t\tError al crear archivo temporal!";
        archivo.close();
        return;
    }

    string linea;
    bool actualizado = false;
    while (getline(archivo, linea)) {
        size_t pos = linea.find("|");
        if (pos != string::npos && linea.substr(0, pos) == numeroGuia) {
            vector<string> datos = split(linea, '|');

            if (campo == "transportista" && datos.size() > 3) datos[3] = valor;
            else if (campo == "estado" && datos.size() > 4) datos[4] = valor;
            else if (campo == "fechaEntrega" && datos.size() > 5) datos[5] = valor;

            // Reconstruir la línea
            string nuevaLinea = datos[0];
            for (size_t i = 1; i < datos.size(); i++) {
                nuevaLinea += "|" + datos[i];
            }
            temp << nuevaLinea << endl;
            actualizado = true;
        } else {
            temp << linea << endl;
        }
    }

    archivo.close();
    temp.close();

    if (actualizado) {
        remove("envios.txt");
        rename("temp.txt", "envios.txt");
    } else {
        remove("temp.txt");
    }
}

bool Envios::guardarEnvio() {
    ofstream archivo("envios.txt", ios::app);
    if (!archivo.is_open()) {
        return false;
    }

    archivo << numeroGuia << "|" << numeroPedido << "|" << destinatario << "|"
            << transportista << "|" << estado << "|" << fechaGeneracion << "|"
            << direccion << "|" << ciudad << "|" << telefono << endl;

    archivo.close();
    return true;
}

vector<string> Envios::split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string Envios::obtenerFechaActual() {
    time_t now = time(0);
    if (now == -1) {
        return "Fecha desconocida";
    }

    tm* ltm = localtime(&now);
    if (!ltm) {
        return "Fecha desconocida";
    }

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", ltm);
    return string(buffer);
}
