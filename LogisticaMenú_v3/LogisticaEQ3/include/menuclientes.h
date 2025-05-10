#ifndef MENUCLIENTES_H
#define MENUCLIENTES_H
#include "clientes.h"
#pragma once
#include <vector>
#include "usuarios.h"

class Cliente;  // Forward declaration

class MenuClientes {
public:
   static void mostrar(std::vector<Clientes>& lista, usuarios& usuarioActual);
};

#endif // MENUCLIENTES_H
