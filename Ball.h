#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable{ //dziedziczy z interfejsu
	sf::CircleShape shape;
	const float circleRadius = 10.0f;
	float circleVelocity = 5.0f;
	sf::Vector2f velocity{ circleVelocity, circleVelocity };

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	Ball(float valX, float valY);
	Ball() = delete;
	~Ball() = default;

	float getVelocity() { return this->circleVelocity; }

	void update();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	sf::Vector2f getPosition();

	float left(); //zwraca wspolrzedne danej krawedzi
	float right();
	float top();
	float bottom();
};

