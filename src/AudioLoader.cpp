/*
 * AudioLoader.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: eroc
 */

#include "AudioLoader.hpp"

void AudioLoader::addSound(const std::string& soundName, const std::string& path) {
	soundPaths[soundName] = path;
}

void AudioLoader::addMusic(const std::string& musicName, const std::string& path){
	musicPaths[musicName] = path;
}

void AudioLoader::loadSound(const std::string& soundName) {
	sf::SoundBuffer buff;
	buff.loadFromFile(soundPaths[soundName]);
	buffers[soundName] = buff;
}

void AudioLoader::loadMusic(const std::string& musicName){

}

void AudioLoader::loadAll() {
	for(const auto& iter : soundPaths){
		loadSound(iter.first);
	}
}

sf::SoundBuffer AudioLoader::getBuffer(const std::string& soundName) {
	return buffers[soundName];
}

void AudioLoader::freeSound(const std::string& soundName) {
	buffers.erase(soundName);
}

void AudioLoader::freeMusic(const std::string& musicName){
	music.erase(musicName);
}

void AudioLoader::freeAll() {
	for(const auto& iter : buffers){
		buffers.erase(iter.first);
	}
}
