#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

class Game{

	sf::RenderWindow window;
	Block newBlock;
	unsigned const blocksX = 10, blocksY = 4;
	Ball ball;
	Paddle vaus;
	Rectangle* paddle = &vaus;

public:
	Game();
	~Game() = default;
	void run();
	void loadScore(int result);
	bool isIntersecting(Block& block, Ball& ball);
	bool isIntersecting(Rectangle* p, Ball& b);
	bool collisionTest(Rectangle* paddle, Ball& ball);
	bool collisionTest(Block& block, Ball& ball);
};

