#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Brick.h"
#include "Player.h"

double mapValue(double x, double a, double b, double c, double d) {
	double y = (x - a) / (b - a) * (d - c) + c;
	return y;
}

int main(int argc, char** argv)
{
	std::deque<Brick*> bricks;
	Ball ball(200, 250, 10, 550); 
	Player player(550, 100, 11);
	sf::RenderWindow window(sf::VideoMode(1200, 700), "Projet SFML");


	int numBricksPerLine = 10; 
	int brickWidth = 80; 
	int brickHeight = 30; 
	int horizontalSpacing = (window.getSize().x - numBricksPerLine * brickWidth) / (numBricksPerLine + 1); 
	int verticalSpacing = 30; 
	for (int i = 0; i < 4; i++) { 
		for (int j = 0; j < numBricksPerLine; j++) { 
			int x = horizontalSpacing + j * (brickWidth + horizontalSpacing); 
			int y = verticalSpacing + i * (brickHeight + verticalSpacing); 
			bricks.push_back(new Brick(x, y, brickWidth, brickHeight, 3));
		}
	}


	sf::RectangleShape rdr2;
	rdr2.setSize(sf::Vector2f(window.getSize().x, 1));



	sf::RectangleShape windowRect;
	windowRect.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

	sf::Clock clock;
	sf::Vector2i mousePos;
	float elapsedTime = 0, maxBallPosY = 550.f;
	int life = 10;
	

	while (window.isOpen())
	{

		elapsedTime = clock.restart().asSeconds();


		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		float playerSpeed = 300.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			player.move(-playerSpeed * elapsedTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.move(playerSpeed * elapsedTime);
		}

		ball.move(elapsedTime);
		ball.manageCollisionWithWindow(window);

		window.clear();

		for (int i = 0; i < window.getSize().y; i++)
		{
			double mappedValue = mapValue(i, 0, window.getSize().y, 0, 200);
			rdr2.setFillColor(sf::Color(mappedValue, mappedValue, 255));
			rdr2.setPosition(0, i);
			window.draw(rdr2);

		}
		player.update(elapsedTime);
		player.draw(window);
		ball.draw(window);
		for (int i = 0; i < bricks.size(); i++)
		{
			if (bricks[i]->isAlive())
			{
				bricks[i]->draw(window);
				ball.manageCollisionWithBrick(bricks[i]);
			}
			else
			{
				bricks[i]->destroyAndDelete(bricks);
			}
		}
		window.display();

		ball.manageCollisionWithPlayer(player);

		
	}

	return 0;
}
