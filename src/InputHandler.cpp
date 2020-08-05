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
		} else if ( event.type == SDL_JOYAXISMOTION ) {
			int which_one = event.jaxis.which;

			if ( event.jaxis.axis == 0 ) {
				if ( event.jaxis.value > joystick_dead_zone ){
					joystick_values[which_one].first->setX(1);
				} else if ( event.jaxis.value < -joystick_dead_zone ){
					joystick_values[which_one].first->setX(-1);
				} else {
					joystick_values[which_one].first->setX(0);
				}
			}

			if ( event.jaxis.axis == 1 ) {
				if ( event.jaxis.value > joystick_dead_zone ){
					joystick_values[which_one].first->setY(1);
				} else if ( event.jaxis.value < -joystick_dead_zone ){
					joystick_values[which_one].first->setY(-1);
				} else {
					joystick_values[which_one].first->setY(0);
				}
			}


			if ( event.jaxis.axis == 3 ) {
				if ( event.jaxis.value > joystick_dead_zone ){
					joystick_values[which_one].second->setX(1);
				} else if ( event.jaxis.value < -joystick_dead_zone ){
					joystick_values[which_one].second->setX(-1);
				} else {
					joystick_values[which_one].second->setX(0);
				}
			}

			if ( event.jaxis.axis == 4 ) {
				if ( event.jaxis.value > joystick_dead_zone ){
					joystick_values[which_one].second->setY(1);
				} else if ( event.jaxis.value < -joystick_dead_zone ){
					joystick_values[which_one].second->setY(-1);
				} else {
					joystick_values[which_one].second->setY(0);
				}
			}


		}
	}
}

void InputHandler::clean(){

	while (!joysticks.empty()){
		SDL_JoystickClose(joysticks.back());
		joysticks.pop_back();
	}

	while (!joystick_values.empty()){
		auto sticks = joystick_values.back();
		delete sticks.first;
		delete sticks.second;
		joystick_values.pop_back();
	}

	joysticks_initialised = false;

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

			Vector2D * stick1 = new Vector2D(0,0);
			Vector2D * stick2 = new Vector2D(0,0);

			joystick_values.push_back(std::make_pair(stick1, stick2));
		} else {
			std::cerr << SDL_GetError() << std::endl;
		}

	}

	joysticks_initialised = !joysticks.empty();

	if (joysticks_initialised){
		SDL_JoystickEventState(SDL_ENABLE);
	}


}


int InputHandler::xValue(const int joy, const int stick) const{
	int valor = 0;

	if ( !joystick_values.empty() ){
		if ( stick == 1 ){
			valor = joystick_values[joy].first->getX();
		} else if ( stick == 2 ) {
			valor = joystick_values[joy].second->getX();
		}
	}


	return valor;
}

int InputHandler::yValue(const int joy, const int stick) const{
	int valor = 0;

	if ( !joystick_values.empty() ){
		if ( stick == 1 ){
			valor = joystick_values[joy].first->getY();
		} else if ( stick == 2 ) {
			valor = joystick_values[joy].second->getY();
		}
	}


	return valor;
}



InputHandler * InputHandler::instance = nullptr;
