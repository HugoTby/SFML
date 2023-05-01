#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(int x, int y, int width, int height); // constructeur
	~Player(); // destructeur

	// ajouter une fonction pour dessiner le joueur
	void draw(sf::RenderWindow& window);

	// ajouter une fonction pour déplacer le joueur vers la gauche
	void moveLeft(float elapsedTime);

	// ajouter une fonction pour déplacer le joueur vers la droite
	void moveRight(float elapsedTime);

private:
	sf::Vector2f position;
	sf::Vector2f oldPosition;
	sf::RectangleShape shape;
	float speed;
};
