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
	Point pa(200, 10);
	Point pb(0, 100);
	Point pc(200, 400);
	Point pd(400, 100);
	Point pe(200, 10);

	vector<Point> p;
	p.push_back(pa);
	p.push_back(pb);
	p.push_back(pc);
	p.push_back(pd);
	p.push_back(pe);

	system("clear");

	Curve c(p,0.05);

	FB.drawCurve(c, 255, 255, 255, 0);
	FB.drawCurveLine(c, 255, 255, 0, 0);

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

void move(int key) {
	/*int i = 0;
	if(key=='w'){
		while(i < 10 && window.square.getMinY() > 0) {
			window.moveUp(1);
			i++;
		}
	}
	else if(key=='a'){
		while(i < 10 && window.square.getMinX() > 0) {
			window.moveLeft(1);
			i++;
		}
	}
	else if(key=='d'){
		while(i < 10 && window.square.getMaxX() < 599) {
			window.moveRight(1);
			i++;
		}
	}
	else if(key=='s'){
		while(i < 10 && window.square.getMaxY() < 400) {
			window.moveDown(1);
			i++;
		}
	}
	else if(key=='q') {
		// OTHER KEYS
		quit=true;
		system("clear");
	}

	if (key=='a' || key=='s' || key=='d' || key=='w'){
		//menggambar ulang peta
		drawMap();

		//menggambar ulang window & view
		FB.cleararea(view.P1.x,view.P1.y,view.P2.x,view.P2.y);
	}*/
}