#include "TileLayer.h"
#include "Game.h"


TileLayer::TileLayer(const int TILE_SIZE, const std::vector<Tileset> TILESETS)
							:tile_size(TILE_SIZE), tilesets(TILESETS){
	position = Vector2D(0,0);
	velocity = Vector2D(0,0);

	num_cols = (Game::getInstance()->getGameWidth() / tile_size);
	num_rows = (Game::getInstance()->getGameHeight() / tile_size);

}


void TileLayer::setTileIDs(const std::vector<std::vector<int> > & data) {
	tile_ids = data;
}


void TileLayer::setTileSize(const int SIZE) {
	tile_size = SIZE;
}

Tileset TileLayer::getTileset(const int TILE_ID) const {
	return tilesets[TILE_ID];
}
