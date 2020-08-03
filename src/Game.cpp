#include "Game.h"
#include <iostream>


Game::Game(){
	g_window   = nullptr;
	g_renderer = nullptr;
	g_texture  = nullptr;
	g_running  = false;
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
				SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);

				SDL_Surface * asset_surface = SDL_LoadBMP("assets/animate.bmp");

				g_texture = SDL_CreateTextureFromSurface(g_renderer, asset_surface);

				SDL_FreeSurface(asset_surface);

				// para la animacion no es necesario
				//SDL_QueryTexture(g_texture, nullptr, nullptr, &g_source_rectangle.w,
				//					  &g_source_rectangle.h);

				g_destination_rectangle.x = g_source_rectangle.x = 0;
				g_destination_rectangle.y = g_source_rectangle.y = 0;
				g_destination_rectangle.w = g_source_rectangle.w = 128;
				g_destination_rectangle.h = g_source_rectangle.h = 82;

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

	// le pasamos lo que hemos declarado como el rectangulo de vision
	SDL_RenderCopyEx(g_renderer, g_texture,
						  &g_source_rectangle, &g_destination_rectangle,
						  0, 0, SDL_FLIP_HORIZONTAL);

	// si le pasamos nulo, utilizará toda la pantalla y con toda la textura
	//SDL_RenderCopy(g_renderer, g_texture, nullptr, nullptr);

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

	g_source_rectangle.x = 128 * int( (SDL_GetTicks() /100 ) % 6 );
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
