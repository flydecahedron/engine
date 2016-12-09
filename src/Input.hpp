/*
 * Input.hpp
 *
 *  Created on: Dec 9, 2016
 *      Author: eroc
 */

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "utils/Uncopyable.hpp"
#include "Events.hpp"
#include <unordered_map>
#include <cassert>
#include "Commands.hpp"

/**
 *
 */
class Input : private Uncopyable {
public:
	Input();
	~Input();
	void bind(const sf::Event& userInput, const Command& command);
	Command getBinding(sf::Event& userInput);
private:
	static bool instantiated;
	std::unordered_map<sf::Event, Command> bindings;
};

#endif /* INPUT_HPP_ */
