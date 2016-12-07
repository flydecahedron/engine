/*
 * AudioPlayer_test.hpp
 *
 *  Created on: Dec 6, 2016
 *      Author: eroc
 */

#ifndef AUDIOPLAYER_TEST_HPP_
#define AUDIOPLAYER_TEST_HPP_

#include "AudioPlayer.hpp"
#include <SFML/System.hpp>

void test(){
	sf::Clock clock;
	sf::Time elapsed;
	elapsed = clock.restart();
	AudioPlayer audioPlayer;
	audioPlayer.addSound("punch", "assets/sounds/punch.wav");
	audioPlayer.play("punch");
	sf::Time time = sf::seconds(2);
	audioPlayer.update(elapsed.asSeconds());
	sf::sleep(time);
	audioPlayer.update(elapsed.asSeconds());
	audioPlayer.play("punch");
	sf::sleep(time);
	audioPlayer.play("punch");
	sf::sleep(time);
	audioPlayer.update(elapsed.asSeconds());
	time = sf::seconds(15);
	audioPlayer.update(elapsed.asSeconds());
	sf::sleep(time);
	audioPlayer.update(elapsed.asSeconds());
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


#endif /* AUDIOPLAYER_TEST_HPP_ */
