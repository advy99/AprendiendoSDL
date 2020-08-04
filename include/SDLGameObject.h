#ifndef SDLGAMEOBJECT_H_INCLUDED
#define SDLGAMEOBJECT_H_INCLUDED

#include <string>
#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"

#include "SDL2/SDL.h"

class SDLGameObject : public GameObject{
	private:

	protected:
		Vector2D position;

		int current_frame;
		int current_row;

		int width;
		int height;

		std::string texture_id;

	public:
		//virtual void load(const int X, const int Y, const int WIDTH, const int HEIGHT,
		//			 const std::string id);
		SDLGameObject(const LoaderParams * params);

		virtual void draw();
		virtual void update();
		virtual void clean();

};






#endif
