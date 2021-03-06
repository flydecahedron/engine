/*
 * Game.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: eroc
 */

#include "Game.hpp"
#include "Systems.h"

bool Game::instantiated;

void Game::run(){
	renderer.getWindow().setFramerateLimit(60);
	//testGuiSetup(gui);
	sf::Clock clock;
	while (renderer.isOpen()){
		sf::Event event;
		while (renderer.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				renderer.closeWindow();
			}
			input.poll(event);
			randomSpawner(ecs);
			drawEntities(ecs, renderer);
//			gui.handleEvent(event);
		}
		sf::Time elapsed = clock.restart();
		//level.update(elapsed.asSeconds());
	}
}// run



