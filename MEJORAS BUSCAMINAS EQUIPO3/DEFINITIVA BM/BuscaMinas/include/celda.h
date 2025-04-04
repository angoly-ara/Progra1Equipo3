#ifndef CELDA_H
#define CELDA_H
// Librería que define la clase Celda para representar una celda en el juego,
// almacenando coordenadas, estado de mina y métodos para su manipulación.

class Celda
{
    public:
        // Constructor por defecto
        Celda();

        // Constructor que inicializa la celda con coordenadas y estado de mina
        Celda(int coordenadaX, int coordenadaY, bool estadoMina);

        // Métodos para establecer y obtener la coordenada X
        int setCoordenadaX(int coordenadaX);
        int getCoordenadaX();

        // Métodos para establecer y obtener la coordenada Y
        int setCoordenadaY(int coordenadaY);
        int getCoordenadaY();

        // Métodos para establecer y obtener si la celda tiene una mina
        bool setMina(bool estadoMina);
        bool getMina();

        // Métodos para establecer y obtener si la mina ha sido descubierta
        bool setMinaDescubierta(bool minaDescubierta);
        bool getMinaDescubierta();

        // Método para imprimir la celda (probablemente para depuración o visualización)
        void imprimirCelda();

    protected:
        // Sección protegida (actualmente vacía, pero útil para herencia)

    private:
        // Variables privadas que almacenan las coordenadas y estado de la celda
        int coordenadaX, coordenadaY; // Coordenadas de la celda en el tablero
        bool mina; // Indica si la celda contiene una mina
        bool minaDescubierta; // Indica si la mina ha sido descubierta
};

#endif // CELDA_H
