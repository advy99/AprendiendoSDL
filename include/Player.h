#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "SDLGameObject.h"

class Player : public SDLGameObject {

	public:
		Player(const LoaderParams * params);

		virtual void draw();
		virtual void update();
		virtual void clean();

};


#endif
