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
#include "Action.hpp"
#include <unordered_map>
#include <cassert>
#include "Commands.hpp"
#include <iostream>

/**
 *
 */
class Input : private Uncopyable {
public:
	Input();
	~Input();
	void bind(const Action action, const std::string& command);
	Action getBinding(const std::string& command);
	std::vector<std::string> poll(sf::Event& event);
private:
	static bool instantiated_;
	std::unordered_map<std::string, Action> bindings_;
};

#endif /* INPUT_HPP_ */
