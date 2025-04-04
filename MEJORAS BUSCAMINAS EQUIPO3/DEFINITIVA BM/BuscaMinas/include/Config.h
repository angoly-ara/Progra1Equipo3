#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include "Jugador.h"  // Asegúrate de incluir Jugador.h

class Config
{
public:
    // Constructor
    Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);

    // Métodos para obtener y establecer las configuraciones
    int getfilasTablero();
    void setfilasTablero(int filasTablero);
    int getcolumnasTablero();
    void setcolumnasTablero(int columnasTablero);
    int getminasTablero();
    void setminasTablero(int minasTablero);
    bool getmodoDesarrolladorTablero();
    void setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
    int getvidasTablero();
    void setvidasTablero(int vidasTablero);

    // Métodos para gestionar la configuración de jugadores
    void menuConfiguracion(std::vector<Jugador>& jugadores);
    void mostrarJugadores(const std::vector<Jugador>& jugadores);

private:
    // Atributos de configuración del tablero
    int filasTablero;
    int columnasTablero;
    int minasTablero;
    bool modoDesarrolladorTablero;
    int vidasTablero;
};

#endif // CONFIG_
