#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D() {
	x = 0;
	y = 0;
}

Vector2D::Vector2D(const int X, const int Y):x(X), y(Y){

}

double Vector2D::length() const {
	return sqrt(x*x + y*y);
}

int Vector2D::getX() const {
	return x;
}

int Vector2D::getY() const {
	return y;
}

void Vector2D::setX(const int new_x){
	x = new_x;
}


void Vector2D::setY(const int new_y){
	y = new_y;
}

Vector2D Vector2D::operator+ (const Vector2D & other) const{
	Vector2D result(this->x + other.x, this->y + other.y);

	return result;
}

Vector2D & Vector2D::operator+= (const Vector2D & other){
	(*this) = (*this) + other;

	return (*this);
}


Vector2D Vector2D::operator - (const Vector2D & other) const{
	Vector2D result(this->x - other.x, this->y - other.y);

	return result;
}

Vector2D & Vector2D::operator -= (const Vector2D & other){
	(*this) = (*this) - other;

	return (*this);
}



Vector2D Vector2D::operator / (const double scalar) const {
	Vector2D result(this->x / scalar, this->y / scalar);

	return result;
}

Vector2D & Vector2D::operator /= (const double scalar){
	(*this) = (*this) / scalar;

	return (*this);
}


Vector2D operator * (const Vector2D & vector, const double scalar){
	Vector2D result(vector.x * scalar, vector.y * scalar);

	return result;
}

Vector2D operator * (const double scalar, const Vector2D & vector){
	return (vector * scalar);
}

Vector2D & Vector2D::operator *= (const double scalar){
	(*this) = (*this) * scalar;

	return (*this);
}


void Vector2D::normalize(){
	double len = length();

	if (len > 0){
		(*this) /= len;
	}
}
