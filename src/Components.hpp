/*
 * Components.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_
#include <SFML/Graphics.hpp>

struct BasePhysics{
	BasePhysics(const sf::Vector2& position, const sf::Vector2f& direction, float rotation)
		: position(position), direction(direction), rotation(rotation) {}

	sf::Vector2f position;
	sf::Vector2f direction;
	float rotation;
};


struct Primitive {
	explicit Primitive(sf::Shape* shape) : shape(shape) {}
	sf::Shape* shape;
};

struct Movement {
	explicit Movement(float speed) : speed(speed) {}

	float speed;
};

struct Player {
	std::string name;
	int score;
};

struct Collidable {
	explicit Collidable(float hitBoxRadius) : radius(hitBoxRadius) {}
	float radius;
};

struct CollisionEvent {
	CollisionEvent(ex::Entity left, ex::Entity right) : left(left), right(right) {}
	ex::Entity left, right;
};

struct Controllable {

};
#endif /* COMPONENTS_HPP_ */
