#include "GameState.h"
#include "InputHandler.h"


bool GameState::onExit(){

	bool exiting = true;

	for ( unsigned i = 0; i < objects.size(); i++ ){
		objects[i]->clean();
		delete objects[i];
		objects[i] = nullptr;
	}

	objects.clear();


	for ( unsigned i = 0; i < texture_id_list.size(); i++ ) {
		TextureManager::getInstance()->clearFromTextureMap(texture_id_list[i]);
	}


	InputHandler::getInstance()->reset();


	return exiting;


}
