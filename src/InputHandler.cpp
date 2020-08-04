#include "InputHandler.h"

InputHandler::InputHandler() {

}

InputHandler::~InputHandler(){

}

InputHandler * InputHandler::getInstance() {
	if (instance == nullptr){
		instance = new InputHandler();
	}

	return instance;
}

void InputHandler::update(){

}

void InputHandler::clean(){
	if (instance != nullptr){
		delete instance;
	}

	instance = nullptr;
}


InputHandler * InputHandler::instance = nullptr;
