#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vector>
#include "Celda.h"

using namespace std;

class Tablero
{
public:
    static const int MAX_ALTURA = 20;
    static const int MAX_ANCHO = 20;
    static const int MAX_CELDAS = MAX_ALTURA * MAX_ANCHO;
    Tablero();
    Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);
    int getAlturaTablero();
    bool setAlturaTablero(int alturaTablero);
    int getAnchoTablero();
    bool setAnchoTablero(int anchoTablero);
    bool getModoDesarrollador();
    bool setModoDesarrollador(bool modoDesarrollador);
    void imprimirSeparadorEncabezado();
    void imprimirSeparadorFilas();
    void imprimirEncabezado();
    void imprimir();
    bool colocarMina(int x, int y);
    bool descubrirMina(int x, int y);
    int contarCeldasSinMinasYSinDescubrir();
    int minasCercanas(int fila, int columna);
protected:

private:

    int alturaTablero, anchoTablero;
    bool modoDesarrollador;
    vector<vector<Celda>> contenidoTablero;

    string getRepresentacionMina(int x, int y);

};

#endif // TABLERO_H
