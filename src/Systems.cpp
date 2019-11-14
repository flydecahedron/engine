#include "Systems.h"
#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <TGUI/TGUI.hpp>
#include "Components.hpp"
#include "Renderer.hpp"
#include "Events.hpp"
#include "Commands.hpp"
#include <iostream>

sf::Texture texture;
bool isLoaded = false;
void drawEntities(entt::registry& ecs, Renderer& renderer) {
	auto view = ecs.view<sf::Sprite>();

	renderer.drawBegin();
	for (auto& entity : view) {
		auto& sprite = ecs.get<sf::Sprite>(entity);
		renderer.draw(sprite);
	}
	renderer.drawEnd();
}


void randomSpawner(entt::registry& ecs) {
	if (!isLoaded) {
		texture.loadFromFile("kirby.png");
	}

	static int spawnCount = 50;
	if(spawnCount > 0){
		entt::entity entity = ecs.create();
		auto& sprite = ecs.assign<sf::Sprite>(entity);
		sprite.setTexture(texture);

		sf::Vector2f position;
		sf::Vector2f direction;
		position.x = rand() % 600 + 1; // 0 to 600
		position.y = rand() % 800 + 1; // 0 to 800
		direction.x = rand() % 600 + 1;
		direction.y = rand() % 800 + 1;
		float rotation = rand() % 360 + 1;
		
		sprite.setPosition(position);
		sprite.setRotation(rotation);

		sf::Color color;
		color.r = rand() % 255 + 1;
		color.g = rand() % 255 + 1;
		color.b = rand() % 255 + 1;

		//events.emit<PlaySound>("punch");
		--spawnCount;
	}
}