#pragma once
#include"libs.h"
#include "mira.h"

class Menu {
private:
	RenderWindow& Ventana;
	Texture fondoMenu;
	Texture fondoMenuJugar;
	Texture fondoMenuSalir;
	Texture fondoInstrucciones[2];
	Sprite fondo;
	Sprite intro;
	Mira mira;
public:
	Menu(RenderWindow& Ventana);
	void mostrarInstrucciones();
	bool iniciar();
};