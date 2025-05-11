#ifndef GLOBALS_H
#define GLOBALS_H
#pragma once

#include "pedidos.h"
#include "inventario.h"
#include "envios.h"
#include "facturacion.h"
#include "reportes.h"
#include "usuarios.h"
#include "bitacora.h"

// Declaraciones extern
extern Pedidos gestorPedidos;
extern Inventario gestorInventario;
extern Envios gestorEnvios;
extern Facturacion gestorFacturacion;
extern Reportes gestorReportes;
extern usuarios usuarioRegistrado;
extern bitacora auditoria;

#endif // GLOBALS_H
