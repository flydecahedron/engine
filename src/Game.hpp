/*
 * Game.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <cassert> // assert one instance exists
#include "utils/Uncopyable.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <entityx/entityx.h>
#include "Renderer.hpp"
#include "Components.hpp"
#include "Level.hpp"
#include "Systems.hpp"
#include "Audio.hpp"
#include "Input.hpp"
namespace ex = entityx;

class Game : private Uncopyable{
public:
	Game()
	:renderer(),
	 audio(),
	 input(),
	level(renderer, audio, input)
	{
		assert(!Game::instantiated);
		instantiated = true;
		audio.addSound("punch","assets/sounds/punch.wav");
		audio.addMusic("music", "assets/sounds/music.wab");

	}

	~Game(){
		instantiated = false;
	}
	Renderer& getRenderer() {return renderer; }
	void run();

private:
	static bool instantiated;
	Renderer renderer;
	Audio audio;
	Input input;
	// Level should be last here so it initializes last.
	// Its constructor depends on everything else in this class
	Level level;


};// game namespace
#endif /* GAME_HPP_ */
