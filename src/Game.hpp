/*
 * Game.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <entityx/entityx.h>
#include "Renderer.hpp"
#include "Components.hpp"
#include "Systems.hpp"
#include "Level.hpp"
namespace ex = entityx;

class Game{
public:
	Game()
	:renderer(),
	level(renderer) {}

	Renderer& getRenderer() {return renderer; }
	void run();

private:
	Renderer renderer;
	Level level;

};// game namespace
#endif /* GAME_HPP_ */
