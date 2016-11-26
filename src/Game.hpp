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
namespace ex = entityx;
class Game{
public:

	sf::RenderWindow window;
	ex::EntityX world;

};



#endif /* GAME_HPP_ */
