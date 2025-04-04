#include "Jugador.h"

Jugador::Jugador(std::string nombre) : nombre(nombre), puntaje(0) {}

void Jugador::incrementarPuntaje() {
    puntaje += 10; // Se puede ajustar el valor según la lógica del juego
}

std::string Jugador::getNombre() const {
    return nombre;
}

int Jugador::getPuntaje() const {
    return puntaje;
}
