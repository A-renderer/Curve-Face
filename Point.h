#ifndef POINT_H
#define POINT_H

#include "header.h"

class Point {
public:
	Point();

	Point(int x, int y);

	Point(const Point& p);

	Point& operator=(const Point& p);

	~Point();

	void moveUp(float dy);

	void moveDown(float dy);

	void moveLeft(float dx);

	void moveRight(float dx);

	int x;
	int y;

private:

};

#endif
