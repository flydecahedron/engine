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
		for(const auto& sound : playingSounds){
			std::cout << sound.getStatus() << std::endl;
		}
		if(playingSounds[i].getStatus() == sf::Sound::Stopped){
			std::cout << "sound at" << i << "stopped playing, popping" << std::endl;
			std::swap(playingSounds[i], playingSounds.back());
			playingSounds.pop_back();

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
	playingSounds.emplace_back(sound);
	playingSounds.back().play();
	std::cout << "playing: " << name << std::endl;
}

void AudioPlayer::play(const std::string& name, const bool& isSimultaneous) {
	sf::Sound sound;
}

void AudioPlayer::play(const std::string& name, const bool& isSimultaneous,
		const float& volume) {
}

