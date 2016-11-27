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
class Game{
public:

	void init(){

	}

	void run();

private:

	sf::RenderWindow window;
	Renderer renderer;
	int windowHeight = 800;
	int windowWidth = 600;
};



#endif /* GAME_HPP_ */
