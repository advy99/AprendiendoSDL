#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "TextureManager.h"

class Game{
	private:
		bool g_running;

		SDL_Window * g_window;
		SDL_Renderer * g_renderer;

		int current_frame;
		TextureManager g_textures;

	public:
		Game();
		~Game();

		bool init(const std::string title, const int XPOS, const int YPOS,
					 const int SCREEN_WIDTH, const int SCREEN_HEIGHT,
					 const int FLAGS);
		void render();
		void update();
		void handleEvents();
		void clean();

		bool running() const;


};


#endif
