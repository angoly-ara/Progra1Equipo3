#ifndef GLOBALS_H
#define GLOBALS_H
#pragma once
#include "pedidos.h"
#include "inventario.h"
#include "envios.h"
#include "facturacion.h"
#include "reportes.h"

// Declaraciones (sin inicialización)
extern Pedidos gestorPedidos;         // <-- Solo dice "existe en otro lugar"
extern Inventario gestorInventario;   // <-- No crea la variable aquí
extern Envios gestorEnvios;
extern Facturacion gestorFacturacion;
extern Reportes gestorReportes;

#endif // GLOBALS_H
