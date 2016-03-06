#ifndef FACE
#define FACE

#include "Point.h"
#include "Polygon.h"
#include <vector>
#include <map>
using namespace std;

class Face {
	public:
		//head 0, nose 1, upper lip 2
		vector<Point> face;
		vector<Point> Nose;
		vector<Polygon> lips;
		vector<Polygon> eyebrows;
		vector<Polygon> eyes;
		vector<Polygon> eyeballs;
		vector<Polygon> normal_exp;
		LowerHead lowerHead;

		Face();
		Face(map polygons, int a, int b, int c, float s);
		Face& operator=(const Face& f);
		float scale(Polygon pol);
};

#endif