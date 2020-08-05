#ifndef INPUTHANDLER_H_INCLUDED
#define INPUTHANDLER_H_INCLUDED

#include <vector>
#include "Vector2D.h"
#include <SDL2/SDL.h>

class InputHandler {
	private:
		bool joysticks_initialised;
		std::vector<SDL_Joystick *> joysticks;
		std::vector<std::pair<Vector2D *, Vector2D *> > joystick_values;
		std::vector<std::vector<bool> > button_states;


		InputHandler();
		~InputHandler();

		static InputHandler * instance;

		const int joystick_dead_zone = 10000;

	public:
		static InputHandler * getInstance();
		void update();
		void clean();

		void initialiseJoysticks();
		bool joysticksInitialised() const;

		int xValue(const int joy, const int stick) const;
		int yValue(const int joy, const int stick) const;
		bool getButtonState(const int joy, const int button_number) const;

};



#endif
