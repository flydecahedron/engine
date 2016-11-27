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

	sf::RenderWindow window;
};



#endif /* GAME_HPP_ */
