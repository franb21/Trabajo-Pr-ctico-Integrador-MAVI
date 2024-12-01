#include "gameOver.h"

GameOver::GameOver(RenderWindow& Ventana, int puntuacionFinal) : Ventana(Ventana), puntuacionFinal(puntuacionFinal) {
    textGameOver.loadFromFile("fondoGameOver.png");
    fuenteText.loadFromFile("PressStart.ttf");

    gameOver.setTexture(textGameOver);
    puntuacionText.setFont(fuenteText);
    puntuacionText.setCharacterSize(41);
    puntuacionText.setFillColor(Color::Green);
    puntuacionText.setString("Puntuación  final: " + to_string(puntuacionFinal));
    puntuacionText.setPosition(150, 490);
}

void GameOver::iniciar() {
    while (Ventana.isOpen()) {
        Event evt;
        while (Ventana.pollEvent(evt)) {

            switch (evt.type) {

            case Event::Closed:
                Ventana.close();
                break;
            }
        }
        Ventana.clear();
        Ventana.draw(gameOver);
        Ventana.draw(puntuacionText);
        Ventana.display();
    }
}