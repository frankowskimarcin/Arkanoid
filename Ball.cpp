#include "Ball.h"
#include "Paddle.h"

Ball::Ball(float valX,float valY) {
	shape.setPosition(valX, valY);
	shape.setRadius(this->circleRadius);
	shape.setFillColor(sf::Color::Cyan);
	shape.setOrigin(this->circleRadius, this->circleRadius); //przesuniecie srodka ciezkosci
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const { //metoda nie zmienia pól klasy
	target.draw(this->shape, state);
}

void Ball::update() {
	shape.move(this->velocity);

	if (this->left() < 0) velocity.x = circleVelocity;
	else if (this->right() > 800) velocity.x = -circleVelocity;

	if (this->top() < 0) velocity.y = circleVelocity;
	else if (this->bottom() > 600) circleVelocity=0; // TODO: tutaj friend class i display game over
}

float Ball::left() {
	return this->shape.getPosition().x - shape.getRadius();
}

float Ball::right() {
	return this->shape.getPosition().x + shape.getRadius();
}

float Ball::top() {
	return this->shape.getPosition().y - shape.getRadius();
}

float Ball::bottom() {
	return this->shape.getPosition().y + shape.getRadius();
}

void Ball::moveDown() {
	this->velocity.y = circleVelocity;
}

void Ball::moveUp() {
	this->velocity.y = -circleVelocity;
}

void Ball::moveRight() {
	this->velocity.x = circleVelocity;
}

void Ball::moveLeft() {
	this->velocity.x = -circleVelocity;
}

sf::Vector2f Ball::getPosition() {
	return shape.getPosition();
}