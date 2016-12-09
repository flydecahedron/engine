/*
 * AudioPlayer_test.hpp
 *
 *  Created on: Dec 6, 2016
 *      Author: eroc
 */

#ifndef AUDIO_TEST_HPP_
#define AUDIO_TEST_HPP_

#include "Audio.hpp"

#include <SFML/System.hpp>

void test(){
	sf::Clock clock;
	sf::Time elapsed;
	elapsed = clock.restart();
	Audio audio;
	audio.addSound("punch", "assets/sounds/punch.wav");
	audio.addMusic("music", "assets/sounds/music.wav");
	audio.loadMusic("music");
	audio.playMusic("music");
	audio.playSound("punch");
	sf::Time time = sf::seconds(0.1);
	audio.update();
	sf::sleep(time);
	audio.update();
	audio.playSound("punch");
	sf::sleep(time);
	audio.playSound("punch");
	sf::sleep(time);
	audio.update();
	time = sf::seconds(15);
	audio.update();
	sf::sleep(time);
	audio.update();
}

void test2(){
	sf::Time time = sf::seconds(.5);

	// Declare a new sound buffer
	sf::SoundBuffer buffer;
	// Load it from a file
	if (!buffer.loadFromFile("assets/sounds/punch.wav"))
	{
	    // error...
	}
	// Create a sound source and bind it to the buffer
	sf::Sound sound1;
	sound1.setBuffer(buffer);
	// Play the sound
	sound1.play();
	// Create another sound source bound to the same buffer
	sf::sleep(time);
	sf::Sound sound2;
	sound2.setBuffer(buffer);
	// Play it with a higher pitch -- the first sound remains unchanged
	sound2.setPitch(2);
	sound2.play();
	sf::sleep(time);
	sf::Sound sound3;
	sound3.setBuffer(buffer);
	sf::Sound sound4;
	sound4.setBuffer(buffer);
	sf::Sound sound5;
	sound5.setBuffer(buffer);
	sf::Sound sound6;
	sound6.setBuffer(buffer);
	sf::Sound sound7;
	sound7.setBuffer(buffer);
	sound3.play();
	sound4.play();
	sound5.play();
	sound6.play();
	sound7.play();
	time = sf::seconds(10);
	sf::sleep(time);
	sf::sleep(time);

}


#endif /* AUDIO_TEST_HPP_ */
