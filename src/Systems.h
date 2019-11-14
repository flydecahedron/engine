/*
 * Systems.hpp
 *
 *  Created on: Nov 26, 2016
 *      Author: eroc
 */

#ifndef SYSTEMS_HPP_
#define SYSTEMS_HPP_
#include <entt/entity/registry.hpp>
#include "Renderer.hpp"

void drawEntities(entt::registry& ecs, Renderer& renderer);
void randomSpawner(entt::registry& ecs);

//
//#include <entityx/entityx.h>
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <TGUI/TGUI.hpp>
//#include "Components.hpp"
//#include "Renderer.hpp"
//#include "Events.hpp"
//#include "Commands.hpp"
//#include <iostream>
//
//#include "Audio.hpp"
//namespace ex = entityx;
//
//class RenderSystem : public ex::System<RenderSystem> {
//public:
//	explicit RenderSystem(Renderer& renderer, tgui::Gui& gui)
//	:renderer(renderer),
//	 gui(gui){}
//
//	void update(entityx::EntityManager &es, entityx::EventManager &events, ex::TimeDelta dt) override {
//		renderer.drawBegin();
//		es.each<BasePhysics, Primitive>([this](ex::Entity entity, BasePhysics& basePhysics, Primitive& primitive){
//			//std::cout << primitive.shape->getPosition().x << std::endl;
//			primitive.shape->setPosition(basePhysics.position.x, basePhysics.position.y);
//			//primitive.shape->setRotation(basePhysics.rotation);
//			renderer.draw(*primitive.shape);
//		});
//		gui.draw();
//		renderer.drawEnd();
//	};
//
//private:
//	Renderer& renderer;
//	tgui::Gui& gui;
//};// RenderSystem class
//
//class SpawnSystem : public ex::System<SpawnSystem>, public ex::Receiver<SpawnSystem> {
//public:
//	explicit SpawnSystem(){}
//	void configure(ex::EventManager &events){
//		events.subscribe<CommandEvent>(*this);
//	}
//
//	void update(entityx::EntityManager &es, entityx::EventManager &events, ex::TimeDelta dt) override {
//		if(spawnCount_ > 0){
//			ex::Entity entity = es.create();
//			sf::Vector3f position;
//			sf::Vector2f direction;
//			position.x = rand() % 600 + 1; // 0 to 600
//			position.y = rand() % 800 + 1; // 0 to 800
//			direction.x = rand() % 600 + 1;
//			direction.y = rand() % 800 + 1;
//			float rotation = rand() % 360 + 1;
//			entity.assign<BasePhysics>(position, direction, rotation);
//			int radius = rand() % 100 + 1;
//			std::shared_ptr<sf::CircleShape> shape = std::make_shared<sf::CircleShape>(radius);
//			sf::Color color;
//			color.r = rand() % 255 + 1;
//			color.g = rand() % 255 + 1;
//			color.b = rand() % 255 + 1;
//			entity.assign<Primitive>(std::move(shape), color);
//			events.emit<PlaySound>("punch");
//			--spawnCount_;
//		}
//	}
//
//	void receive(const CommandEvent& command){
//		if(command.command == "SpawnCircle"){
//			++spawnCount_;
//		}
//
//	}
//private:
//	int spawnCount_ = 0;
//}; // SpawnSystem class
//
//class AudioSystem : public ex::System<AudioSystem>, public ex::Receiver<AudioSystem> {
//public:
//	explicit AudioSystem(Audio& audioPlayer)
//	:audioPlayer(audioPlayer){}
//	void configure(ex::EventManager &events){
//		events.subscribe<PlaySound>(*this);
//	}
//	void update(entityx::EntityManager &es, entityx::EventManager &events, ex::TimeDelta dt) override {
//
//	}
//
//	void receive(const PlaySound &playSound){
//		std::cout << playSound.name << std::endl;
//		audioPlayer.playSound(playSound.name);
//	}
//private:
//	Audio& audioPlayer;
//}; // AudioSystem class
//
//class CommandSystem : public ex::System<CommandSystem>{
//public:
//	explicit CommandSystem(Input& input)
//	:input(input) {}
//	void update(entityx::EntityManager &es, entityx::EventManager &events, ex::TimeDelta dt) override {
//		for(const auto& command : input.getCommandBuffer()){// where to get sf::Event from?
//			events.emit<CommandEvent>(command);
//			std::cout << "emmited command: " << command << std::endl;
//		}
//		input.getCommandBuffer().clear();
//	}
//private:
//	Input& input;
//};
#endif /* SYSTEMS_HPP_ */
