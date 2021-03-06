/*
 * Components.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct PhysicsComponent{
	PhysicsComponent(const sf::Vector3f& position, const sf::Vector2f& direction, float rotation)
		: position(position), direction(direction), rotation(rotation) {}

	sf::Vector3f position;
	sf::Vector2f direction;
	float rotation;
};

//struct SpriteComponent {
//	sf::Sprite sprite;
//};
struct Primitive {
	explicit Primitive(std::shared_ptr<sf::Shape> shape, sf::Color color) : shape(std::move(shape)), color(color) {
		this->shape->setFillColor(this->color);
	}
	std::shared_ptr<sf::Shape> shape;
	sf::Color color;
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

//struct CollisionEvent {
//	CollisionEvent(ex::Entity left, ex::Entity right) : left(left), right(right) {}
//	ex::Entity left, right;
//};

struct Controllable {

};

struct Sound {
	explicit Sound(const std::string& filename)
	: buffer()
	{
		buffer.loadFromFile(filename);
	}
	sf::SoundBuffer buffer;
};
#endif /* COMPONENTS_HPP_ */
