#include "humano.h"
#include "posiciones.h"

Humano::Humano() {
    textHumanos[0].loadFromFile("humano1.png");
    textHumanos[1].loadFromFile("humano2.png");
    textHumanos[2].loadFromFile("humano3.png");
    textPuerta.loadFromFile("puerta.png");
    textOps.loadFromFile("oops.png");

    puerta.setTexture(textPuerta);
    Ops.setTexture(textOps);
    Ops.setPosition(130, 80);

    puerta.setOrigin(textPuerta.getSize().x / 2, textPuerta.getSize().y / 2);
    humanos.setOrigin((float)textHumanos[0].getSize().x / 2, (float)textHumanos[0].getSize().y / 2);
}

void Humano::dibujar(RenderWindow& Ventana) {
    Ventana.draw(puerta);
    Ventana.draw(humanos);
      if (efectoOps()) {
          Ventana.draw(Ops);
      }
}

void Humano::spawn() {
    int indicePuerta = rand() % 6;
    x = posPuertas[indicePuerta][0];
    y = posPuertas[indicePuerta][1];
    puerta.setPosition(x, y);

    x = posHu[indicePuerta][0];
    y = posHu[indicePuerta][1];
    int tipoHumano = rand() % 3;
    humanos.setTexture(textHumanos[tipoHumano]);
    humanos.setPosition(x, y);

    tiempoVivo.restart();
    mostrarOps = false;
}
bool Humano::estaVivo(int mouseX, int mouseY) const {
    return (mouseX >= x - 37 && mouseX <= x + 37 && mouseY >= y - 78 && mouseY <= y + 78);
}
bool Humano::tiempoVida() {
    return tiempoVivo.getElapsedTime().asSeconds() >= 1.5f;
}

void Humano::activarEfecto() {
    mostrarOps = true;
    tiempoOps.restart();
}

bool Humano::efectoOps() {
    if (mostrarOps) {
        if (tiempoOps.getElapsedTime().asSeconds() >= 2) {
            mostrarOps = false;
        }
    }
    return mostrarOps;
}