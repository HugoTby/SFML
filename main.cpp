#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"
#include "Brick.h"

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Projet SFML");
	sf::RectangleShape rectanglehaut(sf::Vector2f(800, 50));
	sf::RectangleShape rectanglebas(sf::Vector2f(800, 550));


	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen())
	{
		rectanglehaut.setPosition(0, 0);
		rectanglehaut.setFillColor(sf::Color(48, 51, 48));

		rectanglebas.setPosition(0, 50);
		rectanglebas.setFillColor(sf::Color(82, 82, 82));

		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (window.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// effacer la fen�tre (avec une couleur de fond)
		window.clear(sf::Color::Black);

		// dessiner le rectangle sur la fen�tre
		window.draw(rectanglehaut);
		window.draw(rectanglebas);

		// afficher le contenu de la fen�tre � l'�cran
		window.display();
	}

	return 0;
}
