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
#include "AudioLoader.hpp"

class AudioPlayer : private Uncopyable {
public:
	AudioPlayer(){
		assert(!instantiated);
		instantiated = true;
	}
	~AudioPlayer(){
		instantiated = false;
	}

	void addSound(std::string name, std::string filePath);
	void removeSound(std::string name);
	void addMusic(std::string name, std::string filePath);
	void removeMusic(std::string name, std::string filePath);

	void play(std::string name); // return a handle? to perform actions on sound(vol, etc)
	void stop(std::string name);
	void setVolume(std::string name);
private:
	static bool instantiated;
	AudioLoader loader;
	std::vector<sf::Sound> sounds;
};

#endif /* AUDIOPLAYER_HPP_ */
