#pragma once
#include "libs.h"

class Humano {
private:
    Texture textHumanos[3];
    Texture textPuerta;
    Texture textOps;
    Sprite humanos; 
    Sprite puerta;
    Sprite Ops;
    float x;
    float y;
    Clock tiempoVivo;
    Clock tiempoOps;
    bool mostrarOps = false;
public:
    Humano();
    void dibujar(RenderWindow& Ventana);
    void spawn();
    bool estaVivo(int mouseX, int mouseY) const;
    bool tiempoVida();
    void activarEfecto();
    bool efectoOps();
};