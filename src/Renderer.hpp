/*
 * Renderer.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef RENDERER_HPP_
#define RENDERER_HPP_
#include "utils/Uncopyable.hpp"
#include <cassert>
#include <SFML/Graphics.hpp>
class Renderer : private Uncopyable{
public:
	Renderer()
	:window(sf::VideoMode(800,600), "fucking work"){
		assert(!instantiated);
		instantiated = true;
	}
	~Renderer(){
		window.close();
		instantiated = false;
	}
	void draw(const sf::Drawable& drawable);
	void drawBegin();
	void drawEnd();
	void setupWindow();
	void closeWindow();
	bool isOpen();
	bool pollEvent(sf::Event& event);
	sf::RenderWindow& getWindow(){
		return window;
	}

private:
	static bool instantiated;
	sf::RenderWindow window;


};



#endif /* RENDERER_HPP_ */
