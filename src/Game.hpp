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
#include "Level.hpp"
#include "Systems.hpp"
namespace ex = entityx;

class Game{
public:
	Game()
	:renderer(),
	 audioPlayer(),
	level(renderer, audioPlayer) {}

	Renderer& getRenderer() {return renderer; }
	void run();

private:
	Renderer renderer;
	AudioPlayer audioPlayer;
	// Level should be last here so it initializes last.
	// Its constructor depends on everything else in this class
	Level level;


};// game namespace
#endif /* GAME_HPP_ */
