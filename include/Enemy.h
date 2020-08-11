#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "SDLGameObject.h"

class Enemy : public SDLGameObject {
	private:

	public:
		Enemy();
		virtual void load(const LoaderParams * params);
		virtual void draw();
		virtual void update();
		virtual void clean();

};



#endif
