/*
 * Events.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: eroc
 */

#ifndef EVENTS_HPP_
#define EVENTS_HPP_

#include <SFML/Audio.hpp>
#include "Commands.hpp"
#include "Input.hpp"

/**
 * Recieved by AudioSystem which calls Audio.play() according to the name given.
 * Eventually add parameters for all parts of sound that is allowed by the SFML api.
 */
struct PlaySound {
	explicit PlaySound(std::string name)
	:name(name) {}
	std::string name;
}; // PlaySound struct

struct CommandEvent{
	explicit CommandEvent(std::string command)
	:command(command) {}
	std::string command;
};

#endif /* EVENTS_HPP_ */
