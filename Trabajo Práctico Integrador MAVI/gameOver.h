#pragma once
#include "libs.h"

class GameOver {
private:
    RenderWindow& Ventana;
    Texture textGameOver;
    Sprite gameOver;
    Font fuenteText;
    Text puntuacionText;
    int puntuacionFinal;
public:
    GameOver(RenderWindow& Ventana, int puntuacionFinal);
    void iniciar();
};