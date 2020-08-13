#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include <string>
#include <vector>
#include "GameObject.h"

class GameState {
	protected:

		virtual bool onExit();
		std::vector<std::string> texture_id_list;
		std::vector<GameObject *> objects;

	public:
		virtual ~GameState() {};
		virtual void update() = 0;
		virtual void render() = 0;

		virtual bool onEnter() = 0;

		virtual std::string getStateID() const = 0;

};


#endif
