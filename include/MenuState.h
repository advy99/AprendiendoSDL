#ifndef MENUSTATE_H_INCLUDED
#define MENUSTATE_H_INCLUDED

#include "GameState.h"
#include "GameObject.h"
#include <vector>

class MenuState : public GameState {
	private:
		static const std::string menu_id;

		std::vector<GameObject *> menu_objects;

		static void menuToPlay();
		static void exitFromMenu();

		virtual bool onExit();

	public:
		virtual ~MenuState();
		virtual void update();
		virtual void render();

		virtual bool onEnter();

		virtual std::string getStateID() const;

};


#endif
