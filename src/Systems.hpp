/*
 * Systems.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef SYSTEMS_HPP_
#define SYSTEMS_HPP_

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Components.hpp"
#include "Renderer.hpp"
#include "AudioPlayer.hpp"
#include "Events.hpp"
#include <iostream>
namespace ex = entityx;

class RenderSystem : public ex::System<RenderSystem> {
public:
	explicit RenderSystem(Renderer& renderer) : renderer(renderer) {}

	void update(entityx::EntityManager &es, entityx::EventManager &events, ex::TimeDelta dt) override {
		renderer.drawBegin();
		es.each<BasePhysics, Primitive>([this](ex::Entity entity, BasePhysics& basePhysics, Primitive& primitive){
			//std::cout << primitive.shape->getPosition().x << std::endl;
			primitive.shape->setPosition(basePhysics.position);
			//primitive.shape->setRotation(basePhysics.rotation);
			renderer.draw(*primitive.shape);
		});
		renderer.drawEnd();
	};

private:
	Renderer& renderer;
};// RenderSystem class

class SpawnSystem : public ex::System<SpawnSystem> {
public:
	explicit SpawnSystem(){}

	void update(entityx::EntityManager &es, entityx::EventManager &events, ex::TimeDelta dt) override {
		ex::Entity entity = es.create();
		sf::Vector2f position, direction;
		position.x = rand() % 600 + 1; // 0 to 600
		position.y = rand() % 800 + 1; // 0 to 800
		direction.x = rand() % 600 + 1;
		direction.y = rand() % 800 + 1;
		float rotation = rand() % 360 + 1;
		entity.assign<BasePhysics>(position, direction, rotation);
		int radius = rand() % 100 + 1;
		std::shared_ptr<sf::CircleShape> shape = std::make_shared<sf::CircleShape>(radius);
		sf::Color color;
		color.r = rand() % 255 + 1;
		color.g = rand() % 255 + 1;
		color.b = rand() % 255 + 1;
		entity.assign<Primitive>(std::move(shape), color);
		events.emit<PlaySound>("punch");
	}
}; // SpawnSystem class

class AudioSystem : public ex::System<AudioSystem>, public ex::Receiver<AudioSystem> {
public:
	explicit AudioSystem(AudioPlayer& audioPlayer)
	:audioPlayer(audioPlayer){}
	void configure(ex::EventManager &events){
		events.subscribe<PlaySound>(*this);
	}
	void update(entityx::EntityManager &es, entityx::EventManager &events, ex::TimeDelta dt) override {

	}

	void receive(const PlaySound &playSound){
		std::cout << playSound.name << std::endl;
		audioPlayer.play(playSound.name);
	}
private:
	AudioPlayer& audioPlayer;
}; // AudioSystem class

#endif /* SYSTEMS_HPP_ */
