#ifndef MENUCLIENTES_H
#define MENUCLIENTES_H

#include "Clientes.h"
#include "usuarios.h"
#include <vector>

class MenuClientes {
public:
    static void mostrar(std::vector<Clientes>& listaClientes, usuarios& usuarioActual);
};

#endif
