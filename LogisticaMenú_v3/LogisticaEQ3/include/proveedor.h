#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#pragma once
#include <string>
#include <vector>
#include <fstream>

class Proveedor {
public:
    std::string id;
    std::string nombre;
    std::string telefono;

    // CRUD
    static void agregar(std::vector<Proveedor>& lista);
    static void mostrar(const std::vector<Proveedor>& lista);
    static void modificar(std::vector<Proveedor>& lista);
    static void eliminar(std::vector<Proveedor>& lista);

    // Persistencia
    static void guardarEnArchivo(const std::vector<Proveedor>& lista);
    static void cargarDesdeArchivo(std::vector<Proveedor>& lista);
};

#endif // PROVEEDOR_H
