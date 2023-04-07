#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"
#include "Brick.h"

double mapValue(double x, double a, double b, double c, double d) {
	double y = (x - a) / (b - a) * (d - c) + c;
	return y;
}

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Projet SFML");
	sf::RectangleShape rectanglehaut(sf::Vector2f(800, 50));
	sf::RectangleShape rectanglebas(sf::Vector2f(800, 550));
	sf::CircleShape circle;
	circle.setRadius(25);
	circle.setPosition(0, 0);
	circle.setFillColor(sf::Color(48, 51, 48));
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(1);

	sf::RectangleShape rdr2;
	
	rdr2.setSize(sf::Vector2f(window.getSize().x, 1));

	Brick b();


	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		rectanglehaut.setPosition(0, 0);
		rectanglehaut.setFillColor(sf::Color(48, 51, 48));
		
		/*rectanglehaut.setOutlineColor(sf::Color::Red);
		rectanglehaut.setOutlineThickness(5);*/                  // Bordure

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
		window.draw(circle);
		for (int i = 0; i < window.getSize().y; i++)
		{
			double mappedValue = mapValue(i, 0, window.getSize().y, 0, 200);
			rdr2.setFillColor(sf::Color(mappedValue, mappedValue, 255));
			rdr2.setPosition(0, i);
			window.draw(rdr2);
		}

		// afficher le contenu de la fenêtre à l'écran
		window.display();
	}

	return 0;
}
