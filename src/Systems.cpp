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

class SpawnSystem {
public:
	void update(entt::registry& ecs) {
		if (!isLoaded) {
			texture.loadFromFile("kirby.png");
		}

		//static int spawnCount = 50;
		if (spawnCount > 0) {
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

	void receive(const CommandEvent& command) {
		if (command.command == "SpawnCircle") {
			++spawnCount;
		}
	}

private:

	int spawnCount;
};


struct an_event { int value; };
struct another_event {};

struct listener {
	void receive(const an_event&) { /* ... */ }
	void method(const another_event&) { /* ... */ }
};

// ...
/*
listener listener;
dispatcher.sink<an_event>().connect<&listener::receive>(listener);
dispatcher.sink<another_event>().connect<&listener::method>(listener);

dispatcher.enqueue<an_event>(42);
dispatcher.enqueue<another_event>();

// emits all the events of the given type at once
dispatcher.update<my_event>();

// emits all the events queued so far at once
dispatcher.update();
*/

//void receiveSpawnEvent()
void handleInput(entt::dispatcher& inputDispatcher, Input& input) {
	for (const auto& command : input.getCommandBuffer()) {// where to get sf::Event from?
		inputDispatcher.update();
		std::cout << "emmited command: " << command << std::endl;
	}
	input.getCommandBuffer().clear();
}