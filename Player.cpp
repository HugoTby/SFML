#include "Player.h"

Player::Player(int x, int y, int width, int height)
{
	position.x = x;
	position.y = y;
	oldPosition = position;
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(sf::Color(sf::Color::Red));
	speed = 500.0f; // vitesse de déplacement
}

Player::~Player()
{
}

// implémenter la fonction pour dessiner le joueur
void Player::draw(sf::RenderWindow& window)
{
	shape.setPosition(position);
	window.draw(shape);
}

// implémenter la fonction pour déplacer le joueur vers la gauche
void Player::moveLeft(float elapsedTime)
{
	position.x -= speed * elapsedTime;
}

// implémenter la fonction pour déplacer le joueur vers la droite
void Player::moveRight(float elapsedTime)
{
	position.x += speed * elapsedTime;
}
