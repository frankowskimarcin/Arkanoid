#include "Paddle.h"
#include <SFML\Graphics.hpp>

Paddle::Paddle(float valX, float valY) {
	shape.setPosition(valX, valY);
	shape.setSize(sf::Vector2f(this->width, this->height));
	shape.setOrigin(width / 2.f, height / 2.f);
	shape.setFillColor(sf::Color::Magenta);
}

void Paddle::update() {
	this->shape.move(this->velocity);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left() > 0) {
		velocity.x = -padVelocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < 800) {
		velocity.x = padVelocity;
	}
	else {
		velocity.x=0;
	}
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates state) const { //metoda nie zmienia pól klasy
	target.draw(this->shape, state);
}