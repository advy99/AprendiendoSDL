#include "Game.h"
#include <iostream>


Game::Game(){
	gWindow   = nullptr;
	gRenderer = nullptr;
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
		gWindow = SDL_CreateWindow(title.c_str(), XPOS, YPOS,
											SCREEN_WIDTH, SCREEN_HEIGHT, FLAGS);
		if (gWindow == nullptr){
			std::cerr << "Window could not be created. SDL_Error: "
						 << SDL_GetError() << std::endl;
			success = false;
		} else {
			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

			if (gRenderer == nullptr){
				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
			} else {
				std::cerr << "Renderer could not be created. STD_Error: "
							 << SDL_GetError() << std::endl;
				success = false;
			}
		}
	}

	if ( success ) {
		gRunning = true;
	}

	return success;

}

void Game::render() {

	SDL_RenderClear(gRenderer);

	SDL_RenderPresent(gRenderer);

}

void Game::clean() {
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;
	SDL_Quit();
}

void Game::update(){

}

void Game::handleEvents() {
	SDL_Event event;

	if ( SDL_PollEvent(&event) ){
		switch (event.type){
			case SDL_QUIT:
				gRunning = false;
				break;

		}
	}
}

bool Game::running() const {
	return gRunning;
}
