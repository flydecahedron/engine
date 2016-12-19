/*
 * Input.cpp
 *
 *  Created on: Dec 9, 2016
 *      Author: eroc
 */

#include "Input.hpp"

bool Input::instantiated_;

Input::Input()
:bindings_(){
	assert(!instantiated_);
	//bind(sf::Keyboard::W, "Up");
	//bind(sf::Keyboard::A, "Left");
	//bindKey(sf::Keyboard::S, "Down");
	//bindKey(sf::Keyboard::D, "Right");
	bind(Action(sf::Mouse::Left, sf::Event::MouseButtonPressed), "SpawnCircle");
	for(const auto& iter : bindings_){
		std::cout << "key: " << iter.first  << std::endl;
	}
}

Input::~Input() {
	instantiated_ = false;
}

void Input::bind(const Action action, const std::string& command) {
	bindings_.emplace(command, action);
}

Action Input::getBinding(const std::string& command) {
	return bindings_.at(command);
}

std::vector<std::string> Input::poll(sf::Event& event){
	std::vector<std::string> tempCommands;
	tempCommands.reserve(bindings_.size());
	for(auto& iter : bindings_){
		if(iter.second.isActive(event)){
			tempCommands.emplace_back(iter.first);
		}
	}
	return tempCommands;
}
