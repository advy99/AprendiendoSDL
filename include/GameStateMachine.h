#ifndef GAMESTATEMACHINE_H_INCLUDED
#define GAMESTATEMACHINE_H_INCLUDED

#include "GameState.h"
#include <stack>

class GameStateMachine {
	private:
		std::stack<GameState *> game_states;


	public:
		void pushState(GameState * state);
		void changeState(GameState * state);
		void popState();

};



#endif
