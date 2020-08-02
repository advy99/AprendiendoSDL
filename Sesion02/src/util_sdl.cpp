#include "util_sdl.h"

#include <iostream>

bool initSDL(SDL_Window * & gWindow, SDL_Surface * & gScreenSurface,
				 const int SCREEN_WIDTH, const int SCREEN_HEIGHT){
	// initialization flag
	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		std::cerr << "SDL could not initialize. SDL_Error: "
					 << SDL_GetError() << std::endl;
		success = false;
	} else {
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
											SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == nullptr){
			std::cerr << "Window could not be created. SDL_Error: "
						 << SDL_GetError() << std::endl;
			success = false;
		} else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;

}



bool loadMedia(SDL_Surface * & gSurface, const std::string file) {
	bool success = true;

	gSurface = SDL_LoadBMP(file.c_str());

	if (gSurface == nullptr){
		std::cerr << "Unable to load image " << file << ". SDL_Error: "
					 << SDL_GetError() << std::endl;
		success = false;
	}

	return success;
}



void closeSDL(SDL_Surface * & gSurface, SDL_Window * & gWindow){
	SDL_FreeSurface(gSurface);
	gSurface = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	SDL_Quit();
}
