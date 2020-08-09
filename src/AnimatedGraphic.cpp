#include "AnimatedGraphic.h"
#include "TextureManager.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams * params, const int speed)
											:SDLGameObject(params), animation_speed(speed){

}

void AnimatedGraphic::update() {
	current_frame = int( (SDL_GetTicks() / ( 1000 / animation_speed ))
								% TextureManager::getTextureNumFrames(texture_id) ) ;
}

void AnimatedGraphic::draw() {
	SDLGameObject::draw();
}

void AnimatedGraphic::clean() {
	SDLGameObject::clean();
}
