/*
 * Renderer.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef RENDERER_HPP_
#define RENDERER_HPP_
#include <SFML/Graphics.hpp>
class Renderer{
public:
	Renderer()
	:window(sf::VideoMode(800,600), "fucking work"){}
	~Renderer();
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
	sf::RenderWindow window;

};



#endif /* RENDERER_HPP_ */
