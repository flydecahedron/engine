/*
 * AudioPlayer.h
 *
 *  Created on: Dec 3, 2016
 *      Author: eroc
 */

#ifndef AUDIOPLAYER_HPP_
#define AUDIOPLAYER_HPP_
#include <SFML/Audio.hpp>
#include "utils/Uncopyable.hpp"
#include <cassert>

class AudioPlayer : private Uncopyable {
public:
	AudioPlayer(){
		assert(!instantiated);
		instantiated = true;
	}
	virtual ~AudioPlayer(){
		instantiated = false;
	}

	void play(sf::Sound& sound);
	void play(sf::Music& music);
	void stop(sf::Sound& sound);
	void stop(sf::Music&music);

private:
	static bool instantiated;

};

#endif /* AUDIOPLAYER_HPP_ */
