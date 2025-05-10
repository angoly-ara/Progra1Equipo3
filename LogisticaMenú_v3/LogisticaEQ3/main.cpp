#include <iostream>
#include "usuarios.h"
#include "MenuPrincipal.h"
#include "pedidos.h"  // Faltaban estos includes
#include "inventario.h"
#include "envios.h"
#include "facturacion.h"
#include "reportes.h"
#include "MenuCatalogos.h"
#include "Clientes.h"
#include "Proveedor.h"
#include "Producto.h"
#include "globals.h"

// Instancias globales (como las tienes actualmente)
usuarios usuarioRegistrado;
bitacora auditoria;

Pedidos gestorPedidos;
Inventario gestorInventario;
Envios gestorEnvios;
Facturacion gestorFacturacion;
Reportes gestorReportes;

int main() {

    vector<Clientes> clientes;
    vector<Proveedor> proveedores;
    vector<Producto> productos;
    usuarios usuarioActual;

    if (usuarioRegistrado.loginUsuarios()) {  // Login existente
        MenuPrincipal::mostrar(clientes, proveedores, productos, usuarioActual);  // Menú principal con tu estilo
    }
    std::cout << "** Hasta la próxima **\n";
    return 0;
}
