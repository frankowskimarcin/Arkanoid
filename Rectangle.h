#pragma once
#include <SFML\Graphics.hpp>

class Rectangle : public sf::Drawable {
	friend class Game;
public:
	sf::RectangleShape shape;
	float width;
	float height;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	Rectangle() = default;
	~Rectangle() = default;

	sf::Vector2f getPosition();

	float right();
	float left();
	float top();
	float bottom();

	virtual void update() = 0;
};