#include "Player.h"

Player::Player(const LoaderParams * params):SDLGameObject(params){

}

void Player::draw(){
	SDLGameObject::draw();
}

void Player::update() {
	current_frame = int( (SDL_GetTicks() / 100) % 6  );

	velocity.setX(1);

	SDLGameObject::update();
}

void Player::clean(){

}
