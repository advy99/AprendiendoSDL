#include "PlayState.h"
#include <iostream>

void PlayState::update() {

}

void PlayState::render() {

}

bool PlayState::onEnter() {
	std::cout << "Entering Play state" << std::endl;

	bool success = true;


	return success;
}

bool PlayState::onExit() {
	std::cout << "Exiting Play state" << std::endl;

	bool success = true;


	return success;
}

std::string PlayState::getStateID() const {
	return play_id;
}




const std::string PlayState::play_id = "PLAY";
