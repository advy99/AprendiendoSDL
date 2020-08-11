#include "LoaderParams.h"

LoaderParams::LoaderParams(const int X, const int Y,
									const int WIDTH, const int HEIGHT,
									const std::string id, const int NUM_FRAMES,
									const int CALLBACK_ID, const int ANIM_SPEED,
									const SDL_RendererFlip INIT_FLIP)
									:x_pos(X), y_pos(Y), width(WIDTH), height(HEIGHT),
									texture_id(id), num_frames(NUM_FRAMES),
									callback_id(CALLBACK_ID), anim_speed(ANIM_SPEED),
									flip(INIT_FLIP){


}

int LoaderParams::getX() const{
	return x_pos;
}

int LoaderParams::getY() const{
	return y_pos;
}


int LoaderParams::getWidth() const{
	return width;
}


int LoaderParams::getHeight() const{
	return height;
}


std::string LoaderParams::getTextureId() const{
	return texture_id;
}

SDL_RendererFlip LoaderParams::getFlip() const {
	return flip;
}

int LoaderParams::getAnimSpeed() const {
	return anim_speed;
}

int LoaderParams::getCallbackID() const {
	return callback_id;
}

int LoaderParams::getNumFrames() const {
	return num_frames;
}
