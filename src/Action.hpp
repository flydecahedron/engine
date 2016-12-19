/*
 * Action.hpp
 *
 *  Created on: Dec 18, 2016
 *      Author: eroc
 */

#ifndef ACTION_HPP_
#define ACTION_HPP_
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
enum InputType{
	keyboard,
	mouse,
	joystick
};

class Action {
public:
	Action(sf::Keyboard::Key key, sf::Event::EventType eventType);
	Action(sf::Mouse::Button mouseButton, sf::Event::EventType eventType);
	~Action();
	bool isActive(sf::Event& event);
private:
	InputType inputType_;
	sf::Event::EventType eventType_;
	sf::Keyboard::Key key_;
	sf::Mouse::Button mouseButton_;
};

#endif /* ACTION_HPP_ */
