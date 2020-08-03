#include "Enemy.h"



void Enemy::load(const int X, const int Y, const int WIDTH, const int HEIGHT,
						const std::string id){
	GameObject::load(X, Y, WIDTH, HEIGHT, id);
}

void Enemy::draw(SDL_Renderer * g_renderer){
	GameObject::draw(g_renderer);
}

void Enemy::update() {
	x_pos += 1;
	y_pos += 1;
	current_frame = int( (SDL_GetTicks() / 100) % 6 );
}

void Enemy::clean(){

}
