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
		if(playingSounds[i].getStatus() == sf::Sound::Stopped){
			std::cout << "sound at" << i << "stopped playing, popping" << std::endl;
			std::swap(playingSounds[i], playingSounds.back());
			playingSounds.pop_back();

		}
	}
}

void AudioPlayer::addSound(std::string name, std::string filePath) {
	loader.addSound(name, filePath);
	loader.loadSound(name);
}

void AudioPlayer::removeSound(std::string name) {
	loader.freeSound(name);
}

void AudioPlayer::addMusic(std::string name, std::string filePath) {
	loader.addMusic(name, filePath);
	loader.loadMusic(name);
}

void AudioPlayer::removeMusic(std::string name) {
	loader.freeSound(name);
}

void AudioPlayer::play(std::string name) {
	sf::Sound sound;
	sound.setBuffer(loader.getBuffer(name));
	playingSounds.emplace_back(sound);
	playingSounds.back().play();
	std::cout << "playing: " << name << std::endl;
}

void AudioPlayer::stop(std::string name) {
	//TODO
}

void AudioPlayer::setVolume(std::string name) {
	//TODO
}

