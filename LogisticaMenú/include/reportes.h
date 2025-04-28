#ifndef REPORTES_H
#define REPORTES_H

#include "bitacora.h"
#include "usuarios.h"

class Reportes {
public:
    void generarReportes();
    void informeVentas();
    void analisisTiemposEntrega();
    void reporteInventarios();
    void evaluacionProveedores();
};

#endif // REPORTES_H
