#include "SDLGameObject.h"
#include "Game.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject() :GameObject(){

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

void SDLGameObject::load(const LoaderParams * params) {
	position = Vector2D(params->getX(), params->getY());
	velocity = Vector2D(0, 0);
	acceleration = Vector2D(0, 0);
	width = params->getWidth();
	height = params->getHeight();
	texture_id = params->getTextureId();
	current_frame = 1;
	current_row = 1;
	num_frames = params->getNumFrames();
	last_flip = params->getFlip();

}
