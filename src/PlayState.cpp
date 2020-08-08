#include "PlayState.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Game.h"
#include <iostream>

void PlayState::update() {

	if ( InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE) ){
		Game::getInstance()->getStateMachine()->pushState(new PauseState());
	}

	for ( unsigned i = 0; i < play_objects.size(); i++ ) {
		play_objects[i]->update();
	}

}

void PlayState::render() {
	for ( unsigned i = 0; i < play_objects.size(); i++ ) {
		play_objects[i]->draw();
	}

}

bool PlayState::onEnter() {
	std::cout << "Entering Play state" << std::endl;

	bool success;

	success = TextureManager::getInstance()->load("assets/helicopter0.png",
															"helicopter0", 5,
															Game::getInstance()->getRenderer());

	if ( success ) {
		LoaderParams * params_player = new LoaderParams(100, 100, 128, 55,
																		"helicopter0");

		GameObject * player = new Player(params_player);

		play_objects.push_back(player);

		delete params_player;

	}

	exiting = !success;

	return success;
}

bool PlayState::onExit() {
	std::cout << "Exiting Play state" << std::endl;

	bool success = true;

	for ( unsigned i = 0; i < play_objects.size(); i++ ) {
		play_objects[i]->clean();
		delete play_objects[i];
	}

	play_objects.clear();
	TextureManager::getInstance()->clearFromTextureMap("helicopter0");

	exiting = success;

	return success;
}

std::string PlayState::getStateID() const {
	return play_id;
}




const std::string PlayState::play_id = "PLAY";
