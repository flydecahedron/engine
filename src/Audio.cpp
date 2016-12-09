/*
 * AudioPlayer.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: eroc
 */

#include "Audio.hpp"

bool Audio::instantiated;

Audio::Audio()
: sounds(),
  availableIndices(),
  soundPaths(),
  musicPaths(),
  buffers(),
  musicPtrs() {
		assert(!instantiated);
		instantiated = true;
		sounds.reserve(MaxSounds); // should probs use an array but lazy. Assert is in play()
}

Audio::~Audio(){
	instantiated = false;
}

void Audio::update(){
	for(std::vector<sf::Sound>::size_type i = 0; i != sounds.size(); i++){
		if(sounds.at(i).getStatus() == sf::Sound::Stopped){
			std::cout << "sound at" << i << "stopped playing" << std::endl;
			availableIndices.push(i);
		}
	}
}

void Audio::addSound(const std::string& name, const std::string& filePath) {
	soundPaths.emplace(name, filePath);
	sf::SoundBuffer buff;
	buff.loadFromFile(soundPaths[name]);
	buffers.emplace(name, buff);
}

void Audio::freeSound(const std::string& name) {
	buffers.erase(name);
}

void Audio::addMusic(const std::string& name, const std::string& filePath) {
	musicPaths.emplace(name, filePath);
}

void Audio::loadMusic(const std::string& name) {
	std::unique_ptr<sf::Music> musicPtr = std::make_unique<sf::Music>();
	musicPtr.get()->openFromFile(musicPaths[name]);
	musicPtrs.emplace(name, std::move(musicPtr));
}

void Audio::freeMusic(const std::string& name) {
	musicPtrs.erase(name);
}


void Audio::playSound(const std::string& name) {
	sf::Sound sound;
	sound.setBuffer(buffers[name]);
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
	musicPtrs[name].get()->play();
}

void Audio::pauseMusic(const std::string& name) {
	musicPtrs[name].get()->pause();
}

void Audio::stopMusic(const std::string& name) {
	musicPtrs[name].get()->stop();
}
