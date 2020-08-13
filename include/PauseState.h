#ifndef PAUSESTATE_H_INCLUDED
#define PAUSESTATE_H_INCLUDED

#include "MenuState.h"
#include "GameObject.h"
#include <vector>

class PauseState : public MenuState {
	private:
		static void pauseToMain();
		static void resumePlay();

		static const std::string pause_id;


		virtual bool onExit();
		virtual void setCallbacks(const std::vector<Callback> & callbacks);

	public:
		virtual ~PauseState();

		virtual void update();
		virtual void render();

		virtual bool onEnter();

		virtual std::string getStateID() const;


};


#endif
