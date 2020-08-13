#include "AnimatedGraphic.h"
#include "TextureManager.h"

AnimatedGraphic::AnimatedGraphic():SDLGameObject(){
}

void AnimatedGraphic::update() {
	current_frame = int( (SDL_GetTicks() / ( 1000 / animation_speed ))
								% num_frames ) ;
}

void AnimatedGraphic::draw() {
	SDLGameObject::draw();
}

void AnimatedGraphic::clean() {
	SDLGameObject::clean();
}

void AnimatedGraphic::load(const LoaderParams * params) {
	SDLGameObject::load(params);
	animation_speed = params->getAnimSpeed();
}

GameObject * AnimatedGraphicCreator::createGameObject() const {
	return new AnimatedGraphic();
}
