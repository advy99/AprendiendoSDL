#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "GameObject.h"

class Enemy : public GameObject {
	private:

	public:
		void load(const int X, const int Y, const int WIDTH, const int HEIGHT,
					 const std::string texture_id);
		void draw(SDL_Renderer * g_renderer);
		void update();
		void clean();

};



#endif
