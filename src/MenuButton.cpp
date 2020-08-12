#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams * params, void (*func)())
							  :SDLGameObject(), callback(func){
	SDLGameObject::load(params);
	current_frame = MOUSE_OUT;
	button_released = true;
}


void MenuButton::draw() {
	SDLGameObject::draw();
}


void MenuButton::update() {
	Vector2D * mouse_position = InputHandler::getInstance()->getMousePosition();


	if ( mouse_position->getX() < position.getX() + width &&
		  mouse_position->getX() > position.getX() &&
		  mouse_position->getY() < position.getY() + height &&
		  mouse_position->getY() > position.getY()) {


		if ( InputHandler::getInstance()->getMouseButtonState(LEFT) &&
			  button_released) {
			current_frame = CLICKED;

			callback();

			button_released = false;
		} else if ( !InputHandler::getInstance()->getMouseButtonState(LEFT) ) {
			button_released = true;
			current_frame = MOUSE_OVER;
		}




	} else {
		current_frame = MOUSE_OUT;
	}

}

void MenuButton::clean() {
	SDLGameObject::clean();
}

void MenuButton::load(const LoaderParams * params) {
	SDLGameObject::load(params);
	callback_id = params->getCallbackID();
	current_frame = MOUSE_OUT;
}

void MenuButton::setCallback( void (*func)()  ) {
	callback = func;
}

int MenuButton::getCallbackID() const {
	return callback_id;
}
