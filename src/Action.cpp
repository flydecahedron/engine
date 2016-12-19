/*
 * Action.cpp
 *
 *  Created on: Dec 18, 2016
 *      Author: eroc
 */
#include "Action.hpp"

	Action::Action(sf::Keyboard::Key key, sf::Event::EventType eventType)
	:inputType_(InputType::keyboard),
	 eventType_(eventType),
	 key_(key),
	 mouseButton_(){}

	Action::Action(sf::Mouse::Button mouseButton, sf::Event::EventType eventType)
	:inputType_(InputType::mouse),
	 eventType_(eventType),
	 key_(),
	 mouseButton_(mouseButton){}

	Action::~Action(){}

	bool Action::isActive(sf::Event& event){
		switch(inputType_){
		case keyboard:
			if(event.type == eventType_){
				return true;
			}
			else {
				return false;
			}
			break;
		case mouse:
			if(event.type == eventType_){
				return true;
			}
			else{
				return false;
			}
			break;
		case joystick:
			if(event.type == eventType_){
				return true;
			}
			else{
				return false;
			}
		}
		return false;
	}

