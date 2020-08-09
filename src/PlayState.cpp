#include "PlayState.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Game.h"
#include <iostream>

void PlayState::update() {

	if ( InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE) ){
		Game::getInstance()->getStateMachine()->pushState(new PauseState());
	}

	for ( unsigned i = 0; i < play_objects.size() && !exiting; i++ ) {
		play_objects[i]->update();
	}

}

void PlayState::render() {
	for ( unsigned i = 0; i < play_objects.size() && !exiting; i++ ) {
		play_objects[i]->draw();
	}

}

bool PlayState::onEnter() {
	std::cout << "Entering Play state" << std::endl;

	bool success;

	success = TextureManager::getInstance()->load("assets/helicopter0.png",
															"helicopter0", 5,
															Game::getInstance()->getRenderer());


	success = TextureManager::getInstance()->load("assets/helicopter1.png",
															"helicopter1", 5,
															Game::getInstance()->getRenderer());

	if ( success ) {
		play_objects.clear();
		LoaderParams * params_player = new LoaderParams(500, 100, 128, 55,
																		"helicopter0");

		LoaderParams * params_enemy = new LoaderParams(100, 100, 128, 55,
																		"helicopter1");

		GameObject * player = new Player(params_player);
		GameObject * enemy = new Enemy(params_enemy);

		play_objects.push_back(player);
		play_objects.push_back(enemy);

		delete params_player;
		delete params_enemy;

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
