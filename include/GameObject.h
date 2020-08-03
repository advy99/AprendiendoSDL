#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include <string>

class GameObject {
	private:

	protected:
		int x_pos;
		int y_pos;

		std::string texture_id;

		int current_frame;
		int current_row;

		int width;
		int height;

	public:
		virtual void load(const int X, const int Y, const int WIDTH, const int HEIGHT,
					 const std::string id);
		virtual void draw(SDL_Renderer * g_renderer);
		virtual void update();
		virtual void clean();

};




#endif
