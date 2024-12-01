#include "juego.h"
int main() {
    srand((time(nullptr)));
    RenderWindow Ventana(VideoMode(1200, 800), "Super Aien Shooter");

    Juego juego(Ventana);
    juego.iniciar();
    return 0;
}