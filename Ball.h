#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Brick.h"

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
	int lives;



	//void manageCollisionWith(Player& player); //Collisions plateforme

public:
	Ball(int x, int y, int radius, float speed);
	~Ball();
	void move(float ellapsedTime);
	void draw(sf::RenderWindow& window);

	float getSpeed() const;
	void setSpeed(float newSpeed);

	void setPosition(sf::Vector2f newPosition);
	sf::Vector2f getPosition() const;
	void setDirection(sf::Vector2f newDirection);
	int getLives() const;
	void manageCollisionWithWindow(const sf::RenderWindow& window);
	void manageCollisionWithPlayer(Player& player);
	void manageCollisionWithBrick(Brick* brick);
};

#endif // BALL_H
