#include "TileLayer.h"
#include "Game.h"
#include <iostream>


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
	bool found = false;
	Tileset tileset;

	for ( unsigned i = 0; i < tilesets.size() && !found; i++ ) {

		if ( i + 1 < tilesets.size() - 1){

			if ( TILE_ID >= tilesets[i].first_grid_id &&
				  TILE_ID < tilesets[i + 1].first_grid_id	) {
				found = true;
				tileset = tilesets[i];
			}

		} else {

			found = true;
			tileset = tilesets[i];
		}

	}

	if ( !found ) {
		std::cerr << "WARNING: Tileset not found: returning empty tileset" << std::endl;
	}

	return tileset;
}

void TileLayer::update(){
	position += velocity;
}

void TileLayer::render() {
	int x = 0;
	int y = 0;
	int x2 = 0;
	int y2 = 0;

	x = position.getX() / tile_size;
	y = position.getY() / tile_size;

	x2 = int(position.getX()) % tile_size;
	y2 = int(position.getY()) % tile_size;

	for ( int i = 0; i < num_rows; i++ ) {
		for ( int j = 0; j < num_cols; j++ ) {
			int id = tile_ids[i + y][j + x];

			if ( id != 0 ) {
				Tileset tileset = getTileset(id);

				id--;

				TextureManager::getInstance()->drawTile(tileset.name, 2, 2,
								(j * tile_size) - x2,
								(i * tile_size) - y2,
								tile_size, tile_size,
								(id - (tileset.first_grid_id - 1)) / tileset.num_columns,
								(id - (tileset.first_grid_id - 1)) % tileset.num_columns,
								Game::getInstance()->getRenderer());

			}

		}
	}

}
