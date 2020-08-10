#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include <string>

class GameState {
	protected:

		bool exiting;
		virtual bool onExit() = 0;

	public:
		virtual ~GameState() {};
		virtual void update() = 0;
		virtual void render() = 0;

		virtual bool onEnter() = 0;

		virtual std::string getStateID() const = 0;

};


#endif
