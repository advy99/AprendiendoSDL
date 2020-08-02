#ifndef UTIL_SDL
#define UTIL_SDL

#include <SDL2/SDL.h>
#include <string>

// starts SDL
bool initSDL(SDL_Window * & gWindow, SDL_Surface * & gScreenSurface,
				 const int SCREEN_WIDTH, const int SCREEN_HEIGHT);

// load bmp file
bool loadMedia(SDL_Surface * & gSurface, const std::string file);

// frees media and shuts down SDL
void closeSDL(SDL_Surface * & gSurface, SDL_Window * & gWindow);



#endif
