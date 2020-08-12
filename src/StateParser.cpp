#include "StateParser.h"
#include "Game.h"

bool StateParser::parseState(const char * state_file,
									  const std::string state_id,
									  std::vector<GameObject *> * objects,
									  std::vector<std::string> * texture_ids){
	tinyxml2::XMLDocument xml_doc;

	bool success;

	success = xml_doc.LoadFile(state_file);

	if ( success ) {
		tinyxml2::XMLElement * root = xml_doc.RootElement();

		tinyxml2::XMLElement * state_root = nullptr;

		for ( tinyxml2::XMLElement * xml_ele = root->FirstChildElement();
				xml_ele != nullptr; xml_ele = xml_ele->NextSiblingElement() ) {
			if ( xml_ele->Value() == state_id ) {
				state_root = xml_ele;
			}
		}

		tinyxml2::XMLElement * texture_root = nullptr;

		for ( tinyxml2::XMLElement * xml_ele = state_root->FirstChildElement();
				xml_ele != nullptr; xml_ele = xml_ele->NextSiblingElement() ) {
			if ( xml_ele->Value() == std::string("TEXTURES" )) {
				texture_root = xml_ele;
			}
		}

		parseTextures(texture_root, texture_ids);


		tinyxml2::XMLElement * object_root = nullptr;

		for ( tinyxml2::XMLElement * xml_ele = state_root->FirstChildElement();
				xml_ele != nullptr; xml_ele = xml_ele->NextSiblingElement() ) {
			if ( xml_ele->Value() == std::string("OBJECTS" )) {
				texture_root = xml_ele;
			}
		}

		parseObjects(object_root, objects);


	} else {
		std::cerr << xml_doc.ErrorStr() << std::endl;
	}


	return success;
}


void StateParser::parseTextures(tinyxml2::XMLElement * state,
										 std::vector<std::string> * texture_ids) {

	for ( tinyxml2::XMLElement * element = state->FirstChildElement();
			element != nullptr; element = element->NextSiblingElement() ){
		std::string file_name_atribbute = element->Attribute("filename");
		std::string id_atribbute = element->Attribute("ID");

		texture_ids->push_back(id_atribbute);
		TextureManager::getInstance()->load(file_name_atribbute, id_atribbute,
														Game::getInstance()->getRenderer());
	}

}

void StateParser::parseObjects(tinyxml2::XMLElement * state,
										 std::vector<GameObject *> * objects){

	for ( tinyxml2::XMLElement * element = state->FirstChildElement();
			element != nullptr; element = element->NextSiblingElement() ) {

		int x, y, width, height, num_frames, callback_id, anim_speed;
		std::string texture_id;

		x = element->IntAttribute("x");
		y = element->IntAttribute("y");
		width = element->IntAttribute("width");
		height = element->IntAttribute("height");
		num_frames = element->IntAttribute("num_frames");
		callback_id = element->IntAttribute("callback_id");
		anim_speed = element->IntAttribute("anim_speed");

		texture_id = element->Attribute("texture_id");

		LoaderParams * params = new LoaderParams(x, y, width, height, texture_id,
															  num_frames, callback_id,
															  anim_speed);

		GameObject * object = GameObjectFactory::getInstance()->create(
												element->Attribute("type"));
		object->load(params);

		delete params;

		objects->push_back(object);
	}

}
