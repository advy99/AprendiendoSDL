#ifndef PLAYSTATE_H_INCLUDED
#define PLAYSTATE_H_INCLUDED

#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include <vector>

class PlayState : public GameState {
	private:
		static const std::string play_id;
		bool checkCollision(const SDLGameObject * p1, const SDLGameObject * p2);

		virtual bool onExit();

	public:
		virtual ~PlayState();
		virtual void update();
		virtual void render();

		virtual bool onEnter();

		virtual std::string getStateID() const;

};



#endif
