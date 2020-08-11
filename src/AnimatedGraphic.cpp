#include "AnimatedGraphic.h"
#include "TextureManager.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams * params, const int speed)
											:SDLGameObject(), animation_speed(speed){
	SDLGameObject::load(params);
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
