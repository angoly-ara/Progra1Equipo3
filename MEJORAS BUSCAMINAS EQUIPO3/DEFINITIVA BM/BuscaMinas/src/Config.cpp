#include <iostream>
#include <unistd.h>
#include "Config.h"
using namespace std;

Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}

void Config::menuConfiguracion(std::vector<Jugador>& jugadores)
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Mostrar Jugadores" << endl;
        cout << "\t\t2. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t3. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t4. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t5. Modo del Juego -------> " << (this->getmodoDesarrolladorTablero() ? "Activado" : "Desactivado") << endl;
        cout << "\t\t6. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t7. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;

        switch (opciones)
        {
        case 1:
            mostrarJugadores(jugadores);  // Mostrar jugadores
            break;
        case 2:
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
            this->setfilasTablero(valorIngresado);
            cout << "Filas del Tablero actualizadas" << endl;
            break;
        case 3:
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
            this->setcolumnasTablero(valorIngresado);
            cout << "Columnas del Tablero actualizadas" << endl;
            break;
        case 4:
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
            this->setminasTablero(valorIngresado);
            cout << "Minas del Tablero actualizadas" << endl;
            break;
        case 5:
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
            this->setmodoDesarrolladorTablero(valorIngresado);
            cout << "Modo del Juego actualizado" << endl;
            break;
        case 6:
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
            this->setvidasTablero(valorIngresado);
            cout << "Vidas del Juego actualizadas" << endl;
            break;
        case 7:
            repetir = false;
            break;
        default:
            cout << "Opción inválida, intente nuevamente." << endl;
        }
        system("pause");
    } while (repetir);
}

void Config::mostrarJugadores(const std::vector<Jugador>& jugadores)
{
    if (jugadores.empty())
    {
        cout << "\n\tNo hay jugadores registrados." << endl;
    }
    else
    {
        cout << "\n\tLista de Jugadores y Puntajes:" << endl;
        for (const auto& jugador : jugadores)
        {
            cout << "\t\t" << jugador.getNombre() << " - " << jugador.getPuntaje() << " puntos" << endl;
        }
    }
    system("pause");
}

int Config::getfilasTablero() { return this->filasTablero; }
void Config::setfilasTablero(int filasTablero) { this->filasTablero = filasTablero; }
int Config::getcolumnasTablero() { return this->columnasTablero; }
void Config::setcolumnasTablero(int columnasTablero) { this->columnasTablero = columnasTablero; }
int Config::getminasTablero() { return this->minasTablero; }
void Config::setminasTablero(int minasTablero) { this->minasTablero = minasTablero; }
bool Config::getmodoDesarrolladorTablero() { return this->modoDesarrolladorTablero; }
void Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero) { this->modoDesarrolladorTablero = modoDesarrolladorTablero; }
int Config::getvidasTablero() { return this->vidasTablero; }
void Config::setvidasTablero(int vidasTablero) { this->vidasTablero = vidasTablero; }
