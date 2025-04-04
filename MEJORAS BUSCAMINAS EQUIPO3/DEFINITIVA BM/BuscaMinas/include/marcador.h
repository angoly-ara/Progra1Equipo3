#ifndef MARCADOR_H
#define MARCADOR_H

#include <string>

class Marcador {
private:
    int puntaje;
    int minasEncontradas;
    int vidasRestantes;

public:
    Marcador(int vidasIniciales);  // Constructor
    void incrementarPuntaje(int cantidad);  // Incrementa el puntaje
    void restarVida();  // Resta una vida
    bool tieneVidas() const;  // Verifica si el jugador tiene vidas restantes

    int getPuntaje() const;  // Obtiene el puntaje
    int getMinasEncontradas() const;  // Obtiene las minas encontradas
    int getVidasRestantes() const;  // Obtiene las vidas restantes
};

#endif // MARCADOR_H
