#pragma once
#include <SFML/Graphics.hpp>
#include "Rectangle.h"

class Block: public Rectangle{
	bool destroyed = false;
	float width = 60.0f;
	float height = 20.0f;

public:
	Block(float valX, float valY);
	Block() { };
	~Block() = default;

	float getWidth() { return width; }
	float getHeight() { return height; }

	void update() {}
	bool isDestroyed();
	void destroy();
	sf::Vector2f getSize();
};

