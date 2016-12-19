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

void Input::poll(sf::Event& event){
	std::cout << "Last frame's command buffer:" << std::endl;
	for(const auto & command : commandBuffer_){
		std::cout << command << ", ";
	}
	std::cout << std::endl;
	for(auto& iter : bindings_){
		if(iter.second.isActive(event)){
			commandBuffer_.emplace_back(iter.first);
			std::cout << "Action is active for: " << iter.first << " command" << std::endl;
		}
	}
}

std::vector<std::string>& Input::getCommandBuffer(){
	return commandBuffer_;
}
