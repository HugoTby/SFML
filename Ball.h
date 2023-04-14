#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::CircleShape shape; // Dessiner la balle sur l'écran
	sf::Vector2f oldPosition;
	sf::Vector2f position;
	float speed;
	int radius;
	sf::Vector2f direction;
	static bool isRandInitialized;
	double randomizeAngle();
	void setAngle(double angle);

	

	//void manageCollisionWith(Player& player); //Collisions plateforme

public:
	Ball(int x, int y, int radius, float speed);
	~Ball();
	void move(float ellapsedTime);
	void draw(sf::RenderWindow& window);
	float getSpeed();
	void setSpeed(float newSpeed);
	void setPosition(sf::Vector2f newPosition);
	void setDirection(sf::Vector2f newDirection);
	void manageCollisionWith(sf::RenderWindow& window); //Collisions bordures
};

#endif // BALL_H
