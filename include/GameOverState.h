#ifndef GAMEOVERSTATE_H_INCLUDED
#define GAMEOVERSTATE_H_INCLUDED

#include "MenuState.h"
#include "GameObject.h"
#include <vector>


class GameOverState : public MenuState {
	private:
		static void gameOverToMain();
		static void restartPlay();

		static const std::string game_over_id;


		virtual bool onExit();
		virtual void setCallbacks(const std::vector<Callback> & callbacks);

	public:
		virtual ~GameOverState();
		virtual void update();
		virtual void render();
		virtual bool onEnter();

		virtual std::string getStateID() const;


};


#endif
