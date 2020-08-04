#include "Player.h"

Player::Player(const LoaderParams * params):SDLGameObject(params){

}

void Player::draw(){
	SDLGameObject::draw();
}

void Player::update() {
	position.setX(position.getX() + 1);
	current_frame = int( (SDL_GetTicks() / 100) % 6  );
}

void Player::clean(){

}
