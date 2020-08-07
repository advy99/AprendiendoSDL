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

	current_frame = int( (SDL_GetTicks() / 100) %
						TextureManager::getTextureNumFrames(texture_id)  );


	SDLGameObject::update();
}

void Player::clean(){

}

void Player::handleInput() {

	Vector2D * target = InputHandler::getInstance()->getMousePosition();

	velocity = (*target) - position;

	velocity /= 10;

}
