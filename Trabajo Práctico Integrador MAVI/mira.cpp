#include"mira.h"

Mira::Mira() {
	textMira.loadFromFile("mira.png");

	mira.setTexture(textMira);

	mira.setScale(80 / (float)textMira.getSize().x, 80 / (float)textMira.getSize().y);
	mira.setOrigin((float)textMira.getSize().x / 2, (float)textMira.getSize().y / 2);
}

void Mira::moverMira(float x, float y) {
	mira.setPosition(x, y);
}

void Mira::dibujar(RenderWindow& Ventana) {
	Ventana.draw(mira);
}