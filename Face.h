#ifndef FACE
#define FACE

#include "Point.h"
#include "Eyes.h"
#include "LowerHead.h"
#include "Shape.h"
#include <vector>
#include <map>
using namespace std;

class Face {
	public:
		//head 0, nose 1, upper lip 2
		vector<Polygon> face;
		vector<Polygon> eyebrows;
		vector<Polygon> eyes;
		vector<Polygon> eyeballs;
		vector<Polygon> normal_exp;
		LowerHead lowerHead;

		float scale(Polygon pol);

		Face();
		Face(vector<Polygon> points, int a, int b, int c, float s);
		Face& operator=(const Face& f);
};

#endif