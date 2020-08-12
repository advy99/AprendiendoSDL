#ifndef STATEPARSER_H_INCLUDED
#define STATEPARSER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "GameObject.h"
#include "tinyxml2.h"

class StateParser {
	private:
		bool parseState(const char * state_file, const std::string state_id,
							 std::vector<GameObject *> * objects,
							 std::vector<std::string> * texture_ids);

	public:
		void parseObjects(tinyxml2::XMLElement * state,
								std::vector<GameObject *> *objects);
		void parseTextures(tinyxml2::XMLElement * state,
								 std::vector<std::string> * texture_ids);


};



#endif
