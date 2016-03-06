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
	temp = polygons.find("nose")->second;
	nose = Polygon(temp);
	face.push_back(nose);
	normal_exp.push_back(nose);

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
	temp = polygons.find("upper_lip")->second;
	lips.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));

	temp.clear();
	temp = polygons.find("lower_lip")->second;
	lips.push_back(Polygon(temp));
	face.push_back(Polygon(temp));
	normal_exp.push_back(Polygon(temp));

	temp.clear();
	temp = polygons.find("lip_tag")->second;
	//tags.insert(std::pair<std::string, vector<Point>("lipTag", temp));

	temp.clear();
	temp = polygons.find("eye_tag")->second;
	//tags.insert(std::pair<std::string, vector<Point>("eyeTag", temp));
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

void Face::moveHead(string dir, float d) {
	if (dir.compare("up")==0) {
		head.moveUp(d);
	} else if (dir.compare("down")==0) {
		head.moveDown(d);
	} else if (dir.compare("right")==0) {
		head.moveRight(d);
	} else if (dir.compare("left")==0) {
		head.moveLeft(d);
	}
}

void Face::moveNose(string dir, float d) {
	if (dir.compare("up")==0) {
		nose.moveUp(d);
	} else if (dir.compare("down")==0) {
		nose.moveDown(d);
	} else if (dir.compare("right")==0) {
		nose.moveRight(d);
	} else if (dir.compare("left")==0) {
		nose.moveLeft(d);
	}
}

void Face::smile() {
	face.clear();

	face.push_back(normal_exp.at(0));
	face.push_back(normal_exp.at(1));
	face.push_back(normal_exp.at(2));
	face.push_back(normal_exp.at(3));
	face.push_back(normal_exp.at(4));
	face.push_back(normal_exp.at(5));
	face.push_back(normal_exp.at(6));
	face.push_back(normal_exp.at(7));


	vector<Point> temp;
	//temp = polygons.find("lipTag")->second;
	for (int i=0; i<temp.size(); i++) {
		//for (int i)
	}
}

void Face::laugh() {
	face.clear();

	face.push_back(normal_exp.at(0));
	face.push_back(normal_exp.at(1));
	face.push_back(normal_exp.at(2));
	face.push_back(normal_exp.at(3));
	face.push_back(normal_exp.at(4));
	face.push_back(normal_exp.at(5));
	face.push_back(normal_exp.at(6));
	face.push_back(normal_exp.at(7));

	//yang berubah mulutnya	
}

void Face::cry() {
	face.clear();

	face.push_back(normal_exp.at(0));
	face.push_back(normal_exp.at(1));
	face.push_back(normal_exp.at(2));
	face.push_back(normal_exp.at(3));

	//yang berubah mulut dan mata; eyeball diilangin
}

void Face::eyesClosed() {
	face.clear();

	face.push_back(normal_exp.at(0));
	face.push_back(normal_exp.at(1));
	face.push_back(normal_exp.at(2));
	face.push_back(normal_exp.at(3));
	face.push_back(normal_exp.at(8));
	face.push_back(normal_exp.at(9));

	//yang berubah matanya; eyeball diilangin
}