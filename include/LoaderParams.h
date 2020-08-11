#ifndef LOADERPARAMS_H_INCLUDED
#define LOADERPARAMS_H_INCLUDED

#include <string>
#include <SDL2/SDL.h>

class LoaderParams {
	private:

		int x_pos;
		int y_pos;


		int width;
		int height;

		std::string texture_id;

		int num_frames;
		int callback_id;
		int anim_speed;

		SDL_RendererFlip flip;

	public:
		LoaderParams(const int X, const int Y, const int WIDTH, const int HEIGHT,
						 const std::string id, const int NUM_FRAMES,
						 const int CALLBACK_ID = 0, const int ANIM_SPEED = 0,
						 const SDL_RendererFlip flip = SDL_FLIP_NONE);

		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;
		std::string getTextureId() const;

		SDL_RendererFlip getFlip() const;
		int getAnimSpeed() const;
		int getCallbackID() const;
		int getNumFrames() const;


};


#endif
