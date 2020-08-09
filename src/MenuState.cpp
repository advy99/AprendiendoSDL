#include "MenuState.h"
#include "InputHandler.h"
#include "Game.h"
#include "MenuButton.h"
#include <iostream>

MenuState::~MenuState() {

}

void MenuState::update(){
	for ( unsigned i = 0; i < menu_objects.size() && !exiting; i++ ) {
		menu_objects[i]->update();
	}
}

void MenuState::render() {
	for ( unsigned i = 0; i < menu_objects.size() && !exiting; i++ ) {
		menu_objects[i]->draw();
	}

}


bool MenuState::onEnter() {
	std::cout << "Entering menu" << std::endl;

	bool success = TextureManager::getInstance()->load("assets/play_button.png",
															"playbutton", 3,
															Game::getInstance()->getRenderer());


	if ( success ) {
		success = TextureManager::getInstance()->load("assets/exit_button.png",
															"exitbutton", 3,
															Game::getInstance()->getRenderer());
	}

	if ( success ) {
		menu_objects.clear();
		LoaderParams * params_b1 = new LoaderParams(100, 100, 400, 100, "playbutton");
		LoaderParams * params_b2 = new LoaderParams(100, 300, 400, 100, "exitbutton");

		GameObject * button1 = new MenuButton(params_b1, menuToPlay);
		GameObject * button2 = new MenuButton(params_b2, exitFromMenu);

		menu_objects.push_back(button1);
		menu_objects.push_back(button2);

		delete params_b1;
		delete params_b2;

	}

	exiting = !success;

	return success;

}

bool MenuState::onExit() {
	std::cout << "Exiting menu" << std::endl;

	bool success = true;

	for ( unsigned i = 0; i < menu_objects.size(); i++ ) {
		menu_objects[i]->clean();
		delete menu_objects[i];
	}

	menu_objects.clear();

	TextureManager::getInstance()->clearFromTextureMap("playbutton");
	TextureManager::getInstance()->clearFromTextureMap("exitbutton");


	exiting = success;
	return success;

}


std::string MenuState::getStateID() const {
	return menu_id;
}


void MenuState::menuToPlay() {
	std::cout << "Clicked Play button" << std::endl;

	Game::getInstance()->getStateMachine()->changeState(new PlayState());
}


void MenuState::exitFromMenu() {
	std::cout << "Clicked Exit button" << std::endl;
	Game::getInstance()->quit();
}


const std::string MenuState::menu_id = "MENU";
