#ifndef INPUTHANDLER_H_INCLUDED
#define INPUTHANDLER_H_INCLUDED

#include <vector>
#include <SDL2/SDL.h>

class InputHandler {
	private:
		bool joysticks_initialised;
		std::vector<SDL_Joystick *> joysticks;


		InputHandler();
		~InputHandler();

		static InputHandler * instance;

	public:
		static InputHandler * getInstance();
		void update();
		void clean();

		void initialiseJoysticks();
		bool joysticksInitialised() const;

};



#endif
