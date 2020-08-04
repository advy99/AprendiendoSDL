#include "SDLGameObject.h"
#include "Game.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams * params)
									 :position(params->getX(), params->getY()){

	width = params->getWidth();
	height = params->getHeight();

	texture_id = params->getTextureId();

	current_frame = 1;
	current_row = 1;
}

void SDLGameObject::draw(){
	TextureManager::getInstance()->drawFrame(texture_id, position.getX(),
														  position.getY(), width, height,
														  current_row, current_frame,
														  Game::getInstance()->getRenderer());
}

void SDLGameObject::update() {

}

void SDLGameObject::clean() {

}
