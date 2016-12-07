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
#include <vector>
#include <queue>
#include <algorithm>
#include "AudioLoader.hpp"
#include <iostream>

const int MaxSounds = 200;

class AudioPlayer : private Uncopyable {
public:
	AudioPlayer()
	: loader(),
	  playingSounds(),
	  availableIndices(){
		assert(!instantiated);
		instantiated = true;
		playingSounds.reserve(MaxSounds); // should probs use an array but lazy. Assert is in play()
	}
	~AudioPlayer(){
		instantiated = false;
	}
	void update(double dt);
	void addSound(const std::string& name, const std::string& filePath);
	void removeSound(const std::string& name);
	void addMusic(const std::string& name, const std::string& filePath);
	void removeMusic(const std::string& name);

	void play(const std::string& name); // return a handle? to perform actions on sound(vol, etc)
	void stop(const std::string& name);


private:
	static bool instantiated;
	AudioLoader loader;
	std::vector<sf::Sound> playingSounds;
	std::queue<unsigned short int> availableIndices;
};

#endif /* AUDIOPLAYER_HPP_ */
