#include "Curve.h"


Curve::Curve(){

}

Curve::Curve(vector<Point> p, float d){
	float t=0;

	for (int i = 0; i<p.size(); i++){
		points.push_back(p.at(i));
	}

	pFinal.x = points.at(0).x;
	pFinal.y = points.at(0).y;

	finals.push_back(pFinal);

	while (t<1){
		pFinal = quadraticBezier(t);
		finals.push_back(pFinal);
		t+=d;
	}

	finals.push_back(points.at(points.size()-1));
}

Curve::~Curve(){
	points.clear();
	finals.clear();
}

Point Curve::quadraticBezier(float t){ 
	// Buat quadratic curve p0: source; p1: control; p2: destination
	// Masih nggak ngerti caranya kalo curvenya lebih dr quadratic
	Point p;
	p.x = (int) (pow (1-t,2) * points.at(0).x + (1-t) * 2 * t * points.at(1).x + t * t * points.at(2).x);
	p.y = (int) (pow (1-t,2) * points.at(0).y + (1-t) * 2 * t * points.at(1).y + t * t * points.at(2).y);
	return p;
}