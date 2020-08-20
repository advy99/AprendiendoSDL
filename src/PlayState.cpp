#include "PlayState.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Game.h"
#include <iostream>
#include "StateParser.h"
#include "LevelParser.h"

PlayState::~PlayState() {
	onExit();
}

void PlayState::update() {
	level->update();

}

void PlayState::render() {
	level->render();
}

bool PlayState::onEnter() {
	std::cout << "Entering Play state" << std::endl;

	bool success = true;

	LevelParser parser;

	level = parser.parseLevel("assets/first_csv.tmx");


	return success;
}

bool PlayState::onExit() {
	delete level;
	return GameState::onExit();
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
