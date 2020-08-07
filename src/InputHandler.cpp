#include "InputHandler.h"
#include <iostream>
#include "Game.h"

InputHandler::InputHandler() {
	joysticks_initialised = false;

	mouse_button_states = std::vector<bool>(3, false);

	mouse_position = new Vector2D(0, 0);
	key_state = nullptr;
}

InputHandler::~InputHandler(){

}

InputHandler * InputHandler::getInstance() {
	if (instance == nullptr){
		instance = new InputHandler();
	}

	return instance;
}

bool InputHandler::joysticksInitialised() const {
	return joysticks_initialised;
}


void InputHandler::update(){
	SDL_Event event;

	while ( SDL_PollEvent(&event) ){

		key_state = const_cast <Uint8*> ( SDL_GetKeyboardState( nullptr ) );

		if (event.type == SDL_QUIT){
			Game::getInstance()->quit();
		} else if ( event.type == SDL_JOYAXISMOTION ) {
			onJoystickAxisMove(event);

		} else if ( event.type == SDL_JOYBUTTONDOWN ) {
			onJoystickButtonDown(event);

		} else if ( event.type == SDL_JOYBUTTONUP ) {
			onJoystickButtonUp(event);

		} else if ( event.type == SDL_MOUSEBUTTONDOWN ) {
			onMouseButtonDown(event);

		} else if ( event.type == SDL_MOUSEBUTTONUP ) {
			onMouseButtonUp(event);

		} else if ( event.type == SDL_MOUSEMOTION ) {
			onMouseMotion(event);

		}




	}
}

void InputHandler::onJoystickButtonDown(const SDL_Event event){
	button_states[event.jaxis.which][event.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(const SDL_Event event) {
	button_states[event.jaxis.which][event.jbutton.button] = false;
}

void InputHandler::onMouseButtonDown(const SDL_Event event) {

	// El izquierdo es 1, central 2 y derecha 3
	// por lo que le restamos 1 para tener 0, 1 y 2
	mouse_button_states[event.button.button - 1] = true;

}


void InputHandler::onMouseButtonUp(const SDL_Event event) {

	// El izquierdo es 1, central 2 y derecha 3
	// por lo que le restamos 1 para tener 0, 1 y 2
	mouse_button_states[event.button.button - 1] = false;

}

void InputHandler::onMouseMotion( const SDL_Event event ) {

	mouse_position->setX(event.motion.x);
	mouse_position->setY(event.motion.y);
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

	if (mouse_position != nullptr){
		delete mouse_position;
	}
	mouse_position = nullptr;



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

			std::vector<bool> tmp_buttons =
									std::vector<bool>(SDL_JoystickNumButtons(joy), false);

			button_states.push_back(tmp_buttons);


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


bool InputHandler::getButtonState(const int joy, const int button_number)const{
	return button_states[joy][button_number];
}

bool InputHandler::getMouseButtonState(const int button) const {
	return mouse_button_states[button];
}

Vector2D * InputHandler::getMousePosition() const {
	return mouse_position;
}

bool InputHandler::isKeyDown(const SDL_Scancode key) const {
	bool is_down = false;

	if (key_state != nullptr){
		is_down = key_state[key] == 1;
	}

	return is_down;


}

void InputHandler::onJoystickAxisMove(const SDL_Event event){

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

InputHandler * InputHandler::instance = nullptr;
