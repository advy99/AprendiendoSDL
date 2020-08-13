#include "Game.h"
#include <iostream>
#include "InputHandler.h"


Game::Game(){
	g_window           = nullptr;
	g_renderer         = nullptr;
	g_running          = false;
	current_frame      = 0;
	game_state_machine = nullptr;
}


void Game::quit(){
	g_running = false;
}
// lo llamamos manualmente al ser singleton
//Game::~Game() {
//	clean();
//}

Game * Game::getInstance(){
	if (instance == nullptr){
		instance = new Game();
	}

	return instance;
}

bool Game::init(const std::string title, const int XPOS, const int YPOS,
					 const int SCREEN_WIDTH, const int SCREEN_HEIGHT,
					 const int FLAGS){

	// initialization flag
	bool success = true;

	if (SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
		std::cerr << "SDL could not initialize. SDL_Error: "
					 << SDL_GetError() << std::endl;
		success = false;
	} else {
		g_window = SDL_CreateWindow(title.c_str(), XPOS, YPOS,
											SCREEN_WIDTH, SCREEN_HEIGHT, FLAGS);
		if (g_window == nullptr){
			std::cerr << "Window could not be created. SDL_Error: "
						 << SDL_GetError() << std::endl;
			success = false;
		} else {
			g_renderer = SDL_CreateRenderer(g_window, -1, 0);

			if (g_renderer == nullptr){
				std::cerr << "Renderer could not be created. STD_Error: "
							 << SDL_GetError() << "." << std::endl;
				success = false;
			} else {
				SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);

				// g_textures->load("assets/animate.png", "animate", g_renderer);

				// Player * game_player = new Player(new LoaderParams(300, 300,
				// 																	128, 82,
				// 																  	"animate"));
				// Enemy * game_enemy = new Enemy(new LoaderParams(0, 0, 128, 82,
				// 															   "animate"));

				// game_objects.push_back(game_player);
				// game_objects.push_back(game_enemy);

				InputHandler::getInstance()->initialiseJoysticks();

				GameObjectFactory::getInstance()->registerType("MenuButton",
																		new MenuButtonCreator());

				GameObjectFactory::getInstance()->registerType("Player",
																		new PlayerCreator());

				GameObjectFactory::getInstance()->registerType("Enemy",
																		new EnemyCreator());

				game_state_machine = new GameStateMachine();
				game_state_machine->changeState(new MainMenuState());

			}
		}
	}

	g_running = success;

	return success;

}

void Game::render() {

	SDL_RenderClear(g_renderer);

	//g_textures.draw("animate", 0, 0, 128, 82, g_renderer);

	//g_textures.drawFrame("animate", 100, 100, 128, 82, 1, current_frame, g_renderer);

	//for (unsigned i = 0; i < game_objects.size(); i++){
	//	game_objects[i]->draw();
	//}

	game_state_machine->render();

	SDL_RenderPresent(g_renderer);

}

void Game::clean() {

	if ( g_window != nullptr )
		SDL_DestroyWindow(g_window);
	g_window = nullptr;

	if (g_renderer != nullptr)
		SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;

	SDL_Quit();

	for (unsigned i = 0; i < game_objects.size(); i++){
		delete game_objects[i];
	}
	game_objects.clear();

	if (g_textures != nullptr)
		g_textures->clean();
	g_textures = nullptr;

	InputHandler::getInstance()->clean();

	if (game_state_machine == nullptr){
		delete game_state_machine;
	}

	game_state_machine = nullptr;

	if (instance != nullptr){
		delete instance;
	}

	instance = nullptr;
}

void Game::update(){

	game_state_machine->update();
	//current_frame = int( (SDL_GetTicks() / 100 ) % 6 );
	// for (unsigned i = 0; i < game_objects.size(); i++){
	// 	game_objects[i]->update();
	// }
}

void Game::handleEvents() {
	InputHandler::getInstance()->update();

	if ( InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_RETURN) ) {
		game_state_machine->changeState(new PlayState());
	}
}

bool Game::running() const {
	return g_running;
}

SDL_Renderer * Game::getRenderer() const {
	return g_renderer;
}

GameStateMachine * Game::getStateMachine() {
	return game_state_machine;
}


Game * Game::instance = nullptr;
