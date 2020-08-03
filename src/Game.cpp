#include "Game.h"
#include <iostream>


Game::Game(){
	g_window      = nullptr;
	g_renderer    = nullptr;
	g_running     = false;
	current_frame = 0;
}


Game::~Game() {
	clean();
}

bool Game::init(const std::string title, const int XPOS, const int YPOS,
					 const int SCREEN_WIDTH, const int SCREEN_HEIGHT,
					 const int FLAGS){

	// initialization flag
	bool success = true;

	if (SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
		std::cerr << "SDL could not initialize. SDL_Error: "
					 << SDL_GetError() << std::endl;
		success = false;
	} else {
		g_window = SDL_CreateWindow(title.c_str(), XPOS, YPOS,
											SCREEN_WIDTH, SCREEN_HEIGHT, FLAGS);
		if (g_window == nullptr){
			std::cerr << "Window could not be created. SDL_Error: "
						 << SDL_GetError() << std::endl;
			success = false;
		} else {
			g_renderer = SDL_CreateRenderer(g_window, -1, 0);

			if (g_renderer == nullptr){
				std::cerr << "Renderer could not be created. STD_Error: "
							 << SDL_GetError() << "." << std::endl;
				success = false;
			} else {
				SDL_SetRenderDrawColor(g_renderer, 255, 0, 0, 255);

				g_textures.load("assets/animate.png", "animate", g_renderer);

			}
		}
	}

	if ( success ) {
		g_running = true;
	}

	return success;

}

void Game::render() {

	SDL_RenderClear(g_renderer);

	g_textures.draw("animate", 0, 0, 128, 82, g_renderer);

	g_textures.drawFrame("animate", 100, 100, 128, 82, 1, current_frame, g_renderer);

	SDL_RenderPresent(g_renderer);

}

void Game::clean() {

	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;

	SDL_Quit();
}

void Game::update(){

	current_frame = int( (SDL_GetTicks() / 100 ) % 6 );
}

void Game::handleEvents() {
	SDL_Event event;

	if ( SDL_PollEvent(&event) ){
		switch (event.type){
			case SDL_QUIT:
				g_running = false;
				break;

		}
	}
}

bool Game::running() const {
	return g_running;
}
