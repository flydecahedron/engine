/*
 * Events.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: eroc
 */

#ifndef EVENTS_HPP_
#define EVENTS_HPP_

#include <SFML/Audio.hpp>

//eventually add parameters for all parts of sound that is allowed by the SFML api
struct PlaySound {
	explicit PlaySound(std::string name)
	:name(name) {}
	std::string name;
}; // PlaySound struct



#endif /* EVENTS_HPP_ */
