/*
 * Game.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: eroc
 */

#include "Game.hpp"

void Game::run(){
	renderer.getWindow().setFramerateLimit(60);
	sf::Clock clock;
	while (renderer.isOpen()){
		sf::Event event;
		while (renderer.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				renderer.closeWindow();
		}
		sf::Time elapsed = clock.restart();
		level.update(elapsed.asSeconds());
	}
}// run



