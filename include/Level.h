#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <vector>
#include <string>

struct Tileset {
	int first_grid_id;
	int tile_width;
	int tile_height;
	int spacing;
	int margin;
	int width;
	int height;
	int num_columns;
	std::string name;
};

class Level {
	private:
		std::vector<Tileset> tilesets;


	public:
		Level();
		~Level();

		void update();
		void render();

		std::vector<Tileset> * getTilesets() const;

};


#endif
