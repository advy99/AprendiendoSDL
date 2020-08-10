#include "PauseState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"

PauseState::~PauseState() {
	onExit();
}

std::string PauseState::getStateID() const {
	return pause_id;
}

void PauseState::pauseToMain(){
	Game::getInstance()->getStateMachine()->changeState(new MenuState());
}


void PauseState::resumePlay() {
	Game::getInstance()->getStateMachine()->popState();
}

void PauseState::update() {
	for ( unsigned i = 0; i < pause_objects.size() && !exiting; i++ ) {
		pause_objects[i]->update();
	}
}


void PauseState::render() {
	for ( unsigned i = 0; i < pause_objects.size() && !exiting; i++ ) {
		pause_objects[i]->draw();
	}
}

bool PauseState::onEnter() {
	bool success;
	success = TextureManager::getInstance()->load("assets/resume_button.png",
															"resumeButton", 3,
															Game::getInstance()->getRenderer());

	if ( success ) {
		success = TextureManager::getInstance()->load("assets/main_menu_button.png",
															"mainButton", 3,
															Game::getInstance()->getRenderer());
	}

	if ( success ) {
		pause_objects.clear();
		LoaderParams * main_b = new LoaderParams(200, 100, 200, 80,
																"mainButton");
		LoaderParams * resume_b = new LoaderParams(200, 300, 200, 80, "resumeButton");

		GameObject * main_button = new MenuButton(main_b, pauseToMain);
		GameObject * resume_button = new MenuButton(resume_b, resumePlay);

		pause_objects.push_back(main_button);
		pause_objects.push_back(resume_button);

		delete resume_b;
		delete main_b;

		exiting = false;
	}

	return success;
}


bool PauseState::onExit() {
	for ( unsigned i = 0; i < pause_objects.size(); i++ ){
		pause_objects[i]->clean();
		delete pause_objects[i];
	}

	pause_objects.clear();

	TextureManager::getInstance()->clearFromTextureMap("resumeButton");
	TextureManager::getInstance()->clearFromTextureMap("mainButton");

	InputHandler::getInstance()->reset();


	exiting = true;


	return exiting;

}


const std::string PauseState::pause_id = "PAUSE";
