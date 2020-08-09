#ifndef ANIMATEDGRAPHIC_H_INCLUDED
#define ANIMATEDGRAPHIC_H_INCLUDED

#include "SDLGameObject.h"
#include "LoaderParams.h"

class AnimatedGraphic : public SDLGameObject{
	private:
		int animation_speed;

	public:
		AnimatedGraphic(const LoaderParams * params, const int speed);

		virtual void draw();
		virtual void update();
		virtual void clean();

};


#endif
