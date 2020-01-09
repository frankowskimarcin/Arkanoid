#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>


Game::Game() : window{ sf::VideoMode{800,600}, "Arkanoid", sf::Style::Default }, newBlock(), ball(150, 200), vaus(400, 550) {
	window.setFramerateLimit(60);
}

void Game::run() {
	std::vector<Block> blocks;
	sf::Event event;
	for (float i = 0; i < blocksY; i++)
		for (float j = 0; j < blocksX; j++) {
			//metoda oczekuje wartosci konstruktora bloczka, tworzy bloczek na koncu kontenera
			//push back robi kopie, korzysta z wczesniej stworzonego obiektu
			blocks.emplace_back((j + 1) * (newBlock.getWidth() + 10), (i + 2) * (newBlock.getHeight() + 5));
		}
	while (true) {
		window.clear(sf::Color::Black);
		window.pollEvent(event);

		if (event.type == sf::Event::Closed) {
			window.close();
			break;
		}
		ball.update();
		paddle->update();
		collisionTest(paddle, ball);


		for (Block& block : blocks)
			if (collisionTest(block, ball)) break;

		try {
			auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDestroyed();});
			blocks.erase(iterator, end(blocks));
		}
		catch (std::invalid_argument) {
			std::cout << "remove blocks error";
		}

		window.draw(ball);
		window.draw(*paddle);

		for (Block& block : blocks) //dzialanie typu foreach
			window.draw(block);

		if (blocks.empty()) {
			std::cout << "You win!" << std::endl;
			loadScore(0);
			sf::sleep(sf::seconds(1));
			break;
		}
		if (ball.getVelocity() == 0) {
			std::cout << "You lose!" << std::endl;
			loadScore(1);
			sf::sleep(sf::seconds(1));
			break;
		}
		window.display();
	}
}

bool Game::isIntersecting(Block& block, Ball& ball) { //czy dwa ksztalty sie przecinaj¹
	return block.right() >= ball.left() && block.left() <= ball.right() && block.bottom() >= ball.top() && block.top() <= ball.bottom();
}

bool Game::isIntersecting(Rectangle* p, Ball& b) {
	return p->right() >= b.left() && p->left() <= b.right() && p->bottom() >= b.top() && p->top() <= b.bottom();
}

bool Game::collisionTest(Rectangle* paddle, Ball& ball) { //zamiast getLocalBounds.intersects
	if (!isIntersecting(paddle, ball)) return false;
	ball.moveUp();
	if (ball.getPosition().x < paddle->getPosition().x) {
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paddle->getPosition().x) {
		ball.moveRight();
	}
}

bool Game::collisionTest(Block& block, Ball& ball) {
	if (!isIntersecting(block, ball)) return false;

	block.destroy();

	float diffLeft = ball.right() - block.left();
	float diffRight = block.right() - ball.left();
	float diffTop = ball.bottom() - block.top();
	float diffBottom = block.bottom() - ball.top();

	bool hitLeft(abs(diffLeft) < abs(diffRight));
	bool hitTop(abs(diffTop) < abs(diffBottom));

	float minDiffX = (hitLeft ? diffLeft : diffRight);
	float minDiffY = (hitTop ? diffTop : diffBottom);

	if (abs(minDiffX) < abs(minDiffY)) {
		hitLeft ? ball.moveLeft() : ball.moveRight();
	}
	else {
		hitTop ? ball.moveUp() : ball.moveDown();
	}
}

void Game::loadScore(int result) {
	std::fstream plik;
	plik.open("score.txt");
	std::string win, lose;
	int w, l;
	if (!plik.good())
		throw "Brak pliku";
	else {
		plik >> win;
		plik >> w;
		plik >> lose;
		plik >> l;
		result == 0 ? w++ : l++;

		plik.seekg(0);
		plik.clear();

		plik << win << " ";
		plik << w << " ";
		plik << lose << " ";
		plik << l << " ";

		std::cout << win << ": " << w << std::endl;
		std::cout << lose << ": " << l << std::endl;
	}
	plik.close();
}