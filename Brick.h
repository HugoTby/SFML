#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics.hpp>

class Brick
{
private:
	sf::RectangleShape shape;
	sf::Vector2f position;
	sf::Vector2f size;
	int health;
public:
	Brick(int x, int y, int width, int height, int health);
	~Brick();
	void draw(sf::RenderWindow& window);
	sf::Color getColorFromLife();
	bool isAlive();
	void hit();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
};

#endif