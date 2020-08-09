#ifndef PLAYSTATE_H_INCLUDED
#define PLAYSTATE_H_INCLUDED

#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include <vector>

class PlayState : public GameState {
	private:
		static const std::string play_id;
		std::vector<GameObject *> play_objects;
		bool checkCollision(const SDLGameObject * p1, const SDLGameObject * p2);


	public:
		virtual ~PlayState() = default;
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const;

};



#endif
