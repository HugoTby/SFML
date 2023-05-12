#include "Brick.h"

Brick::Brick(int x, int y, int width, int height, int health)
{
	
	this->position = sf::Vector2f(x, y);
	this->size = sf::Vector2f(width, height);
	this->shape = sf::RectangleShape(size);
	this->health = health;
	shape.setFillColor(sf::Color::Green); 
	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(1); 
	this->lastCollisionTime = 0; 
}

Brick::~Brick()
{
}

void Brick::draw(sf::RenderWindow& window)
{
	if (isAlive())
	{
		
		shape.setPosition(position);
		window.draw(shape);
	}
}
bool Brick::isAlive()
{
	
	return health > 0;
}

void Brick::destroyAndDelete(std::deque<Brick*>& bricks)
{
	bricks.erase(std::remove(bricks.begin(), bricks.end(), this), bricks.end());

	delete this;
}

void Brick::hit()
{
	if (isAlive())
	{

		if (clock.getElapsedTime().asSeconds() - lastCollisionTime >= 0.1) {
			health--;
			setColor();
			lastCollisionTime = clock.getElapsedTime().asSeconds();
		}
	}
}
sf::Vector2f Brick::getPosition()
{
	return sf::Vector2f();
}

sf::Vector2f Brick::getSize()
{
	return sf::Vector2f();
}

sf::RectangleShape Brick::getShape()
{
	
	return shape;
}

void Brick::setColor()
{
	this->shape.setOutlineColor(sf::Color::White); 
	this->shape.setOutlineThickness(1); 
	if (this->health == 2)
	{
		this->shape.setFillColor(sf::Color(255, 165, 0)); 
	}
	else if (this->health == 1)
	{

		this->shape.setFillColor(sf::Color::Red); 
	}
}

bool Brick::operator==(const Brick& other) const
{
	return this == &other;
}
