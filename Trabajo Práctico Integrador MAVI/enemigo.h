#pragma once
#include "libs.h"

class Enemigo {
private:
    Texture textAliens[3];
    Texture textPuerta;
    Texture textZap;
    Sprite aliens;
    Sprite puerta;
    Sprite zap;
    float x;
    float y;
    Clock tiempoVivo;
    Clock tiempoZap;
    bool mostrarZap = false;
    bool disparo = false;
public:
    Enemigo();
    void dibujar(RenderWindow& Ventana);
    void spawn();
    bool estaVivo(int mouseX, int mouseY) const;
    bool disparar();
    bool efectoZap();
};