#ifndef MENUPROVEEDORES_H
#define MENUPROVEEDORES_H
#pragma once
#include <vector>
#include "Proveedor.h"
#include "usuarios.h"

class MenuProveedores {
public:
    static void mostrar(std::vector<Proveedor>& lista, usuarios& usuarioActual);
};

#endif // MENUPROVEEDORES_H
