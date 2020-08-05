#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "PlayState.h"
#include "MenuState.h"
#include "GameStateMachine.h"
#include <vector>

class Game{
	private:
		bool g_running;

		SDL_Window * g_window;
		SDL_Renderer * g_renderer;

		int current_frame;
		TextureManager * g_textures = TextureManager::getInstance();
		GameStateMachine * game_state_machine;

		std::vector<GameObject *> game_objects;

		Game();

		static Game * instance;

	public:
		static Game * getInstance();

		bool init(const std::string title, const int XPOS, const int YPOS,
					 const int SCREEN_WIDTH, const int SCREEN_HEIGHT,
					 const int FLAGS);
		void render();
		void draw();
		void update();
		void handleEvents();
		void clean();

		bool running() const;

		SDL_Renderer * getRenderer() const;
		void quit();


};


#endif
