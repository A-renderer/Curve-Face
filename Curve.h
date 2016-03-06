#ifndef CURVE
#define CURVE

#include "Point.h"
#include "Line.h"

using namespace std;

class Curve {
	public:
		Curve();
		Curve(Line, t);
		Curve(const Curve& c);
		Curve& operator=(const Curve& c);
		~Curve();

		Line line;
		int t;
		
};

#endif