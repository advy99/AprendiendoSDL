#include "PlayState.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Game.h"
#include <iostream>

PlayState::~PlayState() {
	onExit();
}

void PlayState::update() {

	if ( InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE) ){
		Game::getInstance()->getStateMachine()->pushState(new PauseState());
	}

	for ( unsigned i = 0; i < play_objects.size() && !GameStateMachine::isChanging(); i++ ) {
		play_objects[i]->update();
	}

	if ( checkCollision(dynamic_cast<SDLGameObject *> (play_objects[0]),
							  dynamic_cast<SDLGameObject *> (play_objects[1]) ) ){
		Game::getInstance()->getStateMachine()->pushState(new GameOverState());
	}

}

void PlayState::render() {
	for ( unsigned i = 0; i < play_objects.size() && !GameStateMachine::isChanging(); i++ ) {
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


	return success;
}

std::string PlayState::getStateID() const {
	return play_id;
}

bool PlayState::checkCollision(const SDLGameObject * p1,
										 const SDLGameObject * p2){
	bool collision = false;


	int leftA = p1->getPosition().getX();
	int rightA = leftA + p1->getWidth();
	int topA = p1->getPosition().getY();
	int bottomA = topA + p1->getHeight();


	int leftB = p2->getPosition().getX();
	int rightB = leftB + p2->getWidth();
	int topB = p2->getPosition().getY();
	int bottomB = topB + p2->getHeight();


	collision = ( bottomA >= topB && topA <= bottomB ) &&
					( rightA >= leftB && leftA <= rightB );


	return collision;
}



const std::string PlayState::play_id = "PLAY";
