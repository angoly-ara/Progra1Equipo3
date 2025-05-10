#ifndef CLIENTES_H
#define CLIENTES_H

#pragma once
#include <string>
#include <vector>
#include <fstream>

class Clientes {
public:
    std::string id;
    std::string nombre;
    std::string direccion;

    // Métodos CRUD
    static void agregar(std::vector<Clientes>& lista);
    static void mostrar(const std::vector<Clientes>& lista);
    static void modificar(std::vector<Clientes>& lista);
    static void eliminar(std::vector<Clientes>& lista);

    // Persistencia en archivo
    static void guardarEnArchivo(const std::vector<Clientes>& lista);
    static void cargarDesdeArchivo(std::vector<Clientes>& lista);
};

#endif // CLIENTES_H
