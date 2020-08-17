#include "TileLayer.h"


TileLayer::TileLayer(const int TILE_SIZE, const std::vector<Tileset> TILESETS)
							:tile_size(TILE_SIZE), tilesets(TILESETS){

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
