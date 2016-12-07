/*
 * AudioPlayer.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: eroc
 */

#include "AudioPlayer.hpp"

bool AudioPlayer::instantiated;

void AudioPlayer::update(double dt){
	for(std::vector<sf::Sound>::size_type i = 0; i != playingSounds.size(); i++){
		if(playingSounds.at(i).getStatus() == sf::Sound::Stopped){
			std::cout << "sound at" << i << "stopped playing" << std::endl;
			availableIndices.push(i);
		}
}
}

void AudioPlayer::addSound(const std::string& name, const std::string& filePath) {
	loader.addSound(name, filePath);
	loader.loadSound(name);
}

void AudioPlayer::removeSound(const std::string& name) {
	loader.freeSound(name);
}

void AudioPlayer::addMusic(const std::string& name, const std::string& filePath) {
	loader.addMusic(name, filePath);
	loader.loadMusic(name);
}

void AudioPlayer::removeMusic(const std::string& name) {
	loader.freeSound(name);
}


void AudioPlayer::play(const std::string& name) {
	sf::Sound sound;
	sound.setBuffer(loader.getBuffer(name));
	assert(playingSounds.size() < MaxSounds);
	if(availableIndices.empty()){
		playingSounds.emplace_back(sound);
		playingSounds.back().play(); //problem child
		std::cout << "playing: " << playingSounds.back().getStatus() << std::endl;
	}
	else {
		unsigned int index = availableIndices.front();
		availableIndices.pop();
		playingSounds.at(index) = sound;
		playingSounds.at(index).play();
		std::cout << "playing: " << playingSounds.at(index).getStatus() << std::endl;
	}
}
