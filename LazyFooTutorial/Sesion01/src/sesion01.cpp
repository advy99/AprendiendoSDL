#include <SDL2/SDL.h>
#include <iostream>
#include <cstdio>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



int main(int argc, char ** argv){

	// window we will render
	SDL_Window * window = nullptr;


	// surface contained by the window
	SDL_Surface * screenSurface = nullptr;

	// initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		std::cerr << "SDL could not be initialized. SDL_Error: "
					 << SDL_GetError() << std::endl;
		exit(-1);
	}


	// create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
									  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
									  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		std::cerr << "Window could not be created. SDL_Error: "
					 << SDL_GetError() << std::endl;
		exit(-1);
	}

	// get window surface
	screenSurface = SDL_GetWindowSurface(window);

	// fill with white
	SDL_FillRect(screenSurface, nullptr,
					 SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	// update the surface
	SDL_UpdateWindowSurface(window);

	// wait two seconds
	SDL_Delay(2000);


	// Destroy the window
	SDL_DestroyWindow(window);

	// Quit SDL
	SDL_Quit();

	return 0;


}
