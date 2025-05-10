#ifndef MENUPRODUCTOS_H
#define MENUPRODUCTOS_H
#pragma once
#include <vector>
#include "Producto.h"
#include "usuarios.h"

class MenuProductos {
public:
    static void mostrar(std::vector<Producto>& lista, usuarios& usuarioActual);
};

#endif // MENUPRODUCTOS_H
