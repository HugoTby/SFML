#include "Ball.h"

#include <cstdlib>
#include <ctime>
#define _USE_MATH_DEFINES
#include <math.h>



Ball::Ball(int x, int y, int radius, float speed) :
	position(x, y),
	oldPosition(position),
	direction(1.f, 1.f),
	radius(radius),
	speed(speed),
	lives(lives)
{
	shape.setFillColor(sf::Color::White);
	shape.setRadius(radius);
	setAngle(randomizeAngle());
}

Ball::~Ball()
{
}

double Ball::randomizeAngle()
{
	static bool isRandInitialized = false;
	if (!isRandInitialized)
	{
		srand(time(NULL));
		isRandInitialized = true;
	}

	return (((double)rand() / (double)RAND_MAX) * 60.0) - 30.0;
}

void Ball::setAngle(double angle)
{
	direction.x = sin(angle);
	direction.y = -cos(angle);
}

void Ball::move(float elapsedTime)
{
	oldPosition = position;
	position += elapsedTime * speed * direction;
	shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

float Ball::getSpeed() const
{
	return speed;
}

void Ball::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

void Ball::setPosition(sf::Vector2f newPosition)
{
	position = newPosition;
	oldPosition = position;
	shape.setPosition(position);
}

sf::Vector2f Ball::getPosition() const
{
	return position;
}

void Ball::setDirection(sf::Vector2f newDirection)
{
	direction = newDirection;
}
int Ball::getLives() const
{
	return lives;
}

void Ball::manageCollisionWithWindow(const sf::RenderWindow& window)
{
	if (position.y <= 0)
	{
		direction.y *= -1;
		position.y = 0;
	}
	else if (position.y + 2 * radius >= window.getSize().y)
	{
		direction.y *= -1;
		position.y = window.getSize().y - 2 * radius;
	}

	if (position.x <= 0)
	{
		direction.x *= -1;
		position.x = 0;
	}
	else if (position.x + 2 * radius >= window.getSize().x)
	{
		direction.x *= -1;
		position.x = window.getSize().x - 2 * radius;

	}
}
void Ball::manageCollisionWithPlayer(Player& player)
{
	sf::FloatRect ballBounds = shape.getGlobalBounds();
	sf::FloatRect playermBounds = player.getShape().getGlobalBounds();
	if (ballBounds.intersects(playermBounds))
	{
		double relativeIntersectX = position.x + radius - player.getPosition().x - player.getSize().x / 2.0;

		double normalizedRelativeIntersectionX = relativeIntersectX / (player.getSize().x / 2.0);

		double maxAngle = 45.0; 
		double angle = normalizedRelativeIntersectionX * maxAngle * M_PI / 180.0;

		setAngle(angle);


		double overlap = ballBounds.top + ballBounds.height - playermBounds.top;
		position.y -= overlap;
		direction.y = -std::abs(direction.y);
	}
}

void Ball::manageCollisionWithBrick(Brick* brick)
{
	sf::FloatRect ballBounds = shape.getGlobalBounds();
	sf::FloatRect brickBounds = brick->getShape().getGlobalBounds();
	// Vérifie si la balle touche la brique
	if (ballBounds.intersects(brickBounds))
	{
		double intersectX = position.x + radius - brick->getPosition().x;
		double intersectY = position.y + radius - brick->getPosition().y;
		double deltaX = brick->getSize().x / 2.0 - std::abs(intersectX);
		double deltaY = brick->getSize().y / 2.0 - std::abs(intersectY);

		if (deltaX > deltaY)
		{
			direction.x *= -1;
		}
		else
		{

			direction.y *= -1;
		}


		brick->hit();
		if (intersectX > 0)
		{
			direction.x = std::abs(direction.x);
		}
		else
		{
			direction.x = -std::abs(direction.x);
		}

		if (intersectY > 0)
		{
			direction.y = std::abs(direction.y);
		}
		else
		{
			direction.y = -std::abs(direction.y);
		}
	}
}
