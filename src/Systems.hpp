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
#include "Renderer.hpp"
namespace ex = entityx;

class RenderSystem : public ex::System<RenderSystem> {
public:
	explicit RenderSystem(Renderer& renderer) : renderer(renderer) {}

	void update(ex::EntityManager entities, ex::EventManager& events, ex::TimeDelta dt) override {
		renderer.drawBegin();
		entities.each<BasePhysics, Primitive>([this](ex::Entity entity, BasePhysics& basePhysics, Primitive& primitive){
			primitive.shape->setPosition(basePhysics.position);
			primitive.shape->setRotation(basePhysics.rotation);
			renderer.draw(*primitive.shape);
		});
		renderer.drawEnd();
	}

private:
	Renderer& renderer;
};



#endif /* SYSTEMS_HPP_ */
