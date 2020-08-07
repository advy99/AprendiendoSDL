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

	public:
		MenuButton(const LoaderParams * params);

		virtual void draw();
		virtual void update();
		virtual void clean();

};


#endif
