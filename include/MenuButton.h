#ifndef MENUBUTTON_H_INCLUDED
#define MENUBUTTON_H_INCLUDED

#include "SDLGameObject.h"

class MenuButton : public SDLGameObject {
	private:
		enum button_state{
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};

		void (*callback) ();

		bool button_released;

	public:
		MenuButton(const LoaderParams * params, void (*func)());

		virtual void draw();
		virtual void update();
		virtual void clean();

};


#endif