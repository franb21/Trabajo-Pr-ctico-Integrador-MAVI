#pragma once
#include"libs.h"

class Mira {
private:
	Texture textMira;
	Sprite mira;
public:
	Mira();
	void moverMira(float x, float y);
	void dibujar(RenderWindow& Ventana);
};