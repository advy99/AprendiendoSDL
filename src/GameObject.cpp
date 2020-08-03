#include "GameObject.h"


void GameObject::load(const int X, const int Y, const int WIDTH, const int HEIGHT,
							 const std::string id){
	x_pos         = X;
	y_pos         = Y;
	width         = WIDTH;
	height        = HEIGHT;
	texture_id    = id;
	current_frame = 1;
	current_row   = 1;
}


void GameObject::draw(SDL_Renderer * g_renderer){
	TextureManager::getInstance().drawFrame(texture_id, x_pos, y_pos,
														  width, height,
														  current_row, current_frame,
														  g_renderer);
}

void GameObject::update(){
	x_pos += 1;
}

void GameObject::clean(){

}
