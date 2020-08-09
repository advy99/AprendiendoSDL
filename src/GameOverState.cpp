#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "InputHandler.h"

std::string GameOverState::getStateID() const {
	return game_over_id;
}

void GameOverState::gameOverToMain() {
	Game::getInstance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::restartPlay() {
	Game::getInstance()->getStateMachine()->changeState(new PlayState());

}

bool GameOverState::onEnter() {
	bool success;
	success = TextureManager::getInstance()->load("assets/gameover.png",
															"gameOverText", 2,
															Game::getInstance()->getRenderer());

	if ( success ) {
		success = TextureManager::getInstance()->load("assets/main_menu_button.png",
															"mainButton", 3,
															Game::getInstance()->getRenderer());
	}

	if ( success ) {
		success = TextureManager::getInstance()->load("assets/restart_button.png",
															"restartButton", 3,
															Game::getInstance()->getRenderer());
	}

	if ( success ) {
		LoaderParams * params_game_over = new LoaderParams(200, 100,
																			190, 30,
																		  	"gameOverText");
		LoaderParams * params_main = new LoaderParams(200, 200, 200, 80,
																	"mainButton");
		LoaderParams * params_restart = new LoaderParams(200, 300, 200, 80,
																		"restartButton");

		GameObject * game_over = new AnimatedGraphic(params_game_over, 2);
		GameObject * main_but = new MenuButton(params_main, gameOverToMain);
		GameObject * restart_but = new MenuButton(params_restart, restartPlay);

		game_over_objects.push_back(game_over);
		game_over_objects.push_back(main_but);
		game_over_objects.push_back(restart_but);

		delete params_game_over;
		delete params_main;
		delete params_restart;
	}

	return success;
}

bool GameOverState::onExit(){


	for ( unsigned i = 0; i < game_over_objects.size(); i++ ){
		game_over_objects[i]->clean();
		delete game_over_objects[i];
	}

	game_over_objects.clear();


	TextureManager::getInstance()->clearFromTextureMap("gameOverText");
	TextureManager::getInstance()->clearFromTextureMap("restartButton");
	TextureManager::getInstance()->clearFromTextureMap("mainButton");

	InputHandler::getInstance()->reset();


	exiting = true;


	return exiting;


}


void GameOverState::update() {
	for ( unsigned i = 0; i < game_over_objects.size() && !exiting; i++ ) {
		game_over_objects[i]->update();
	}
}


void GameOverState::render() {
	for ( unsigned i = 0; i < game_over_objects.size() && !exiting; i++ ) {
		game_over_objects[i]->draw();
	}
}







const std::string GameOverState::game_over_id = "GAMEOVER";
