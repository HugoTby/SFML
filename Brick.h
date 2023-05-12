#ifndef BRICK_H
#define BRICK_H
#include <deque>

#include <SFML/Graphics.hpp>

class Brick
{
private:
	sf::Vector2f position;
	sf::Vector2f size; 
	sf::RectangleShape shape; 
	int health;
	float lastCollisionTime; 
	sf::Clock clock; 
	void setColor();
public:
	Brick(int x, int y, int width, int height, int health);
	~Brick(); 
	void draw(sf::RenderWindow& window); 
	bool isAlive();
	void destroyAndDelete(std::deque<Brick*>& bricks);
	void hit(); 
	sf::Vector2f getPosition(); 
	sf::RectangleShape getShape();
	sf::Vector2f getSize(); 
	bool operator==(const Brick& other) const; 

};

#endif
