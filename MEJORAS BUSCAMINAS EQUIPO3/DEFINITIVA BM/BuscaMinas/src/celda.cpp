#include "Celda.h"
#include <iostream>
using namespace std;

// Constructor por defecto de la clase Celda
Celda::Celda()
{
}

// Constructor con parámetros para inicializar las coordenadas y el estado de la mina
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)
{
    // Inicializa las coordenadas X y Y
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;

    // Inicializa el estado de la mina
    this->mina = estadoMina;

    // Inicializa minaDescubierta como false
    this->minaDescubierta = false;
}

// Método para establecer la coordenada X
int Celda::setCoordenadaX(int coordenadaX)
{
    // Asigna el valor a la coordenada X
    this->coordenadaX = coordenadaX;
}

// Método para obtener el valor de la coordenada X
int Celda::getCoordenadaX()
{
    // Devuelve el valor de la coordenada X
    return this->coordenadaX;
}

// Método para establecer la coordenada Y
int Celda::setCoordenadaY(int coordenadaY)
{
    // Asigna el valor a la coordenada Y
    this->coordenadaY = coordenadaY;
}

// Método para obtener el valor de la coordenada Y
int Celda::getCoordenadaY()
{
    // Devuelve el valor de la coordenada Y
    return this->coordenadaY;
}

// Método para establecer el estado de la mina, solo si no hay una mina ya puesta
bool Celda::setMina(bool estadoMina)
{
    // Verifica si ya hay una mina en la celda
    if (this->getMina())
    {
        // Si ya hay una mina, no permite cambiar su estado
        return false;
    }
    else{
        // Si no hay mina, establece el nuevo estado
        this->mina = estadoMina;
        return true;
    }
}

// Método para obtener el estado de la mina
bool Celda::getMina()
{
    // Devuelve si la celda tiene mina o no
    return this->mina;
}

// Método para establecer si la mina ha sido descubierta
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    // Establece si la mina ha sido descubierta
    this->minaDescubierta = minaDescubierta;
}

// Método para obtener el estado de la mina descubierta
bool Celda::getMinaDescubierta()
{
    // Devuelve si la mina ha sido descubierta
    return this->minaDescubierta;
}

// Método para imprimir la información de la celda
void Celda::imprimirCelda()
{
    // Muestra las coordenadas y el estado de la mina
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
}
