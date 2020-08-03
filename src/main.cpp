#include <iostream>
#include "Game.h"


int main(int argc, char ** argv) {

	Game * myGame;

	myGame = new Game();

	myGame->init("Capitulo 1", 100, 100, 640, 480, 0);

	while ( myGame->running() ) {
		myGame->handleEvents();
		myGame->update();
		myGame->render();
		SDL_Delay(10);
	}

	myGame->clean();



	return 0;
}
