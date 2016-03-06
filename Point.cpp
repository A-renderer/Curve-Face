#include "Point.h"

Point::Point() { // CTOR
	x=0;
	y=0;
}

Point::Point(int x, int y) { //CTOR PARAM
	this->x=x;
	this->y=y;
}

Point::Point(const Point& p) { // CCTOR
	x=p.x;
	y=p.y;
}

Point& Point::operator=(const Point& p) { // OPERATOR=
	x=p.x;
	y=p.y;

	return *this;
}

Point::~Point() { // DTOR

}

void Point::moveUp(float dy) {
	y-=dy;
}

void Point::moveDown(float dy) {
	y+=dy;	
}

void Point::moveLeft(float dx) {
	x-=dx;
}

void Point::moveRight(float dx) {
	x+=dx;		
}