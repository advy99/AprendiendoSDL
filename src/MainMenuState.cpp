#include "MainMenuState.h"
#include "InputHandler.h"
#include "Game.h"
#include "MenuButton.h"
#include <iostream>
#include "StateParser.h"

MainMenuState::~MainMenuState() {

	onExit();
}

void MainMenuState::update(){
	for ( unsigned i = 0; i < objects.size() &&
								!GameStateMachine::isChanging(); i++ ) {
		objects[i]->update();

	}
}

void MainMenuState::render() {
	for ( unsigned i = 0; i < objects.size() &&
								!GameStateMachine::isChanging(); i++ ) {
		objects[i]->draw();
	}

}


bool MainMenuState::onEnter() {
	bool success = true;

	StateParser parser;

	parser.parseState("assets/test.xml", menu_id, &objects, &texture_id_list);

	callbacks.push_back(menuToPlay);
	callbacks.push_back(exitFromMenu);

	setCallbacks(callbacks);

	return success;

}

bool MainMenuState::onExit() {
	std::cout << "Exiting menu" << std::endl;

	bool success = true;

	for ( unsigned i = 0; i < objects.size(); i++ ) {
		objects[i]->clean();
		delete objects[i];
	}

	objects.clear();
	callbacks.clear();

	for ( unsigned i = 0; i < texture_id_list.size(); i++ ) {
		TextureManager::getInstance()->clearFromTextureMap(texture_id_list[i]);
	}


	return success;

}


std::string MainMenuState::getStateID() const {
	return menu_id;
}


void MainMenuState::menuToPlay() {
	std::cout << "Clicked Play button" << std::endl;

	Game::getInstance()->getStateMachine()->changeState(new PlayState());
}


void MainMenuState::exitFromMenu() {
	std::cout << "Clicked Exit button" << std::endl;
	Game::getInstance()->quit();
}


void MainMenuState::setCallbacks(const std::vector<Callback> & callbacks) {
	for ( unsigned i = 0; i < objects.size(); i++ ) {
		MenuButton * button = dynamic_cast<MenuButton*> (objects[i]) ;
		if ( button != nullptr ) {
			button->setCallback(callbacks[button->getCallbackID() ]);
		}
	}
}



const std::string MainMenuState::menu_id = "MENU";
