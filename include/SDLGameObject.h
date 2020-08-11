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
		Vector2D velocity;
		Vector2D acceleration;

		int current_frame;
		int current_row;

		int width;
		int height;

		SDL_RendererFlip last_flip;

		std::string texture_id;

		int num_frames;

	public:
		//virtual void load(const int X, const int Y, const int WIDTH, const int HEIGHT,
		//			 const std::string id);
		SDLGameObject();

		virtual void draw();
		virtual void update();
		virtual void clean();

		Vector2D getPosition() const;
		int getWidth() const;
		int getHeight() const;

		virtual void load(const LoaderParams * params);



};






#endif
