#include "LevelParser.h"


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
