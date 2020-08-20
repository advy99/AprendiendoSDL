#ifndef TILELAYER_H_INCLUDED
#define TILELAYER_H_INCLUDED

#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"
#include <vector>

class TileLayer : public Layer {
	private:
		int num_cols;
		int num_rows;
		int tile_size;

		Vector2D position;
		Vector2D velocity;

		const std::vector<Tileset> tilesets;

		std::vector<std::vector<int> > tile_ids;

	public:
		TileLayer(const int TILE_SIZE, const std::vector<Tileset> tilesets);

		virtual void update();
		virtual void render();

		void setTileIDs(const std::vector<std::vector<int> > & data);
		void setTileSize(const int SIZE);

		Tileset getTileset(const int TILE_ID) const;
};

#endif
