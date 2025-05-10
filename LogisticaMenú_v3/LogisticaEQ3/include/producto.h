#ifndef PRODUCTO_H
#define PRODUCTO_H
#pragma once
#include <string>
#include <vector>
#include <fstream>

class Producto {
public:
    std::string codigo;
    std::string nombre;
    double precio;
    int stock;

    // CRUD
    static void agregar(std::vector<Producto>& lista);
    static void mostrar(const std::vector<Producto>& lista);
    static void modificar(std::vector<Producto>& lista);
    static void eliminar(std::vector<Producto>& lista);

    // Persistencia
    static void guardarEnArchivo(const std::vector<Producto>& lista);
    static void cargarDesdeArchivo(std::vector<Producto>& lista);
};
#endif // PRODUCTO_H
