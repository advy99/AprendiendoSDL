#include "Enemy.h"



Enemy::Enemy(const LoaderParams * params):SDLGameObject(params){
	velocity.setY(2);

	// en el libro pone esto, pero no lo entiendo porque es un int, pero bueno
	velocity.setX(0.001);

}

void Enemy::draw(){
	SDLGameObject::draw();
}

void Enemy::update() {

	current_frame = int( (SDL_GetTicks() / 100) %
						TextureManager::getTextureNumFrames(texture_id)  );

	if ( position.getY() < 0 ) {
		velocity.setY(2);

	} else if ( position.getY() > 400 ) {
		velocity.setY(-2);
	}

	SDLGameObject::update();
}

void Enemy::clean(){

}
