#ifndef MENUBUTTON_H_INCLUDED
#define MENUBUTTON_H_INCLUDED

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class MenuButton : public SDLGameObject {
	private:
		enum button_state{
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};

		void (*callback) ();
		int callback_id;

		bool button_released;

	public:
		MenuButton();

		virtual void draw();
		virtual void update();
		virtual void clean();
		virtual void load(const LoaderParams * params);

		void setCallback( void (*func)()  );
		int getCallbackID() const;

};


class MenuButtonCreator : public BaseCreator {

	public:
		GameObject * createGameObject() const;

};

#endif
