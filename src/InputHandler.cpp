#include "InputHandler.h"
#include <iostream>
#include "Game.h"

InputHandler::InputHandler() {
	joysticks_initialised = false;
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
	SDL_Event event;

	while ( SDL_PollEvent(&event) ){
		if (event.type == SDL_QUIT){
			Game::getInstance()->quit();
		}
	}
}

void InputHandler::clean(){

	while (!joysticks.empty()){
		SDL_JoystickClose(joysticks.back());
		joysticks.pop_back();
	}


	if (instance != nullptr){
		delete instance;
	}

	instance = nullptr;
}


void InputHandler::initialiseJoysticks(){
	Uint32 init_joysticks = SDL_INIT_JOYSTICK;

	if ( SDL_WasInit(init_joysticks) != init_joysticks ){
		SDL_InitSubSystem(init_joysticks);
	}

	for (int i = 0; i < SDL_NumJoysticks(); i++){
		SDL_Joystick * joy = SDL_JoystickOpen(i);

		if ( joy != nullptr ){
			joysticks.push_back(joy);
		} else {
			std::cerr << SDL_GetError() << std::endl;
		}

	}

	if (!joysticks.empty()){
		SDL_JoystickEventState(SDL_ENABLE);

		joysticks_initialised = true;
	}


}


InputHandler * InputHandler::instance = nullptr;
