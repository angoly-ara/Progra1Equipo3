#include "clientes.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bitacora.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <limits> // Para numeric_limits

using namespace std;

// Rango de códigos para clientes
const int CODIGO_INICIAL = 3107;
const int CODIGO_FINAL = 3157;

std::string Clientes::generarIdUnico(const std::vector<Clientes>& lista) {
    // Buscar el primer código disponible en el rango
    for (int i = CODIGO_INICIAL; i <= CODIGO_FINAL; ++i) {
        std::string id = std::to_string(i);
        if (idDisponible(lista, id)) {
            return id;
        }
    }
    return ""; // Retorna cadena vacía si no hay códigos disponibles
}

bool Clientes::idDisponible(const std::vector<Clientes>& lista, const std::string& id) {
    return std::none_of(lista.begin(), lista.end(),
        [&id](const Clientes& c) { return c.id == id; });
}

bool Clientes::esIdValido(const std::string& id) {
    try {
        int num = std::stoi(id);
        return (num >= CODIGO_INICIAL && num <= CODIGO_FINAL);
    } catch (...) {
        return false;
    }
}

// Implementación de métodos CRUD
void Clientes::agregar(std::vector<Clientes>& lista, const std::string& usuarioActual) {
    Clientes nuevo;

    // Asignar ID automático
    nuevo.id = generarIdUnico(lista);
    if (nuevo.id.empty()) {
        std::cerr << "\n\t\tError: No hay códigos disponibles para nuevos clientes (rango lleno)\n";
        system("pause");
        return;
    }

    std::cout << "\n\t\t=== AGREGAR CLIENTE (ID Auto-Asignado: " << nuevo.id << ") ===\n";

    // Limpiar buffer antes de getline()
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\t\tNombre completo: ";
    std::getline(std::cin, nuevo.nombre); // Ahora capturará correctamente "Juan"

    std::cout << "\t\tDirección: ";
    std::getline(std::cin, nuevo.direccion);

    lista.push_back(nuevo);
    guardarEnArchivo(lista);

    bitacora::registrar(usuarioActual, "CLIENTES", "Cliente agregado - ID: " + nuevo.id);
    std::cout << "\n\t\tCliente registrado exitosamente con ID: " << nuevo.id << "\n";
    system("pause");
}

void Clientes::mostrar(const std::vector<Clientes>& lista) {
    cout << "\n--- LISTA DE CLIENTES ---\n";
    for (const auto& cliente : lista) {
        cout << "ID: " << cliente.id
             << " | Nombre: " << cliente.nombre
             << " | Dirección: " << cliente.direccion << "\n";
    }
    system("pause");
}

void Clientes::modificar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& id) {
    auto it = find_if(lista.begin(), lista.end(),
        [&id](const Clientes& c) { return c.id == id; });

    if (it != lista.end()) {
        cout << "\n--- MODIFICAR CLIENTE (ID: " << id << ") ---\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

        cout << "Nuevo nombre (" << it->nombre << "): ";
        getline(cin, it->nombre);

        cout << "Nueva dirección (" << it->direccion << "): ";
        getline(cin, it->direccion);

        guardarEnArchivo(lista);
        bitacora::registrar(usuarioActual, "CLIENTES", "Cliente modificado - ID: " + id);
        cout << "Cliente modificado!\n";
    } else {
        cout << "Cliente no encontrado.\n";
    }
    system("pause");
}

void Clientes::eliminar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& id) {
    auto it = find_if(lista.begin(), lista.end(),
        [&id](const Clientes& c) { return c.id == id; });

    if (it != lista.end()) {
        lista.erase(it);

        guardarEnArchivo(lista); // <- Añadir esta línea

        // Registrar en bitácora
        bitacora::registrar(usuarioActual, "CLIENTES", "Cliente eliminado - ID: " + id);

        cout << "Cliente eliminado!\n";
    } else {
        cout << "Cliente no encontrado.\n";
    }
    system("pause");
}

void Clientes::guardarEnArchivo(const std::vector<Clientes>& lista) {
    // 1. Crear archivo temporal para escritura segura
    ofstream archivo("Clientes.tmp", ios::out);
    if (!archivo.is_open()) {
        cerr << "\n\t\tError crítico: No se pudo crear archivo temporal!\n";
        return;
    }

    // 2. Escribir todos los clientes con verificación
    bool errorEscritura = false;
    for (const auto& cliente : lista) {
        if (!(archivo << cliente.id << ","
                     << cliente.nombre << ","
                     << cliente.direccion << "\n")) {
            cerr << "\n\t\tError al escribir cliente ID: " << cliente.id << "\n";
            errorEscritura = true;
        }
    }

    // 3. Forzar escritura y verificar
    archivo.flush();
    if (!archivo || errorEscritura) {
        cerr << "\n\t\tError: No se pudieron guardar todos los datos!\n";
        archivo.close();
        remove("Clientes.tmp"); // Eliminar archivo temporal corrupto
        return;
    }
    archivo.close();

    // 4. Reemplazar archivo existente (operación atómica)
    if (remove("Clientes.txt") != 0 && errno != ENOENT) {
        cerr << "\n\t\tAdvertencia: No se pudo eliminar archivo anterior\n";
    }
    if (rename("Clientes.tmp", "Clientes.txt") != 0) {
        cerr << "\n\t\tError crítico: Falló el guardado final!\n";
    }
}

void Clientes::cargarDesdeArchivo(std::vector<Clientes>& lista) {
    // 1. Limpiar lista existente
    lista.clear();

    // 2. Abrir archivo con verificación
    ifstream archivo("Clientes.txt");
    if (!archivo) {
        // Crear archivo vacío si no existe
        ofstream nuevoArchivo("Clientes.txt");
        if (!nuevoArchivo) {
            cerr << "\n\t\tError crítico: No se pudo crear archivo de clientes!\n";
        }
        return;
    }

    // 3. Contadores para estadísticas
    int cargados = 0, omitidos = 0;
    string linea;

    // 4. Procesar cada línea
    while (getline(archivo, linea)) {
        // Eliminar espacios y saltos de línea
        linea.erase(remove_if(linea.begin(), linea.end(), ::isspace), linea.end());
        if (linea.empty()) continue;

        istringstream ss(linea);
        Clientes temp;
        string campo;

        // 5. Parsear campos con verificación
        try {
            if (!getline(ss, temp.id, ',') ||
                !getline(ss, temp.nombre, ',') ||
                !getline(ss, temp.direccion)) {
                throw runtime_error("Formato inválido");
            }

            // 6. Validar ID
            if (!esIdValido(temp.id)) {
                throw runtime_error("ID fuera de rango");
            }

            if (!idDisponible(lista, temp.id)) {
                throw runtime_error("ID duplicado");
            }

            lista.push_back(temp);
            cargados++;
        } catch (const exception& e) {
            cerr << "\n\t\tAdvertencia: Cliente omitido (" << e.what() << "): " << linea << "\n";
            omitidos++;
        }
    }

    // 7. Verificar estado final
    if (archivo.bad()) {
        cerr << "\n\t\tError: Fallo durante la lectura del archivo!\n";
    }

    // 8. Mostrar resumen (opcional)
    cout << "\n\t\tCarga completada. " << cargados << " clientes cargados, "
         << omitidos << " omitidos.\n";
}
