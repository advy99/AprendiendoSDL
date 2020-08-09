#include "SDLGameObject.h"
#include "Game.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams * params)
									 :position(params->getX(), params->getY()),
									  velocity(0,0), acceleration(0,0){

	width = params->getWidth();
	height = params->getHeight();

	texture_id = params->getTextureId();

	current_frame = 1;
	current_row = 1;

	last_flip = SDL_FLIP_NONE;
}

void SDLGameObject::draw(){

	// if its zero, the last used
	if ( velocity.getX() > 0 ) {
		last_flip = SDL_FLIP_HORIZONTAL;

	} else if ( velocity.getX() < 0 ) {
		last_flip = SDL_FLIP_NONE;
	}

	TextureManager::getInstance()->drawFrame(texture_id, position.getX(),
														  position.getY(), width, height,
														  current_row, current_frame,
														  Game::getInstance()->getRenderer(),
														  last_flip);
}

void SDLGameObject::update() {
	velocity += acceleration;
	position += velocity;
}

void SDLGameObject::clean() {

}

Vector2D SDLGameObject::getPosition() const {
	return position;
}

int SDLGameObject::getWidth() const {
	return width;
}

int SDLGameObject::getHeight() const {
	return height;
}
