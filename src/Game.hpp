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
#include <TGUI/TGUI.hpp>

/******** ENGINE ***************/
#include "Renderer.hpp"
#include "Components.hpp"
#include "Systems.hpp"
#include "Audio.hpp"
#include "Input.hpp"
//#include "Gui.hpp"

class Game : private Uncopyable{
public:
	Game()
	:renderer(),
	 audio(),
	 input()
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
	//tgui::Gui gui;

};// game class

#endif /* GAME_HPP_ */
