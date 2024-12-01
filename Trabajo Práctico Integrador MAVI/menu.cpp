#include "menu.h"

Menu::Menu(RenderWindow& Ventana) : Ventana(Ventana){
	fondoMenu.loadFromFile("fondoMenu.png");
	fondoMenuJugar.loadFromFile("fondoJugar.png");
	fondoMenuSalir.loadFromFile("fondoSalir.png");
	fondoInstrucciones[0].loadFromFile("instrucciones1.png");
	fondoInstrucciones[1].loadFromFile("instrucciones2.png");

	intro.setTexture(fondoInstrucciones[0]);
	fondo.setTexture(fondoMenu);
}

void Menu::mostrarInstrucciones() {
	int indiceIntro = 0;

	while (Ventana.isOpen()) {
		Event evt;
		while (Ventana.pollEvent(evt)) {

			switch (evt.type) {

			case Event::Closed:
				Ventana.close();
				break;

			case Event::MouseMoved:
				mira.moverMira(evt.mouseMove.x, evt.mouseMove.y);

			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Left) {
					indiceIntro++;

					if (indiceIntro == 1) {
						intro.setTexture(fondoInstrucciones[indiceIntro]);
					}
					else if (indiceIntro == 2) {
						return;
					}
				}
			}
		}
		Ventana.clear();
		Ventana.draw(intro);
		mira.dibujar(Ventana);
		Ventana.display();
	}
}

bool Menu::iniciar() {
	Ventana.setMouseCursorVisible(false);

	while (Ventana.isOpen()) {
		Event evt;
		while (Ventana.pollEvent(evt)) {

			switch (evt.type) {

			case Event::Closed:
				Ventana.close();
				break;

			case Event::MouseMoved:
				mira.moverMira(evt.mouseMove.x, evt.mouseMove.y);

				if (evt.mouseMove.x >= 460 && evt.mouseMove.x <= 720 && evt.mouseMove.y >= 475 && evt.mouseMove.y <= 567) {
					fondo.setTexture(fondoMenuJugar);
				}
				else if (evt.mouseMove.x >= 470 && evt.mouseMove.x <= 710 && evt.mouseMove.y >= 610 && evt.mouseMove.y <= 705) {
					fondo.setTexture(fondoMenuSalir);
				}
				else {
					fondo.setTexture(fondoMenu);
				}
				break;

			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Left) {

					if (evt.mouseButton.x >= 460 && evt.mouseButton.x <= 720 && evt.mouseButton.y >= 475 && evt.mouseButton.y <= 565) {
						mostrarInstrucciones();
						return true;
					}
					if (evt.mouseButton.x >= 470 && evt.mouseButton.x <= 710 && evt.mouseButton.y >= 610 && evt.mouseButton.y <= 705) {
						Ventana.close();
						return false;
					}
				}
				break;
			}
		}

		Ventana.clear();
		Ventana.draw(fondo);
		mira.dibujar(Ventana);
		Ventana.display();
	}
	return false;
}

