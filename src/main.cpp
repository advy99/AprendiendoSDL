#include <iostream>
#include "Game.h"


int main() {

	const int FPS = 60;
	const int DELAY_TIME = 1000.0 / FPS;

	Uint32 frame_start, frame_time;

	Game * myGame;

	myGame = Game::getInstance();

	myGame->init("Capitulo 1", 100, 100, 640, 480, 0);

	while ( myGame->running() ) {
		frame_start = SDL_GetTicks();

		myGame->handleEvents();
		myGame->update();
		myGame->render();

		frame_time = SDL_GetTicks() - frame_start;

		if (frame_time < DELAY_TIME){
			SDL_Delay( (int)(DELAY_TIME - frame_time) ) ;
		}
	}

	myGame->clean();



	return 0;
}
