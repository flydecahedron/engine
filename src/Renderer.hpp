
#ifndef RENDERER_HPP_
#define RENDERER_HPP_
#include "utils/Uncopyable.hpp"
#include <cassert>
#include <SFML/Graphics.hpp>

/**
 * Provides drawing functions and handles the window.
 * Responsible for drawing sf::Drawable and handle the sf::RenderWindow.
 * Owned by Game and is meant to be passed into objects by reference.
 * @see Uncopyable
 */
class Renderer : private Uncopyable{
public:
	/** Setups the window and asserts only one instance exists */
	Renderer()
	:window(sf::VideoMode(800,600), "fucking work"){
		assert(!instantiated);
		instantiated = true;
	}
	/** Closes window and allows for another instance */
	~Renderer(){
		window.close();
		instantiated = false;
	}

	/**
	 * Calls draw on the window relative to screen space
	 * @param drawable any sf::Drawable
	 */
	void draw(const sf::Drawable& drawable);
	/** Clears the window. Needs to be called before drawing each frame */
	void drawBegin();
	/** Calls display on the window. Needs to be called after drawing each frame */
	void drawEnd();
	void setupWindow();
	/** Calls close on the window which is mainly just used in the dtor */
	void closeWindow();
	/** Returns whether the window is open. */
	bool isOpen();
	/** Passes events to the window each frame */
	bool pollEvent(sf::Event& event);
	/** Returns reference to the private sf::RenderWindow */
	sf::RenderWindow& getWindow(){
		return window;
	}

private:
	/** Ensures only one Renderer is instantiated */
	static bool instantiated;
	/** the main window, may extend to allow a stack of screens */
	sf::RenderWindow window;
};



#endif /* RENDERER_HPP_ */
