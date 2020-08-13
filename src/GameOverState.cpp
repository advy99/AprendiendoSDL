#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "InputHandler.h"
#include "StateParser.h"

GameOverState::~GameOverState() {
	onExit();
}

std::string GameOverState::getStateID() const {
	return game_over_id;
}

void GameOverState::gameOverToMain() {
	Game::getInstance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::restartPlay() {
	Game::getInstance()->getStateMachine()->changeState(new PlayState());

}

bool GameOverState::onEnter() {
	bool success = true;

	StateParser parser;

	parser.parseState("assets/test.xml", game_over_id, &objects,
							&texture_id_list);

	callbacks.push_back(gameOverToMain);
	callbacks.push_back(restartPlay);

	setCallbacks(callbacks);

	return success;


}

bool GameOverState::onExit(){

	bool success = true;


	for ( unsigned i = 0; i < objects.size(); i++ ){
		objects[i]->clean();
		delete objects[i];
		objects[i] = nullptr;
	}

	objects.clear();

	callbacks.clear();

	for ( unsigned i = 0; i < texture_id_list.size(); i++ ) {
		TextureManager::getInstance()->clearFromTextureMap(texture_id_list[i]);
	}


	InputHandler::getInstance()->reset();


	return success;


}


void GameOverState::update() {
	for ( unsigned i = 0; i < objects.size() && !GameStateMachine::isChanging(); i++ ) {
		objects[i]->update();
	}
}


void GameOverState::render() {
	for ( unsigned i = 0; i < objects.size() && !GameStateMachine::isChanging(); i++ ) {
		objects[i]->draw();
	}
}



void GameOverState::setCallbacks(const std::vector<Callback> & callbacks) {
	for ( unsigned i = 0; i < objects.size(); i++ ) {
		MenuButton * button = dynamic_cast<MenuButton*> (objects[i]) ;
		if ( button != nullptr ) {
			button->setCallback(callbacks[button->getCallbackID() ]);
		}
	}
}




const std::string GameOverState::game_over_id = "GAMEOVER";
