/*
 * Level.hpp
 *
 *  Created on: Dec 2, 2016
 *      Author: eroc
 */

#ifndef LEVEL_HPP_
#define LEVEL_HPP_

#include <entityx/entityx.h>
#include "Components.hpp"
#include "Renderer.hpp"
#include "Systems.hpp"

namespace ex = entityx;

class Level : public ex::EntityX{
public :
	explicit Level(Renderer& renderer, AudioPlayer& audioPlayer){
		systems.add<RenderSystem>(renderer);
		systems.add<SpawnSystem>();
		systems.add<AudioSystem>(audioPlayer);
		systems.configure();
	}
	void update(ex::TimeDelta dt){
		systems.update<RenderSystem>(dt);
		systems.update<SpawnSystem>(dt);
		systems.update<AudioSystem>(dt);
	}

};




#endif /* LEVEL_HPP_ */
