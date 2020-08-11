#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Player : public SDLGameObject {
	private:
		void handleInput();

	public:
		Player();

		virtual void load(const LoaderParams * params);

		virtual void draw();
		virtual void update();
		virtual void clean();

};

class PlayerCreator : public BaseCreator {

	public:
		GameObject * createGameObject() const;

};

#endif
