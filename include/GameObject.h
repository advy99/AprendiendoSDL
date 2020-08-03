#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "LoaderParams.h"
#include <string>

class GameObject {
	private:

	protected:
		GameObject(const LoaderParams * g_params);


	public:
		GameObject() {};
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;

		virtual ~GameObject(){};
};




#endif
