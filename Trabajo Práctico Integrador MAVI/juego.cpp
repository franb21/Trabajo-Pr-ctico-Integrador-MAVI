#include "juego.h"

Juego::Juego(RenderWindow& Ventana) : Ventana(Ventana) {
    textfondoJuego.loadFromFile("fondoJuego.png");
    textureVida[0].loadFromFile("vida1.png");
    textureVida[1].loadFromFile("vida2.png");
    textureVida[2].loadFromFile("vida3.png");
    fuenteText.loadFromFile("PressStart.ttf");

    fondoJuego.setTexture(textfondoJuego);
    vida.setTexture(textureVida[2]);
    vida.setPosition(959, 8);

    vidaText.setFont(fuenteText);
    vidaText.setCharacterSize(27);
    vidaText.setFillColor(Color::Black);
    vidaText.setPosition(820, 12);
    vidaText.setString("Vidas: ");

    enemigosText.setFont(fuenteText);
    enemigosText.setCharacterSize(27);
    enemigosText.setFillColor(Color::Black);
    enemigosText.setPosition(14, 12);
    enemigosText.setString("Aliens eliminados: 0");
}

void Juego::spawnEntidad() {
    bool esEnemigo = rand() % 2;
    int esEnemigoProb = rand() % 100;
    if (esEnemigoProb < 70) {
        enemigo.spawn();
        hayEnemigo = true;
    }
    else {
        humano.spawn();
        hayHumano = true;
    }
}

void Juego::controlVidas() {
    vidas--;
    indiceVida--;
    vida.setTexture(textureVida[indiceVida]);
    if (vidas == 0) {
        puntuacionFinal = puntuacion - (humanosMuertos * 2);
        GameOver gameover(Ventana, puntuacionFinal);
        gameover.iniciar();
        return;
    }
}

void Juego::iniciar() {
    Ventana.setMouseCursorVisible(false);

    Menu menu(Ventana);
    bool iniciarMenu = menu.iniciar();
    if (!iniciarMenu) {
        return;
    }

    spawnEntidad();

    while (Ventana.isOpen()) {
        Event evt;
        while (Ventana.pollEvent(evt)) {

            switch (evt.type) {

            case Event::Closed:
                Ventana.close();
                break;

            case Event::MouseMoved:
                mira.moverMira(evt.mouseMove.x, evt.mouseMove.y);
                break;

            case Event::MouseButtonPressed:
                if (evt.mouseButton.button == Mouse::Left) {

                    if (hayEnemigo && enemigo.estaVivo(evt.mouseButton.x, evt.mouseButton.y)) {
                        puntuacion++;
                        enemigosText.setString("Aliens derrotados: " + to_string(puntuacion));
                        hayEnemigo = false;
                    }
                    else if (hayHumano && humano.estaVivo(evt.mouseButton.x, evt.mouseButton.y)) {
                        humano.activarEfecto();
                        humanosMuertos++;
                        controlVidas();
                        hayHumano = false;
                    }
                    if (!hayEnemigo && !hayHumano && !enemigo.efectoZap() && !humano.efectoOps()) {
                        spawnEntidad();
                    }
                }
                break;
            }
        }
        if (hayHumano && humano.tiempoVida()) {
            hayHumano = false;
        }
        if (hayEnemigo && enemigo.disparar()) {
            controlVidas();
            hayEnemigo = false;
        }

        if (!enemigo.efectoZap() && !humano.efectoOps()) {
            if (!hayEnemigo && !hayHumano) {
                spawnEntidad();
            }
        }
        Ventana.clear();
        Ventana.draw(fondoJuego);
        Ventana.draw(enemigosText);
        Ventana.draw(vidaText); 
        Ventana.draw(vida);
        if (hayEnemigo || enemigo.efectoZap()) {
            enemigo.dibujar(Ventana);
        }
        if (hayHumano || humano.efectoOps()) {
            humano.dibujar(Ventana);
        }
        mira.dibujar(Ventana);
        Ventana.display();
    }
}
