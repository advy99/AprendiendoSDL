#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams * params):SDLGameObject(params){

}

void Player::draw(){
	SDLGameObject::draw();
}

void Player::update() {
	velocity.setX(0);
	velocity.setY(0);

	handleInput();

	current_frame = int( (SDL_GetTicks() / 100) % 6  );


	SDLGameObject::update();
}

void Player::clean(){

}

void Player::handleInput() {
	InputHandler * input_handler = InputHandler::getInstance();

	if ( input_handler->joysticksInitialised() ) {

		if ( input_handler->xValue(0, 1) != 0 ) {
			velocity.setX( input_handler->xValue(0, 1) );
		}

		if ( input_handler->yValue(0, 1) != 0 ) {
			velocity.setY( input_handler->yValue(0, 1) );
		}

		if ( input_handler->xValue(0, 2) != 0 ) {
			velocity.setX( input_handler->xValue(0, 2) );
		}

		if ( input_handler->yValue(0, 2) != 0 ) {
			velocity.setY( input_handler->yValue(0, 2) );
		}

	}
}
