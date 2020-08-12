#include "MainMenuState.h"
#include "InputHandler.h"
#include "Game.h"
#include "MenuButton.h"
#include <iostream>

MainMenuState::~MainMenuState() {

	onExit();
}

void MainMenuState::update(){
	for ( unsigned i = 0; i < menu_objects.size() &&
								!GameStateMachine::isChanging(); i++ ) {
		menu_objects[i]->update();

	}
}

void MainMenuState::render() {
	for ( unsigned i = 0; i < menu_objects.size() &&
								!GameStateMachine::isChanging(); i++ ) {
		menu_objects[i]->draw();
	}

}


bool MainMenuState::onEnter() {
	std::cout << "Entering menu" << std::endl;

	bool success = TextureManager::getInstance()->load("assets/play_button.png",
															"playbutton",
															Game::getInstance()->getRenderer());


	if ( success ) {
		success = TextureManager::getInstance()->load("assets/exit_button.png",
															"exitbutton",
															Game::getInstance()->getRenderer());
	}

	if ( success ) {
		menu_objects.clear();
		LoaderParams * params_b1 = new LoaderParams(100, 100, 400, 100, "playbutton", 3);
		LoaderParams * params_b2 = new LoaderParams(100, 300, 400, 100, "exitbutton", 3);

		GameObject * button1 = new MenuButton(params_b1, menuToPlay);
		GameObject * button2 = new MenuButton(params_b2, exitFromMenu);

		menu_objects.push_back(button1);
		menu_objects.push_back(button2);

		delete params_b1;
		delete params_b2;

	}


	return success;

}

bool MainMenuState::onExit() {
	std::cout << "Exiting menu" << std::endl;

	bool success = true;

	for ( unsigned i = 0; i < menu_objects.size(); i++ ) {
		menu_objects[i]->clean();
		delete menu_objects[i];
	}

	menu_objects.clear();

	TextureManager::getInstance()->clearFromTextureMap("playbutton");
	TextureManager::getInstance()->clearFromTextureMap("exitbutton");


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


const std::string MainMenuState::menu_id = "MENU";
