/*
 * Input.cpp
 *
 *  Created on: Dec 9, 2016
 *      Author: eroc
 */

#include "Input.hpp"

bool Input::instantiated;

Input::Input()
:bindings(){
	assert(!instantiated);
}

Input::~Input() {
	instantiated = false;
}

void Input::bind(const sf::Event& userInput, const Command& command) {
	bindings.emplace(userInput.type, command);

}

void Input::poll(sf::Event& event) {
	currentEvent = event.type;
}

sf::Event Input::get() {
	return currentEvent;
}

Command Input::getBinding(sf::Event& userInput) {
	return bindings[userInput.type];
}
