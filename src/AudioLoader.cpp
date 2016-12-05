/*
 * AudioLoader.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: eroc
 */

#include "AudioLoader.hpp"

void AudioLoader::addPath(std::string soundName, std::string path) {
	paths[soundName] = path;
}

void AudioLoader::load(std::string soundName) {
	sf::SoundBuffer buff;
	buff.loadFromFile(paths[soundName]);
	buffers[soundName] = buff;
}

void AudioLoader::loadAll() {
	for(const auto& iter : paths){
		load(iter.first);
	}
}

sf::SoundBuffer AudioLoader::getBuffer(std::string soundName) {
	return buffers[soundName];
}

void AudioLoader::free(std::string soundName) {
	buffers.erase(soundName);
}

void AudioLoader::freeAll() {
	for(const auto& iter : buffers){
		buffers.erase(iter.first);
	}
}
