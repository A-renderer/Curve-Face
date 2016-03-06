#ifndef FACE
#define FACE

#include "Point.h"
#include "Polygon.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class Face {
	public:
		//head 0, nose 1, upper lip 2
		Polygon head;
		Polygon nose;
		vector<Polygon> face;
		vector<Polygon> lips;
		vector<Polygon> eyebrows;
		vector<Polygon> eyes;
		vector<Polygon> eyeballs;
		vector<Polygon> normal_exp;

		Face();
		Face(map<string, vector<Point> > polygons);
		Face(const Face& f);
		Face& operator=(const Face& f);
		
		void moveHead(string dir, float d);
		void moveNose(string dir, float d);
		void smile();
		void laugh();
		void cry();
		void eyesClosed();
};

#endif