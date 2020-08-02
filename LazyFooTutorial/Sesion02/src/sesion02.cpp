#include <iostream>
#include <util_sdl.h>


int main(int argc, char ** argv){
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Window * gWindow = nullptr;
	SDL_Surface * gScreenSurface = nullptr;
	SDL_Surface * gHelloWorld = nullptr;

	if ( !initSDL(gWindow, gScreenSurface, SCREEN_WIDTH, SCREEN_HEIGHT) ){
		std::cerr << "Failed to initialize" << std::endl;
		exit(-1);
	}

	if ( !loadMedia(gHelloWorld, "hello_world.bmp") ){
		std::cerr << "Failed to load the media" << std::endl;
		exit(-1);
	}

	SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);
	SDL_UpdateWindowSurface(gWindow);

	SDL_Delay(2000);

	closeSDL(gHelloWorld, gWindow);

}
