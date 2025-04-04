#include "Marcador.h"

Marcador::Marcador(int vidasIniciales) : puntaje(0), minasEncontradas(0), vidasRestantes(vidasIniciales) {}

void Marcador::incrementarPuntaje(int cantidad) {
    puntaje += cantidad;  // Incrementa el puntaje con el valor de minas cercanas
}

void Marcador::restarVida() {
    if (vidasRestantes > 0) {
        vidasRestantes--;  // Resta una vida
    }
}

bool Marcador::tieneVidas() const {
    return vidasRestantes > 0;  // Verifica si quedan vidas
}

int Marcador::getPuntaje() const {
    return puntaje;  // Retorna el puntaje
}

int Marcador::getMinasEncontradas() const {
    return minasEncontradas;  // Retorna las minas encontradas
}

int Marcador::getVidasRestantes() const {
    return vidasRestantes;  // Retorna las vidas restantes
}
