#ifndef CURVE
#define CURVE

#include "Point.h"
#include "Line.h"
#include <math.h>

using namespace std;

class Curve {
	public:
		Curve();
		Curve(vector<Point> points, float d);
		Curve(const Curve& c);
		Curve& operator=(const Curve& c);
		~Curve();

		void quadraticBezier(float t)

		vector<Point> points;
		vector<Point> finals;
		Point pFinal;
		float d;
		
};

#endif