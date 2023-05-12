#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	static constexpr float PLAYER_SPEED = 600.f;
	static constexpr int SCREEN_WIDTH = 1200;
	Player(int y, int width, int height);
	~Player();
	void draw(sf::RenderWindow& window);
	void handleKeyboard(sf::Keyboard::Key key, bool isPressed);
	void update(float deltaTime);
	void move(float distance);

	sf::Vector2f getSurfaceNormal(sf::Vector2f point);
	sf::RectangleShape getShape();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();

private:
	sf::RectangleShape shape;
	sf::Vector2f position;
	sf::Vector2f size;
	int y;
	float velocity = 0.f; 
};
