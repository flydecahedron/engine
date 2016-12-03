/*
 * AudioPlayer.h
 *
 *  Created on: Dec 3, 2016
 *      Author: eroc
 */

#ifndef AUDIOPLAYER_HPP_
#define AUDIOPLAYER_HPP_
#include <SFML/Audio.hpp>
class AudioPlayer {
public:
	AudioPlayer();
	virtual ~AudioPlayer();

	void play(sf::Sound& sound);
	void play(sf::Music& music);
	void stop(sf::Sound& sound);
	void stop(sf::Music&music);


};

#endif /* AUDIOPLAYER_HPP_ */
