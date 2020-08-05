#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState * state) {
	game_states.push(state);
	game_states.top()->onEnter();

}

void GameStateMachine::changeState(GameState * state) {

	if ( !game_states.empty() ) {
		if ( game_states.top()->getStateID() != state->getStateID() ){
			popState();
			pushState(state);
		}
	} else {
		pushState(state);
	}

}


void GameStateMachine::popState() {
	if ( !game_states.empty() ) {
		if ( game_states.top()->onExit() ){

			delete game_states.top();
			game_states.pop();

		}
	}

}
