#include "Enemy.h"



Enemy::Enemy(const LoaderParams * params):SDLGameObject(params){

}

void Enemy::draw(){
	SDLGameObject::draw();
}

void Enemy::update() {
	current_frame = int( (SDL_GetTicks() / 100) % 6  );


	SDLGameObject::update();
}

void Enemy::clean(){

}
