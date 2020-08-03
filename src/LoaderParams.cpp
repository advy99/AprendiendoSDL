#include "LoaderParams.h"

LoaderParams::LoaderParams(const int X, const int Y,
									const int WIDTH, const int HEIGHT,
									const std::string id)
									:x_pos(X), y_pos(Y), width(WIDTH), height(HEIGHT),
									 texture_id(id){

}

int LoaderParams::getX() const{
	return x_pos;
}

int LoaderParams::getY() const{
	return y_pos;
}


int LoaderParams::getWidth() const{
	return width;
}


int LoaderParams::getHeight() const{
	return height;
}


std::string LoaderParams::getTextureId() const{
	return texture_id;
}
