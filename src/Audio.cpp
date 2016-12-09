/*
 * AudioPlayer.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: eroc
 */

#include "Audio.hpp"

bool Audio::instantiated;

void Audio::update(){
	for(std::vector<sf::Sound>::size_type i = 0; i != sounds.size(); i++){
		if(sounds.at(i).getStatus() == sf::Sound::Stopped){
			std::cout << "sound at" << i << "stopped playing" << std::endl;
			availableIndices.push(i);
		}
	}
}

void Audio::addSound(const std::string& name, const std::string& filePath) {
	loader.addSound(name, filePath);
	loader.loadSound(name);
}

void Audio::freeSound(const std::string& name) {
	loader.freeSound(name);
}

void Audio::addMusic(const std::string& name, const std::string& filePath) {
	loader.addMusic(name, filePath);
}

void Audio::loadMusic(const std::string& name) {
	 loader.loadMusic(name);
}

void Audio::freeMusic(const std::string& name) {
	loader.freeSound(name);
}


void Audio::playSound(const std::string& name) {
	sf::Sound sound;
	sound.setBuffer(loader.getBuffer(name));
	assert(sounds.size() < MaxSounds);
	if(availableIndices.empty()){
		sounds.emplace_back(sound);
		sounds.back().play(); //problem child
		std::cout << "playing: " << sounds.back().getStatus() << std::endl;
	}
	else {
		unsigned int index = availableIndices.front();
		availableIndices.pop();
		sounds.at(index) = sound;
		sounds.at(index).play();
		std::cout << "playing: " << sounds.at(index).getStatus() << std::endl;
	}
}

void Audio::playMusic(const std::string& name) {
	loader.getMusic(name).play();
}

void Audio::pauseMusic(const std::string& name) {
	loader.getMusic(name).pause();
}

void Audio::stopMusic(const std::string& name) {
	loader.getMusic(name).stop();
}
