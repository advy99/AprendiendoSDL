#include "Enemy.h"



Enemy::Enemy():SDLGameObject(){
}

void Enemy::draw(){
	SDLGameObject::draw();
}

void Enemy::update() {

	current_frame = int( (SDL_GetTicks() / 100) % num_frames );

	if ( position.getY() < 0 ) {
		velocity.setY(2);

	} else if ( position.getY() > 400 ) {
		velocity.setY(-2);
	}

	SDLGameObject::update();
}

void Enemy::clean(){

}

void Enemy::load(const LoaderParams * params) {
	SDLGameObject::load(params);
	velocity.setY(2);

}


GameObject * EnemyCreator::createGameObject() const {
	return new Enemy();
}
