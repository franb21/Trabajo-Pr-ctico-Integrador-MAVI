#pragma once
#include "libs.h"
#include "enemigo.h"
#include "humano.h"
#include "mira.h"
#include "gameOver.h"
#include "menu.h"

class Juego {
private:
    RenderWindow& Ventana;
    Texture textfondoJuego;
    Texture textureVida[3];
    Sprite fondoJuego;
    Sprite vida;
    Mira mira;
    Enemigo enemigo;
    Humano humano;
    Font fuenteText;
    Text enemigosText;
    Text vidaText;
    int puntuacion = 0;
    int vidas = 3;
    int indiceVida = 2;
    int humanosMuertos = 0;
    int puntuacionFinal = 0;
    bool hayEnemigo = false;
    bool hayHumano = false;
public:
    Juego(RenderWindow& Ventana);
    void spawnEntidad();
    void controlVidas();
    void iniciar();
};