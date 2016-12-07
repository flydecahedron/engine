/*
 * AudioLoader.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: eroc
 */

#include "AudioLoader.hpp"

void AudioLoader::addSound(const std::string& soundName, const std::string& path) {
	soundPaths.emplace(soundName, path);
	std::cout << "Added sound: " << soundName << " from path: " << soundPaths[soundName] << std::endl;
}

void AudioLoader::addMusic(const std::string& musicName, const std::string& path){
	musicPaths.emplace(musicName, path);
}

void AudioLoader::loadSound(const std::string& soundName) {
	sf::SoundBuffer buff;
	buff.loadFromFile(soundPaths[soundName]);
	buffers.emplace(soundName, buff);
}

void AudioLoader::loadMusic(const std::string& musicName){
	std::unique_ptr<sf::Music> musicPtr = std::make_unique<sf::Music>();
	musicPtr.get()->openFromFile(musicPaths[musicName]);
	musicPtrs.emplace(musicName, std::move(musicPtr));
}

void AudioLoader::loadAll() {
	for(const auto& iter : soundPaths){
		loadSound(iter.first);
	}
}

sf::SoundBuffer& AudioLoader::getBuffer(const std::string& soundName) {
	return buffers[soundName];
}

sf::SoundBuffer& AudioLoader::newBuffer(const std::string& soundName){
	sf::SoundBuffer buff;
	buff = buffers[soundName];
	tempBuffers.emplace(soundName, buff);
	return tempBuffers[soundName];
}

void AudioLoader::freeSound(const std::string& soundName) {
	buffers.erase(soundName);
}

void AudioLoader::freeMusic(const std::string& musicName){
	musicPtrs.erase(musicName);
}

void AudioLoader::freeAll() {
	for(const auto& iter : buffers){
		buffers.erase(iter.first);
	}
	for(const auto& iter : musicPtrs){
		musicPtrs.erase(iter.first);
	}
}
