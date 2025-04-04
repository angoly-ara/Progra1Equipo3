//DOCUMENTACION DEL JUEGO BUSCA MINAS, PROPORCIONADO POR EL INGENIERO ESDUARDO DEL ÁGUILA EN MARZO 2025
//PARTE DEL COORDINADOR, JENNIFER BARRIOS EQUIPO 3, PORTALES PROGRAMACION 1 INGENIERIA EN SISTEMAS.
#include "Juego.h"
#include <iostream>
#include <fstream>
#include <ctime> // Para medir el tiempo
#include <iomanip> // Para formatear la salida
#include "marcador.h"

int Juego::aleatorio_en_rango(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Juego::filaAleatoria() {
    return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
}

int Juego::columnaAleatoria() {
    return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
}

Juego::Juego(Tablero tablero, int cantidadMinas, int vidas, std::string nombreJugador)
    : tablero(tablero), cantidadMinas(cantidadMinas),
      marcador(vidas),  // Inicializa Marcador con vidas
      nombreJugador(nombreJugador),
      jugador(nombreJugador) {
    this->colocarMinasAleatoriamente();
}

void Juego::colocarMinasAleatoriamente() {
    int x, y, minasColocadas = 0;
    while (minasColocadas < this->cantidadMinas) {
        x = this->columnaAleatoria();
        y = this->filaAleatoria();
        if (this->tablero.colocarMina(x, y)) {
            minasColocadas++;
        }
    }
}

int Juego::solicitarFilaUsuario() {
    int fila = 0;
    std::cout << "Ingresa la FILA en la que desea jugar: ";
    std::cin >> fila;
    return fila - 1;
}

int Juego::solicitarColumnaUsuario() {
    int columna = 0;
    std::cout << "Ingresa la COLUMNA en la que desea jugar: ";
    std::cin >> columna;
    return columna - 1;
}

bool Juego::jugadorGana() {
    int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
    return (conteo == 0);
}

void Juego::iniciar() {
    this->tiempoInicio = time(nullptr);
    int fila, columna;

    while (marcador.tieneVidas()) {
        this->tablero.imprimir();
        this->mostrarMarcador();

        fila = this->solicitarFilaUsuario();
        columna = this->solicitarColumnaUsuario();

        bool respuesta = this->tablero.descubrirMina(columna, fila);

        if (!respuesta) {
            marcador.restarVida();
            std::cout << "\n\033[31m¡Has pisado una mina!\033[0m Vidas restantes: "
                      << marcador.getVidasRestantes() << "\n";

            if (!marcador.tieneVidas()) {
                time_t tiempoFinal = time(nullptr);
                double tiempoTotal = difftime(tiempoFinal, this->tiempoInicio);

                // Revelar el tablero y mostrar resultados
                this->tablero.setModoDesarrollador(true);  // Revela todas las celdas
                this->tablero.imprimir();

                std::cout << "\033[31m\n¡Perdiste el Juego!\033[0m\n";
                std::cout << "Tiempo jugado: " << std::fixed << std::setprecision(2)
                          << tiempoTotal << " segundos.\n";
                this->mostrarMarcador();

                // Esperar a que el usuario presione una tecla
                std::cout << "\nPresiona cualquier tecla para volver al menú principal...";
                std::cin.ignore();  // Limpiar el buffer de entrada
                std::cin.get();     // Esperar a que el usuario presione una tecla

                break;  // Sale del bucle pero no cierra el juego
            }
        }

         else {
            // Incrementar puntaje si descubre una celda segura
            int minasCercanas = this->tablero.minasCercanas(fila, columna);
            marcador.incrementarPuntaje(minasCercanas * 10);  // Ejemplo: 10 pts por mina cercana
            jugador.incrementarPuntaje();  // Actualiza el puntaje del jugador
        }

        if (this->jugadorGana()) {
            time_t tiempoFinal = time(nullptr);
            double tiempoTotal = difftime(tiempoFinal, this->tiempoInicio);

            std::cout << "\033[32m¡Ganaste el Juego en "
                      << std::fixed << std::setprecision(2) << tiempoTotal
                      << " segundos!\033[0m\n";
            std::cout << "Puntaje final: " << marcador.getPuntaje() << "\n";

            this->tablero.setModoDesarrollador(true);
            this->tablero.imprimir();
            break;
        }
    }
}

void Juego::mostrarMarcador() {
    std::cout << "\n--- MARCADOR ---\n";
    std::cout << "Jugador: " << nombreJugador << "\n";
    std::cout << "Vidas: " << marcador.getVidasRestantes() << "\n";
    std::cout << "Puntaje: " << marcador.getPuntaje() << "\n";
    std::cout << "----------------\n";
}

