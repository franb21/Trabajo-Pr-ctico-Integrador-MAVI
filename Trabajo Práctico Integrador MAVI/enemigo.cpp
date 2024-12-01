#include "enemigo.h"
#include "posiciones.h"

Enemigo::Enemigo() {
    textAliens[0].loadFromFile("enemigo1.png");
    textAliens[1].loadFromFile("enemigo2.png");
    textAliens[2].loadFromFile("enemigo3.png");
    textPuerta.loadFromFile("puerta.png");
    textZap.loadFromFile("zap.png");

    puerta.setTexture(textPuerta);
    zap.setTexture(textZap);
    zap.setPosition(345, 240);

    puerta.setOrigin(textPuerta.getSize().x / 2, textPuerta.getSize().y / 2);
    aliens.setOrigin((float)textAliens[0].getSize().x / 2, (float)textAliens[0].getSize().y / 2);
}

void Enemigo::dibujar(RenderWindow& Ventana) {
    Ventana.draw(puerta);
    Ventana.draw(aliens);
    if (efectoZap()) {
        Ventana.draw(zap);
    }
}

void Enemigo::spawn() {
    int indicePuerta = rand() % 6;
    x = posPuertas[indicePuerta][0];
    y = posPuertas[indicePuerta][1];
    puerta.setPosition(x, y);

    x = posEn[indicePuerta][0];
    y = posEn[indicePuerta][1];
    int tipoAlien = rand() % 3;
    aliens.setTexture(textAliens[tipoAlien]);
    aliens.setPosition(x, y);

    tiempoVivo.restart();
    mostrarZap = false;
    disparo = false;
}
bool Enemigo::estaVivo(int mouseX, int mouseY) const {
    return (mouseX >= x - 39 && mouseX <= x + 39 && mouseY >= y - 82 && mouseY <= y + 82);
}

bool Enemigo::disparar() {
    if (!disparo && tiempoVivo.getElapsedTime().asSeconds() >= 1.5f) {
        mostrarZap = true;
        tiempoZap.restart();
        disparo = true;
        return true;
    }
    return false;
}

bool Enemigo::efectoZap() {
    if (mostrarZap) {
        if (tiempoZap.getElapsedTime().asSeconds() >= 2) {
            mostrarZap = false;
        }
    }
    return mostrarZap;
}