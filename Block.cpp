#include "Block.h"
#include <time.h>

Block::Block(float valX, float valY) {
	srand(time(NULL));
	shape.setPosition(valX, valY);
	shape.setSize({ sf::Vector2f(this->width, this->height) });
	shape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
	shape.setOrigin(width / 2.f, height / 2.f);
}

bool Block::isDestroyed() {
	return this->destroyed;
}

void Block::destroy() {
	this->destroyed = true;
}

sf::Vector2f Block::getSize() {
	return shape.getSize();
}

//void Block::update() {
//
//}