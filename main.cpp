#include <SFML/Graphics.hpp>
#include "Ball.h"

double mapValue(double x, double a, double b, double c, double d) {
	double y = (x - a) / (b - a) * (d - c) + c;
	return y;
}


int main(int argc, char **argv)
{
	Ball ball(200, 250, 50, 200);
	sf::RenderWindow window(sf::VideoMode(1200, 700), "Projet SFML");
	/*sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
	sf::RenderWindow window(fullscreenMode, "Projet SFML", sf::Style::Fullscreen);*/

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setFillColor(sf::Color::Cyan);
	rectangle.setOutlineColor(sf::Color::Magenta);
	rectangle.setOutlineThickness(2);
	rectangle.setPosition(100, 100);

	sf::CircleShape circle;
	circle.setRadius(10);
	circle.setPosition(200, 170);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Yellow);
	circle.setOutlineThickness(2);

	sf::RectangleShape rdr2;
	rdr2.setSize(sf::Vector2f(window.getSize().x, 1));

	sf::Clock clock;
	sf::Vector3f xFactor(10, 20, 30);
	float ellapsedTime = 0;


	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen())
	{
		ellapsedTime = clock.restart().asSeconds();

		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (window.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();
		}

		ball.move(ellapsedTime);
		ball.manageCollisionWith(window);

		window.clear();

		for (int i = 0; i < window.getSize().y; i++)
		{
			double mappedValue = mapValue(i, 0, window.getSize().y, 0, 200);
			rdr2.setFillColor(sf::Color(mappedValue, mappedValue, 255));
			rdr2.setPosition(0, i);
			window.draw(rdr2);

			/*double mappedValue = mapValue(i, 0, window.getSize().y, 0, 255);
			rdr2.setFillColor(sf::Color(mappedValue, mappedValue * xFactor.x * ellapsedTime, mappedValue * xFactor.y * ellapsedTime, mappedValue * xFactore.z * ellapsedTime));
			rdr2.setPosition(0, i);
			window.draw(rdr2);*/
		}
		window.draw(rectangle);
		window.draw(circle);
		ball.draw(window);
		window.display();
	}

	return 0;
}