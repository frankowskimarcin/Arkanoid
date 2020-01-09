#include "Rectangle.h"

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates state) const { //metoda nie zmienia pól klasy
	target.draw(this->shape, state);
}

sf::Vector2f Rectangle::getPosition() {
	return shape.getPosition();
}

float Rectangle::left() {
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Rectangle::right() {
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Rectangle::top() {
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Rectangle::bottom() {
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}