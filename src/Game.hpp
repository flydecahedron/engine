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
/********* LIBS *****************/
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <entityx/entityx.h>
#include <TGUI/TGUI.hpp>

/******** ENGINE ***************/
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
	 gui(renderer.getWindow()),
	level(renderer, audio, input, gui)
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
	tgui::Gui gui;
	// Level should be last here so it initializes last.
	// Its constructor depends on everything else in this class
	Level level;
};// game class

#endif /* GAME_HPP_ */
