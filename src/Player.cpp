#include "Player.h"



void Player::load(const int X, const int Y, const int WIDTH, const int HEIGHT,
						const std::string id){
	GameObject::load(X, Y, WIDTH, HEIGHT, id);
}

void Player::draw(SDL_Renderer * g_renderer){
	GameObject::draw(g_renderer);
}

void Player::update() {
	x_pos -= 1;
}

void Player::clean(){

}
