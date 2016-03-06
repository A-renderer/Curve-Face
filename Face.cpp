#include "Face.h"

Face::Face() {

}

Face::Face(map<string, vector<Point> > polygons) {
	vector<Point> temp;
	temp = polygons.find("head")->second;
	head = Polygon(temp);
	face.push_back(head);
	normal_exp.push_back(head);

	temp.clear();
	temp = polygons.find("right_eyebrow")->second;
	eyebrows.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));

	temp.clear();
	temp = polygons.find("left_eyebrow")->second;
	eyebrows.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));

	temp.clear();
	temp = polygons.find("right_eye")->second;
	eyes.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));

	temp.clear();
	temp = polygons.find("left_eye")->second;
	eyes.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));

	temp.clear();
	temp = polygons.find("right_eyeball")->second;
	eyeballs.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));

	temp.clear();
	temp = polygons.find("left_eyeball")->second;
	eyeballs.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));

	temp.clear();
	temp = polygons.find("nose")->second;
	nose = Polygon(temp);
	face.push_back(nose);
	normal_exp.push_back(nose);

	temp.clear();
	temp = polygons.find("upper_lip")->second;
	lips.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));

	temp.clear();
	temp = polygons.find("lower_lip")->second;
	lips.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));	
}

Face::Face(const Face& f) {
	this->head = f.head;
	this->nose = f.nose;
	this->face = f.face;
	this->lips = f.lips;
    this->eyes = f.eyes;
    this->eyebrows = f.eyebrows;
    this->eyeballs = f.eyeballs;
}

Face& Face::operator=(const Face& f) {
	this->head = f.head;
	this->nose = f.nose;
	this->face = f.face;
	this->lips = f.lips;
    this->eyes = f.eyes;
    this->eyebrows = f.eyebrows;
    this->eyeballs = f.eyeballs;

    return *this;
}