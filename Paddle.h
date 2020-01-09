#pragma once
#include <SFML\Graphics.hpp>
#include "Rectangle.h"

class Paddle: public Rectangle{
	float width = 100.0f;
	float height = 15.0f;
	float padVelocity = 6.0f;
	sf::Vector2f velocity{ padVelocity, 0.f };

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

public:
	Paddle(float valX, float valY);
	Paddle() = delete;
	~Paddle() = default;

	void update();
};

