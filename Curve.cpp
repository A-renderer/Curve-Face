#include "Curve.h"


Curve::Curve(){

}

Curve::Curve(vector<Point> points, float d);{
	float t=0;
	pFinal.x = points.at(0).x;
	pFinal.y = points.at(0).y;
	finals.push_back(pFinal);

	while (t<1){
		quadraticBezier(t);
		t+=d;
		finals.push_back(pFinal);
	}
}

Curve::Curve(const Curve& c){

}

Curve::Curve& operator=(const Curve& c){

}

Curve::~Curve(){
	points.clear();
	finals.clear();
}

void Curve::quadraticBezier(float t){ 
	// Buat quadratic curve p0: source; p1: control; p2: destination
	// Masih nggak ngerti caranya kalo curvenya lebih dr quadratic
	pFinal.x = pow (1-t,2) * points.at(0).x +
				(1-t) * 2 * t * points.at(1).x +
				t * t * points.at(2).x;
	pFinal.y = pow (1-t,2) * points.at(0).y +
				(1-t) * 2 * t * points.at(1).y +
				t * t * points.at(2).y;
}