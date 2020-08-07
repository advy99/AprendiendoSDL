#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams * params)
							  :SDLGameObject(params){
	current_frame = MOUSE_OUT;
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
		current_frame = MOUSE_OVER;

		if ( InputHandler::getInstance()->getMouseButtonState(LEFT) ) {
			current_frame = CLICKED;
		}
	} else {
		current_frame = MOUSE_OUT;
	}

}

void MenuButton::clean() {
	SDLGameObject::clean();
}
