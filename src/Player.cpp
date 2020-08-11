#include "Player.h"
#include "InputHandler.h"

Player::Player(  ):SDLGameObject(){

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

void Player::load(const LoaderParams * params) {
	SDLGameObject::load(params);
}


GameObject * PlayerCreator::createGameObject() const {
	return new Player();
}
