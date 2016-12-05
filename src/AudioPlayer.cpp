/*
 * AudioPlayer.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: eroc
 */

#include "AudioPlayer.hpp"

bool AudioPlayer::instantiated;


void AudioPlayer::addSound(std::string name, std::string filePath) {
	loader.addSound(name, filePath);
	loader.loadSound(name);
}

void AudioPlayer::removeSound(std::string name) {
	loader.freeSound(name);
}

void AudioPlayer::addMusic(std::string name, std::string filePath) {
}

void AudioPlayer::removeMusic(std::string name, std::string filePath) {
}

void AudioPlayer::play(std::string name) {
}

void AudioPlayer::stop(std::string name) {
}

void AudioPlayer::setVolume(std::string name) {
}

