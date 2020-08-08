#ifndef PAUSESTATE_H_INCLUDED
#define PAUSESTATE_H_INCLUDED

#include "GameState.h"
#include "GameObject.h"
#include <vector>

class PauseState : public GameState {
	private:
		static void pauseToMain();
		static void resumePlay();

		static const std::string pause_id;

		std::vector<GameObject *> pause_objects;

		bool exiting;


	public:

		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const;


};


#endif
