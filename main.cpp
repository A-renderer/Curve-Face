#include "FrameBuffer.cpp"
#include <cstring>
#include <termios.h>
#include <fstream>
#include "assets.h"

using namespace std;

FrameBuffer FB;
bool quit = false;
int key;

int kbhit(void);
vector<Point> matrixToPolygon(int object[][2], int col);
void move(int key);


int main() {
	/*Point pa(10,200);
	Point pb(200, 500);
	Point pc(400, 10);
	Point pd(600, 510);
	Point pe(800, 200);

	vector<Point> p;
	p.push_back(pa);
	p.push_back(pb);
	p.push_back(pc);
	p.push_back(pd);
	p.push_back(pe);*/

	vector<Point> faceVector = matrixToPolygon(face, sizeof(face)/sizeof(*face));
	vector<Point> noseVector = matrixToPolygon(nose, sizeof(nose)/sizeof(*nose));
	vector<Point> upperLipVector = matrixToPolygon(upper_lip, sizeof(upper_lip)/sizeof(*upper_lip));
	vector<Point> bottomLipVector = matrixToPolygon(bottom_lip, sizeof(bottom_lip)/sizeof(*bottom_lip));

	system("clear");

	/*Curve c(p,0.05);*/
	Curve faceCurve(faceVector, 0.05);
	Curve noseCurve(noseVector, 0.05);
	Curve upperLipCurve(upperLipVector, 0.05);
	Curve bottomLipCurve(bottomLipVector, 0.05);

	FB.clearscreen();

	/*FB.drawCurve(c, 255, 255, 255, 0);
	FB.drawCurveLine(c, 255, 255, 0, 0);*/
	FB.drawCurve(faceCurve, 255, 255, 255, 0);
	FB.drawCurve(noseCurve, 255, 255, 255, 0);
	FB.drawCurve(bottomLipCurve, 255, 255, 255, 0);
	FB.drawCurve(upperLipCurve, 255, 255, 255, 0);
   
	FB.floodFill(400,250,135,206,235,255,222,173);
	/*
	while(!quit){
		if(kbhit()){
			key=getchar();
			FB.cleararea(250,90,550,400);
			//PANGGIL FUNGSI UNTUK REDRAW MOVEMENT
			if(key=='a' || key=='A') {
				// SMILE
			}
			else if(key=='s' || key=='S') {
				// SAD
			}
			else if(key=='d' || key=='D') {
				// MEREM
			}
			else if(key=='q') {
				quit = true;
			}
			
			FB.drawCurve(faceCurve, 255, 255, 255, 0);
			FB.drawCurve(noseCurve, 255, 255, 255, 0);
			FB.drawCurve(bottomLipCurve, 255, 255, 255, 0);
			FB.drawCurve(upperLipCurve, 255, 255, 255, 0);
			
		}

	}*/

	return 0;
}

int kbhit(void) {
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF) {
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

vector<Point> matrixToPolygon(int object[][2], int col) {
	vector<Point> points;
	points.clear();
	for(int i=0;i<col;i++) {
		points.push_back(Point(object[i][0],object[i][1]));
	}
	return points;
}