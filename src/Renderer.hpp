/*
 * Renderer.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "Game.hpp"
class Renderer{
public:
	Renderer(sf::RenderWindow& renderWindow):window(renderWindow){}


private:
	sf::RenderWindow& window;

};



#endif /* RENDERER_HPP_ */
