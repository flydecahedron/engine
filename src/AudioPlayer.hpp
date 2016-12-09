
#ifndef AUDIOPLAYER_HPP_
#define AUDIOPLAYER_HPP_
#include <SFML/Audio.hpp>
#include "utils/Uncopyable.hpp"
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>
#include "AudioLoader.hpp"
#include <iostream>

/** Maximum amount of sounds at any given time. SFML docs state 256 is recommended max */
const int MaxSounds = 200;

/**
 * Adds and plays sounds to the game engine by name and filepath.
 * Implemented so that entityx events can be used to tell the AudioSystem to play sounds by
 * passing the name of the sound to the AudioPlayer. When sounds are added by calling addSound(),
 * the private AudioLoader handles loading the buffer from the given filepath so that the buffer
 * can be accessed by name.
 */
class AudioPlayer : private Uncopyable {
public:
	/**
	 * Ensures that only one instance exists and reserves the sounds vector according
	 * to MaxSounds.
	 */
	AudioPlayer()
	: loader(),
	  sounds(),
	  availableIndices(){
		assert(!instantiated);
		instantiated = true;
		sounds.reserve(MaxSounds); // should probs use an array but lazy. Assert is in play()
	}

	/** allows others instances to be created by setting instantiated to false */
	~AudioPlayer(){
		instantiated = false;
	}

	/** Checks if sounds are done playing and invalidates sounds if they are.
	 * Basically, the vector containing all the sounds is iterated through and if the sound status
	 * is equal to sf::Sound::Stopped (which comes from the status enum) then its index is pushed onto
	 * the queue of available indices. Only reads are done on the sounds vector during iteration
	 * which allows for the possibility of multithreading.
	 * Currently this is called every frame in the Level class.
	 * @see Level
	 */
	void update();

	/**
	 * Adds and loads the sound to the game.
	 * The appropriate sf::SoundBuffer is loaded in memory so that sounds can be played with
	 * little overhead. If the name already exists it, the filePath will be overriden by the new
	 * path passed in.
	 * @see AudioLoader
	 * @param name Used to play sounds and access their buffers by name
	 * @param filePath The actual file that the buffer will be loaded from
	 */
	void addSound(const std::string& name, const std::string& filePath);

	/**
	 * Frees the buffer from their associated containers.
	 * @see AudioLoader
	 * @param name The same name used when initially adding the sound
	 */
	void removeSound(const std::string& name);


	//void addMusic(const std::string& name, const std::string& filePath);
	//void removeMusic(const std::string& name);

	/**
	 * Plays the sound by the given name with default values such as volume, etc.
	 * A new sound instance is created per call and its buffer is set to its appropriate buffer
	 * in the buffers map contained by loader. Invalidated indices are used first before pushing
	 * the new sound onto the back of the sounds container.
	 *
	 * Possible Future Changes: A handle maybe returned to changed the specific sound being played.
	 * This could be an int according to its index (which would only be valid until the initial
	 * playthrough of the sound is finished). Since sounds are supposed to be relatively short,
	 * setting the initial parameters for the sound will probably be the easiest/safest way to
	 * handle sound effects and such. Maybe this could be handled in the update method through
	 * events emitted by the ecs.
	 * @param name
	 */
	void play(const std::string& name); // return a handle? to perform actions on sound(vol, etc)
	//void stop(const std::string& name);

private:
	/** Ensures only one AudioPlayer is instantiated */
	static bool instantiated;
	/** Contains sf::SoundBuffer and file paths by name of sounds */
	AudioLoader loader;
	/** Contains all sounds and is asserted to not grow (might be changed to array later). */
	std::vector<sf::Sound> sounds;
	/** Indices of sounds container that new sounds can be placed into */
	std::queue<unsigned short int> availableIndices;
};

#endif /* AUDIOPLAYER_HPP_ */
