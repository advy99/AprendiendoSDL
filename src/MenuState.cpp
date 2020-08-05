#include "MenuState.h"
#include <iostream>

MenuState::~MenuState() {

}

void MenuState::update(){

}

void MenuState::render() {

}


bool MenuState::onEnter() {
	std::cout << "Entering menu" << std::endl;

	bool success = true;



	return success;

}

bool MenuState::onExit() {
	std::cout << "Exiting menu" << std::endl;

	bool success = true;


	return success;

}


std::string MenuState::getStateID() const {
	return menu_id;
}





const std::string MenuState::menu_id = "MENU";
