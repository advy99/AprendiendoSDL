#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL2/SDL.h>
#include <string>

class Game{
	private:
		bool gRunning;

		SDL_Window * gWindow;
		SDL_Renderer * gRenderer;

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
