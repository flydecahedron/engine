/*
 * Game.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#include "Game.hpp"

void Game::run(){
	sf::RenderWindow window(sf::VideoMode(windowHeight, windowWidth), "bitch");
	entityx::EntityX world;
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		window.display();
	}
}

