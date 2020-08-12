#ifndef MAINMENUSTATE_H_INCLUDED
#define MAINMENUSTATE_H_INCLUDED

#include "MenuState.h"
#include "GameObject.h"
#include <vector>

class MainMenuState : public MenuState {
	private:
		static const std::string menu_id;

		std::vector<GameObject *> menu_objects;

		static void menuToPlay();
		static void exitFromMenu();

		virtual bool onExit();

		virtual void setCallbacks(const std::vector<Callback> & callbacks);

	public:
		virtual ~MainMenuState();
		virtual void update();
		virtual void render();

		virtual bool onEnter();

		virtual std::string getStateID() const;

};


#endif
