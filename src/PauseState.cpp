#include "PauseState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"

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
	for ( unsigned i = 0; i < pause_objects.size() &&
								!GameStateMachine::isChanging(); i++ ) {
		pause_objects[i]->update();
	}
}


void PauseState::render() {
	for ( unsigned i = 0; i < pause_objects.size() &&
								!GameStateMachine::isChanging(); i++ ) {
		pause_objects[i]->draw();
	}
}

bool PauseState::onEnter() {
	bool success;
	success = TextureManager::getInstance()->load("assets/resume_button.png",
															"resumeButton",
															Game::getInstance()->getRenderer());

	if ( success ) {
		success = TextureManager::getInstance()->load("assets/main_menu_button.png",
															"mainButton",
															Game::getInstance()->getRenderer());
	}

	if ( success ) {
		pause_objects.clear();
		LoaderParams * main_b = new LoaderParams(200, 100, 200, 80,
																"mainButton", 3);
		LoaderParams * resume_b = new LoaderParams(200, 300, 200, 80, "resumeButton", 3);

		GameObject * main_button = new MenuButton();
		main_button->load(main_b);
		(dynamic_cast<MenuButton *> (main_button) )->setCallback(pauseToMain);

		GameObject * resume_button = new MenuButton();
		resume_button->load(resume_b);
		(dynamic_cast<MenuButton *> (resume_button) )->setCallback(pauseToMain);

		pause_objects.push_back(main_button);
		pause_objects.push_back(resume_button);

		delete resume_b;
		delete main_b;

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



	return true;

}


const std::string PauseState::pause_id = "PAUSE";
