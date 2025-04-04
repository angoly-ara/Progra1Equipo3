#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    int puntaje;
public:
    Jugador(string nombre);
    void incrementarPuntaje();
    string getNombre() const;
    int getPuntaje() const;

};

#endif // JUGADOR_H
