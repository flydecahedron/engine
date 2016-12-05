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
#include <SFML/Audio.hpp>

class AudioLoader : private Uncopyable {
public:
	AudioLoader()
	:paths(),
	 buffers() {}
	~AudioLoader(){
		paths.clear();
		buffers.clear();
	}


	void addPath(std::string soundName, std::string path);
	void load(std::string soundName);
	void loadAll();
	sf::SoundBuffer getBuffer(std::string soundName);
	void free(std::string soundName);
	void freeAll();
private:
	std::unordered_map<std::string, std::string> paths;
	std::unordered_map<std::string, sf::SoundBuffer> buffers;

};

#endif /* AUDIOLOADER_HPP_ */
