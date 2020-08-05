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


		if ( input_handler->getButtonState(0,3) ) {
			velocity.setX(1);
		}

	}


	//if ( input_handler->getMouseButtonState(LEFT) ) {
	//	velocity.setX(1);
	//}

	//Vector2D * vec = InputHandler::getInstance()->getMousePosition();

	//velocity = ((*vec) - position) / 10;

	if ( InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_RIGHT) ) {
		velocity.setX(2);

	}

	if ( InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_LEFT) ) {
		velocity.setX(-2);

	}

	if ( InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_UP) ) {
		velocity.setY(-2);

	}

	if ( InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_DOWN) ) {
		velocity.setY(2);

	}
}
