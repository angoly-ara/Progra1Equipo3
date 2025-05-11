#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#pragma once
#include <vector>
#include "Clientes.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Almacen.h"
#include "usuarios.h"

class MenuPrincipal {
public:
    static void mostrar(std::vector<Clientes>& clientes,
                       std::vector<Proveedor>& proveedores,
                       std::vector<Producto>& productos,
                       std::vector<Almacen>& almacenes,
                       usuarios& usuarioActual);
};
#endif // MENUPRINCIPAL_H
