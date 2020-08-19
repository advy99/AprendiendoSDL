#include "LevelParser.h"
#include "Game.h"
#include "TileLayer.h"
#include "base64.h"
#include "zlib.h"


Level * LevelParser::parseLevel(const char * level_file){
	tinyxml2::XMLDocument level_document;
	level_document.LoadFile(level_file);


	Level * level = new Level();


	tinyxml2::XMLElement * root = level_document.RootElement();

	tile_size = root->IntAttribute("tilewidth");
	width = root->IntAttribute("width");
	height = root->IntAttribute("height");

	for ( tinyxml2::XMLElement * element = root->FirstChildElement();
			element != nullptr;
			element = element->NextSiblingElement() ) {
		if ( element->Value() == std::string("tileset") ) {
			parseTilesets(element, level->getTilesets() );
		}
	}


	for ( tinyxml2::XMLElement * element = root->FirstChildElement();
			element != nullptr;
			element = element->NextSiblingElement() ) {
		if ( element->Value() == std::string("layer") ) {
			parseTileLayer(element, level->getLayers(), level->getTilesets());
		}
	}



	return level;

}


void LevelParser::parseTilesets(tinyxml2::XMLElement * tile_element,
										  std::vector<Tileset> * tilesets){

	const char * element_source = tile_element->FirstChildElement()->
											Attribute("source");
	const char * element_name = tile_element->Attribute("name");

	TextureManager::getInstance()->load(element_source, element_name,
													Game::getInstance()->getRenderer());

	Tileset tileset;

	tileset.width = tile_element->FirstChildElement()->IntAttribute("width");
	tileset.height = tile_element->FirstChildElement()->IntAttribute("height");

	tileset.first_grid_id = tile_element->IntAttribute("firstgrid");
	tileset.tile_width = tile_element->IntAttribute("tilewidth");
	tileset.tile_height = tile_element->IntAttribute("tileheight");
	tileset.spacing = tile_element->IntAttribute("spacing");
	tileset.margin = tile_element->IntAttribute("margin");
	tileset.name = tile_element->Attribute("name");

	tileset.num_columns = tileset.width / (tileset.tile_width + tileset.spacing);

	tilesets->push_back(tileset);

}


void LevelParser::parseTileLayer(tinyxml2::XMLElement * tile_element,
											std::vector<Layer *> * layers,
											const std::vector<Tileset> * tilesets){
	TileLayer * tile_layer = new TileLayer(tile_size, *tilesets);

	std::vector<std::vector<int> > data;

	std::string decoded_ids;

	tinyxml2::XMLElement * data_node;


	for ( tinyxml2::XMLElement * element = tile_element->FirstChildElement();
			element != nullptr;
			element = element->NextSiblingElement() ) {
		if ( element->Value() == std::string("data") ) {
			data_node = element;
		}
	}

	for ( tinyxml2::XMLNode * element = data_node->FirstChild();
			element != nullptr;
			element = element->NextSibling() ) {
		tinyxml2::XMLText * text = element->ToText();
		std::string node_text = text->Value();
		decoded_ids = base64_decode(node_text);
	}

	uLongf num_gids = width * height * sizeof(int);
	std::vector<unsigned> gids(num_gids);

	uncompress( (Bytef *)&gids[0], &num_gids,
					(const Bytef *) decoded_ids.c_str(),
					decoded_ids.size()	);

	std::vector<int> layer_row(width);

	for ( int i = 0; i < height; i++ ){
		data.push_back(layer_row);
	}

	for ( int i = 0; i < height; i++ ) {
		for (int j = 0; j < width; j++){
			data[i][j] = gids[i * width + j];
		}
	}

	tile_layer->setTileIDs(data);
	layers->push_back(tile_layer);

}
