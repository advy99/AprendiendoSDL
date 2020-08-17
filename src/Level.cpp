#include "Level.h"


std::vector<Tileset> * Level::getTilesets() {
	return &tilesets;
}

std::vector<Layer *> * Level::getLayers() {
	return &layers;
}

void Level::update() {
	for ( unsigned i = 0; i < layers.size(); i++ ) {
		layers[i]->update();
	}
}



void Level::render() {
	for ( unsigned i = 0; i < layers.size(); i++ ) {
		layers[i]->render();
	}
}
