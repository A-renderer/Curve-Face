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
	
	vector<Point> face_vector =  matrixToPolygon(v_face,sizeof(v_face)/sizeof(*v_face));
	vector<Point> left_eyebrow_vector =  matrixToPolygon(v_left_eyebrow,sizeof(v_left_eyebrow)/sizeof(*v_left_eyebrow));
	vector<Point> right_eyebrow_vector =  matrixToPolygon(v_right_eyebrow,sizeof(v_right_eyebrow)/sizeof(*v_right_eyebrow));
	vector<Point> left_upper_eye_vector =  matrixToPolygon(v_left_upper_eye,sizeof(v_left_upper_eye)/sizeof(*v_left_upper_eye));
	vector<Point> right_upper_eye_vector =  matrixToPolygon(v_right_upper_eye,sizeof(v_right_upper_eye)/sizeof(*v_right_upper_eye));
	vector<Point> left_lower_eye_vector =  matrixToPolygon(v_left_lower_eye,sizeof(v_left_lower_eye)/sizeof(*v_left_lower_eye));
	vector<Point> right_lower_eye_vector =  matrixToPolygon(v_right_lower_eye,sizeof(v_right_lower_eye)/sizeof(*v_right_lower_eye));
	vector<Point> noseVector = matrixToPolygon(nose, sizeof(nose)/sizeof(*nose));
	vector<Point> upperLipVector = matrixToPolygon(upper_lip, sizeof(upper_lip)/sizeof(*upper_lip));
	vector<Point> bottomLipVector = matrixToPolygon(bottom_lip, sizeof(bottom_lip)/sizeof(*bottom_lip));

	system("clear");

	Curve face(face_vector,0.05);
	Curve left_eyebrow(left_eyebrow_vector,0.05);
	Curve right_eyebrow(right_eyebrow_vector,0.05);
	Curve left_upper_eye(left_upper_eye_vector,0.05);
	Curve right_upper_eye(right_upper_eye_vector,0.05);
	Curve left_lower_eye(left_lower_eye_vector,0.05);
	Curve right_lower_eye(right_lower_eye_vector,0.05);
	Curve noseCurve(noseVector, 0.05);
	Curve upperLipCurve(upperLipVector, 0.05);
	Curve bottomLipCurve(bottomLipVector, 0.05);


	FB.drawCurve(face, 255, 255, 255, 0);
	FB.drawCurveLine(face, 255, 255, 0, 0);
	FB.drawCurve(left_eyebrow, 255, 255, 255, 0);
	FB.drawCurve(right_eyebrow, 255, 255, 255, 0);
	FB.drawCurve(left_upper_eye, 255, 255, 255, 0);
	FB.drawCurve(right_upper_eye, 255, 255, 255, 0);
	FB.drawCurve(left_lower_eye, 255, 255, 255, 0);
	FB.drawCurve(right_lower_eye, 255, 255, 255, 0);
	FB.drawCircle({345,248},9,255, 255, 255, 0);
	FB.drawCircle({455,248},9,255, 255, 255, 0);
	FB.drawCurve(noseCurve, 255, 255, 255, 0);
	FB.drawCurve(bottomLipCurve, 255, 255, 255, 0);
	FB.drawCurve(upperLipCurve, 255, 255, 255, 0);
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
