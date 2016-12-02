/*
 * Game.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>
#include "Renderer.hpp"
#include "Components.hpp"
namespace ex = entityx;

namespace game{

int windowHeight = 800;
int windowWidth = 600;
std::string windowTitle = "balls";

static Renderer renderer;

void run(){
	entityx::EntityX world;
	while (renderer.getWindow().isOpen()){
		sf::Event event;
		while (renderer.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				renderer.closeWindow();
		}
		renderer.drawBegin();

		renderer.drawEnd();
	}
}// run

}// game namespace
#endif /* GAME_HPP_ */
