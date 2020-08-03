#include "Enemy.h"



Enemy::Enemy(const LoaderParams * params):SDLGameObject(params){

}

void Enemy::draw(){
	SDLGameObject::draw();
}

void Enemy::update() {
	x_pos -= 1;
	current_frame = int( (SDL_GetTicks() / 100) % 6  );
}

void Enemy::clean(){

}
