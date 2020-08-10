#ifndef GAMESTATEMACHINE_H_INCLUDED
#define GAMESTATEMACHINE_H_INCLUDED

#include "GameState.h"
#include <stack>

class GameStateMachine {
	private:
		std::stack<GameState *> game_states;
		static bool changing;


	public:
		~GameStateMachine();
		void pushState(GameState * state);
		void changeState(GameState * state);
		void popState();

		void update();
		void render();

		static bool isChanging() ;


};



#endif
