#include "ObjectLayer.h"


ObjectLayer::~ObjectLayer(){
	for ( unsigned i = 0; i < game_objects.size(); i++ ) {
		delete game_objects[i];
	}

}


void ObjectLayer::update() {
	for ( unsigned i = 0; i < game_objects.size(); i++ ) {
		game_objects[i]->update();
	}
}


void ObjectLayer::render() {
	for ( unsigned i = 0; i < game_objects.size(); i++ ) {
		game_objects[i]->draw();
	}
}

std::vector<GameObject *> * ObjectLayer::getGameObjects() {
	return &game_objects;
}
