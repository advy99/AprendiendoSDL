#include "GameStateMachine.h"


GameStateMachine::~GameStateMachine() {
	while ( !game_states.empty() ) {
		popState();
	}
}

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
		if ( game_states.top() != nullptr ) {
			delete game_states.top();
			game_states.top() = nullptr;
			game_states.pop();
		}

	}
}

void GameStateMachine::update() {
	if ( !game_states.empty() ) {
		if ( game_states.top() != nullptr )
			game_states.top()->update();
	}
}

void GameStateMachine::render() {
	if ( !game_states.empty() ) {
		game_states.top()->render();
	}
}
