/*
 * AudioLoader.hpp
 *
 *  Created on: Dec 5, 2016
 *      Author: eroc
 */

#ifndef AUDIOLOADER_HPP_
#define AUDIOLOADER_HPP_
#include "utils/Uncopyable.hpp"
#include <unordered_map>
#include <iostream>
#include <SFML/Audio.hpp>

class AudioLoader : private Uncopyable {
public:
	AudioLoader()
	:soundPaths(),
	 musicPaths(),
	 buffers() {}
	~AudioLoader(){
		soundPaths.clear();
		buffers.clear();
	}


	void addSound(const std::string& soundName, const std::string& path);
	void addMusic(const std::string& musicName, const std::string& path);
	void loadSound(const std::string& soundName);
	void loadMusic(const std::string& musicName);
	void loadAll();
	sf::SoundBuffer& getBuffer(const std::string& soundName);
	void freeSound(const std::string& soundName);
	void freeMusic(const std::string& musicName);
	void freeAll();
private:
	std::unordered_map<std::string, std::string> soundPaths;
	std::unordered_map<std::string, std::string> musicPaths;
	std::unordered_map<std::string, sf::SoundBuffer> buffers;
	std::unordered_map<std::string, std::unique_ptr<sf::Music>> musicPtrs;

};

#endif /* AUDIOLOADER_HPP_ */
