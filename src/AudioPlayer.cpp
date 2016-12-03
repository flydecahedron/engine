/*
 * AudioPlayer.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: eroc
 */

#include "AudioPlayer.hpp"

AudioPlayer::AudioPlayer() {
	// TODO Auto-generated constructor stub

}

AudioPlayer::~AudioPlayer() {
	// TODO Auto-generated destructor stub
}

void AudioPlayer::play(sf::Sound& sound) {
	sound.play();
}

void AudioPlayer::play(sf::Music& music) {
	music.play();
}

void AudioPlayer::stop(sf::Sound& sound) {
	sound.stop();
}

void AudioPlayer::stop(sf::Music& music) {
	music.stop();
}
