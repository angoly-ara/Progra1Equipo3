#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"
#include "Jugador.h"

using namespace std;

int main()
{
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;

    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    vector<Jugador> jugadores;
    srand(getpid());

    int opciones;
    bool repetir = true;

    do {
        system("cls");
        cout << "\n\n\t\tBUSCA MINAS - Menu" << endl;
        cout << "\t\t------------------" << endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;

        switch (opciones) {
            case 1:
                configuracionJuego.menuConfiguracion(jugadores);
                break;
            case 2: {
                string nombreJugador;
                cout << "Ingrese su nombre: ";
                cin >> nombreJugador;

                Jugador jugador(nombreJugador);
                jugadores.push_back(jugador);

                Juego juegoTemporal(
                    Tablero(configuracionJuego.getfilasTablero(),
                            configuracionJuego.getcolumnasTablero(),
                            configuracionJuego.getmodoDesarrolladorTablero()),
                    configuracionJuego.getminasTablero(),
                    configuracionJuego.getvidasTablero(),
                    nombreJugador
                );
                juegoTemporal.iniciar();  // Al salir de aquí, vuelve al menú
                break;
            }
            case 3:
                repetir = false;
                break;
        }
    } while (repetir);

    system("cls");
    return 0;
}
