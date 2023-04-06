#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"
#include "Brick.h"

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Projet SFML");
	sf::RectangleShape rectanglehaut(sf::Vector2f(800, 50));
	sf::RectangleShape rectanglebas(sf::Vector2f(800, 550));


	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		rectanglehaut.setPosition(0, 0);
		rectanglehaut.setFillColor(sf::Color(48, 51, 48));

		rectanglebas.setPosition(0, 50);
		rectanglebas.setFillColor(sf::Color(82, 82, 82));

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// effacer la fenêtre (avec une couleur de fond)
		window.clear(sf::Color::Black);

		// dessiner le rectangle sur la fenêtre
		window.draw(rectanglehaut);
		window.draw(rectanglebas);

		// afficher le contenu de la fenêtre à l'écran
		window.display();
	}

	return 0;
}
