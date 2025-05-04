#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "bitacora.h"
#include "usuarios.h"
#include <string>
#include <vector>

class Pedidos {
public:
    void gestionPedidos();
    void crearPedido();
    void consultarPedidos();
    void modificarPedido();
    void cancelarPedido();
    void verHistorial();

private:
    struct Pedido {
        std::string id;
        std::string cliente;
        std::string producto;
        std::string estado;
    };

    std::vector<Pedido> listaPedidos;

    void cargarPedidos();
    void guardarPedidos();
};


#endif // PEDIDOS_H
