/*
 * Renderer.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: eroc
 */

#include "Renderer.hpp"

bool Renderer::instantiated;

void Renderer::draw(const sf::Drawable& drawable) {
	window.draw(drawable);
}

void Renderer::drawBegin() {
	window.clear(sf::Color::Black);
}

void Renderer::drawEnd() {
	window.display();
}


void Renderer::closeWindow() {
	window.close();
}

void Renderer::setupWindow(){
	//window();
}

bool Renderer::isOpen(){
	return window.isOpen();
}

bool Renderer::pollEvent(sf::Event& event){
	return window.pollEvent(event);
}
