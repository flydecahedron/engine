/*
 * Action.cpp
 *
 *  Created on: Dec 18, 2016
 *      Author: eroc
 */
#include "Action.hpp"

	Action::Action(sf::Keyboard::Key key, sf::Event::EventType eventType)
	:eventType_(eventType),
	 key_(key),
	 mouseButton_(){}

	Action::Action(sf::Mouse::Button mouseButton, sf::Event::EventType eventType)
	:eventType_(eventType),
	 key_(),
	 mouseButton_(mouseButton){}

	Action::~Action(){}



