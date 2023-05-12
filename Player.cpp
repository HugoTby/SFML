#include "Player.h"

Player::Player(int y, int width, int height)
{
	this->y = y;
	this->size = sf::Vector2f(width, height);
	this->position = sf::Vector2f(350, y);
	this->shape = sf::RectangleShape(size);
	shape.setFillColor(sf::Color(sf::Color::Red));
}

Player::~Player()
{
}

r
void Player::draw(sf::RenderWindow& window)
{
	shape.setPosition(position);
	window.draw(shape);
}

sf::Vector2f Player::getPosition()
{
	return position;
}

sf::RectangleShape Player::getShape()
{
	return shape;
}

sf::Vector2f Player::getSize()
{
	return size;
}

void Player::handleKeyboard(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Q)
	{
		velocity = isPressed ? -PLAYER_SPEED : 200;
	}
	else if (key == sf::Keyboard::D)
	{
		velocity = isPressed ? PLAYER_SPEED : 200;
	}
	else
	{
		velocity = 0;
	}
}

void Player::update(float deltaTime)
{

	position.x += velocity * deltaTime;

	if (position.x < 0)
	{
		position.x = 0;
	}
	else if (position.x + size.x > SCREEN_WIDTH)
	{
		position.x = SCREEN_WIDTH - size.x;
	}

	shape.setPosition(position);
}

void Player::move(float distance)
{
	position.x += distance;

	if (position.x < 0)
	{
		position.x = 0;
	}
	else if (position.x + size.x > SCREEN_WIDTH)
	{
		position.x = SCREEN_WIDTH - size.x;
	}

	shape.setPosition(position);
}
sf::Vector2f Player::getSurfaceNormal(sf::Vector2f point)
{
	sf::Vector2f relativePoint = point - position;
	relativePoint.x = std::max(-size.x / 2.0f, std::min(relativePoint.x, size.x / 2.0f));
	relativePoint.y = std::max(-size.y / 2.0f, std::min(relativePoint.y, size.y / 2.0f));


	if (std::abs(relativePoint.x) > std::abs(relativePoint.y))
	{
		return sf::Vector2f(std::signbit(relativePoint.x) ? -1.0f : 1.0f, 0.0f);
	}
	else
	{
		return sf::Vector2f(0.0f, std::signbit(relativePoint.y) ? -1.0f : 1.0f);
	}
}
