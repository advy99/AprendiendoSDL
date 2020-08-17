#ifndef LEVELPARSER_H_INCLUDE
#define LEVELPARSER_H_INCLUDE

#include "tinyxml2.h"
#include "Level.h"

class LevelParser {
	private:

		int tile_size;
		int width;
		int height;


		void parseTilesets(tinyxml2::XMLElement * tileset_root,
								 std::vector<Tileset> * tilesets);

		void parseTileLayer(tinyxml2::XMLElement * tile_element,
								  std::vector<Layer *> * layers,
								  const std::vector<Tileset> * tilesets);


	public:
		Level* parseLevel(const char * level_file);

};


#endif
