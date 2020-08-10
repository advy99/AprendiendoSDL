#include "GameStateMachine.h"


GameStateMachine::~GameStateMachine() {
	while ( !game_states.empty() ) {
		popState();
	}
}

void GameStateMachine::pushState(GameState * state) {
	game_states.push(state);
	game_states.top()->onEnter();

	changing = true;
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

	changing = true;

}


void GameStateMachine::popState() {
	if ( !game_states.empty() ) {
		changing = true;
		if ( game_states.top() != nullptr ) {
			delete game_states.top();
			game_states.top() = nullptr;
			game_states.pop();
		}

	}
}

void GameStateMachine::update() {
	changing = false;
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

bool GameStateMachine::isChanging() {
	return changing;
}


bool GameStateMachine::changing = false;
