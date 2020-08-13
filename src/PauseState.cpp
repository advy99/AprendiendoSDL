#include "PauseState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "StateParser.h"

PauseState::~PauseState() {
	onExit();
}

std::string PauseState::getStateID() const {
	return pause_id;
}

void PauseState::pauseToMain(){
	Game::getInstance()->getStateMachine()->changeState(new MainMenuState());
}


void PauseState::resumePlay() {
	Game::getInstance()->getStateMachine()->popState();
}

void PauseState::update() {
	for ( unsigned i = 0; i < objects.size() &&
								!GameStateMachine::isChanging(); i++ ) {
		objects[i]->update();
	}
}


void PauseState::render() {
	for ( unsigned i = 0; i < objects.size() &&
								!GameStateMachine::isChanging(); i++ ) {
		objects[i]->draw();
	}
}

bool PauseState::onEnter() {
	bool success = true;

	StateParser parser;

	parser.parseState("assets/test.xml", pause_id, &objects,
							&texture_id_list);

	callbacks.push_back(pauseToMain);
	callbacks.push_back(resumePlay);

	setCallbacks(callbacks);

	return success;
}


bool PauseState::onExit() {
	for ( unsigned i = 0; i < objects.size(); i++ ){
		objects[i]->clean();
		delete objects[i];
	}

	objects.clear();
	callbacks.clear();

	for ( unsigned i = 0; i < texture_id_list.size(); i++ ) {
		TextureManager::getInstance()->clearFromTextureMap(texture_id_list[i]);
	}

	InputHandler::getInstance()->reset();



	return true;

}


void PauseState::setCallbacks(const std::vector<Callback> & callbacks) {
	for ( unsigned i = 0; i < objects.size(); i++ ) {
		MenuButton * button = dynamic_cast<MenuButton*> (objects[i]) ;
		if ( button != nullptr ) {
			button->setCallback(callbacks[button->getCallbackID() ]);
		}
	}
}


const std::string PauseState::pause_id = "PAUSE";
