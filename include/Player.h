#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "GameObject.h"

class Player : public GameObject {

	public:
		void load(const int X, const int Y, const int WIDTH, const int HEIGHT,
					 const std::string id);
		void draw(SDL_Renderer * g_renderer);
		void update();
		void clean();

};


#endif
