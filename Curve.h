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
		~Curve();

		vector<Point> points;
		vector<Point> finals;
		Point pFinal;
		float d;

	private:
		Point quadraticBezier(float t);
		Point cubicBezier(float t);
		Point fourBezier(float t);
		Point bezierCurve(float t);
		vector<int> pascalTriangle(int n);
		
};

#endif