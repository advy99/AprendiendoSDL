#ifndef GAMEOVERSTATE_H_INCLUDED
#define GAMEOVERSTATE_H_INCLUDED

#include "GameState.h"
#include "GameObject.h"
#include <vector>


class GameOverState : public GameState {
	private:
		static void gameOverToMain();
		static void restartPlay();

		static const std::string game_over_id;

		std::vector<GameObject *> game_over_objects;

		bool exiting;

	public:

		virtual void update();
		virtual void render();
		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const;


};


#endif
