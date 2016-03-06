#include "FrameBuffer.cpp"
#include <cstring>
#include <termios.h>
#include <fstream>
#include "assets.h"
#include "Face.h"

using namespace std;

FrameBuffer FB;
bool quit = false;
int key;

int kbhit(void);
vector<Point> matrixToPolygon(int object[][2], int col);
void colorFace();

int main() {
	
	// --------------INIT-------------- //
	vector<Point> face_vector =  matrixToPolygon(v_face,sizeof(v_face)/sizeof(*v_face));
	vector<Point> left_eyebrow_vector =  matrixToPolygon(v_left_eyebrow,sizeof(v_left_eyebrow)/sizeof(*v_left_eyebrow));
	vector<Point> right_eyebrow_vector =  matrixToPolygon(v_right_eyebrow,sizeof(v_right_eyebrow)/sizeof(*v_right_eyebrow));
	vector<Point> left_upper_eye_vector =  matrixToPolygon(v_left_upper_eye,sizeof(v_left_upper_eye)/sizeof(*v_left_upper_eye));
	vector<Point> right_upper_eye_vector =  matrixToPolygon(v_right_upper_eye,sizeof(v_right_upper_eye)/sizeof(*v_right_upper_eye));
	vector<Point> left_lower_eye_vector =  matrixToPolygon(v_left_lower_eye,sizeof(v_left_lower_eye)/sizeof(*v_left_lower_eye));
	vector<Point> right_lower_eye_vector =  matrixToPolygon(v_right_lower_eye,sizeof(v_right_lower_eye)/sizeof(*v_right_lower_eye));
	vector<Point> nose_vector = matrixToPolygon(nose, sizeof(nose)/sizeof(*nose));
	vector<Point> upperLipVector = matrixToPolygon(upper_lip, sizeof(upper_lip)/sizeof(*upper_lip));
	vector<Point> bottomLipVector = matrixToPolygon(bottom_lip, sizeof(bottom_lip)/sizeof(*bottom_lip));
	vector<Point> eyeTagVector = matrixToPolygon(eye_tag, sizeof(eye_tag)/sizeof(*eye_tag));
	vector<Point> lipTagVector = matrixToPolygon(lip_tag, sizeof(lip_tag)/sizeof(*lip_tag));
	vector<Point> mouthTagVector = matrixToPolygon(mouth_tag, sizeof(mouth_tag)/sizeof(*mouth_tag));

	map<string, vector<Point> > faceMap;
	
	faceMap.insert(std::pair<std::string, vector<Point> >("head",face_vector));
	faceMap.insert(std::pair<std::string, vector<Point> >("nose",nose_vector));
	faceMap.insert(std::pair<std::string, vector<Point> >("right_eyebrow",right_eyebrow_vector));
	faceMap.insert(std::pair<std::string, vector<Point> >("left_eyebrow",left_eyebrow_vector));
	faceMap.insert(std::pair<std::string, vector<Point> >("right_upper_eyelid",right_upper_eye_vector));
	faceMap.insert(std::pair<std::string, vector<Point> >("right_lower_eyelid",right_lower_eye_vector));
	faceMap.insert(std::pair<std::string, vector<Point> >("left_upper_eyelid",left_upper_eye_vector));
	faceMap.insert(std::pair<std::string, vector<Point> >("left_lower_eyelid",left_lower_eye_vector));
	faceMap.insert(std::pair<std::string, vector<Point> >("upper_lip",upperLipVector));
	faceMap.insert(std::pair<std::string, vector<Point> >("lower_lip",bottomLipVector));
	faceMap.insert(std::pair<std::string, vector<Point> >("lip_tag",lipTagVector));
	faceMap.insert(std::pair<std::string, vector<Point> >("laugh_tag",mouthTagVector));
	faceMap.insert(std::pair<std::string, vector<Point> >("eye_tag",eyeTagVector));
	

	printf("masuk sini sebelum?\n");
	// Face myFace(faceMap); // >>>>> NGEBUG COOOY <<<<< //
	printf("masuk sini sesudah?\n");

	// --------------END OF INIT-------------- //

	system("clear");
	FB.clearscreen();


	while(!quit){
		if(kbhit()){
			key=getchar();
			FB.cleararea(250,90,550,400);
			//PANGGIL FUNGSI UNTUK REDRAW MOVEMENT
			if(key=='a' || key=='A') {
				// SMILE
				// myFace.smile(1);
				
				FB.drawCircle(Point(345,248),9,255, 255, 255, 0);
				FB.drawCircle(Point(455,248),9,255, 255, 255, 0);
			}
			else if(key=='s' || key=='S') {
				// LAUGH
				// myFace.laugh(1);

				FB.drawCircle(Point(345,248),9,255, 255, 255, 0);
				FB.drawCircle(Point(455,248),9,255, 255, 255, 0);
			}
			else if(key=='d' || key=='D') {
				// CRY
				// myFace.cry(1,1);

				FB.drawCircle(Point(345,248),9,255, 255, 255, 0);
				FB.drawCircle(Point(455,248),9,255, 255, 255, 0);
			}
			else if(key=='f' || key=='F') {
				// MEREM
				// myFace.eyesClosed();
			}
			else if(key=='q') {
				quit = true;
			}
			else {
				FB.drawCircle(Point(345,248),9,255, 255, 255, 0);
				FB.drawCircle(Point(455,248),9,255, 255, 255, 0);
			}
			Curve face(face_vector,0.05);
			Curve left_eyebrow(left_eyebrow_vector,0.05);
			Curve right_eyebrow(right_eyebrow_vector,0.05);
			Curve left_upper_eye(left_upper_eye_vector,0.05);
			Curve right_upper_eye(right_upper_eye_vector,0.05);
			Curve left_lower_eye(left_lower_eye_vector,0.05);
			Curve right_lower_eye(right_lower_eye_vector,0.05);
			Curve noseCurve(nose_vector, 0.05);
			Curve upperLipCurve(upperLipVector, 0.05);
			Curve bottomLipCurve(bottomLipVector, 0.05);
			
			FB.drawCurve(face, 255, 255, 255, 0);
			FB.drawCurve(left_eyebrow, 0, 0, 0, 0);
			FB.drawCurve(right_eyebrow, 0, 0, 0, 0);
			FB.drawCurve(left_upper_eye, 0, 0, 0, 0);
			FB.drawCurve(right_upper_eye, 0, 0, 0, 0);
			FB.drawCurve(left_lower_eye, 0, 0, 0, 0);
			FB.drawCurve(right_lower_eye, 0, 0, 0, 0);
			FB.drawCurve(noseCurve, 0, 0, 0, 0);
			FB.drawCurve(bottomLipCurve, 128, 0, 0, 0);
			FB.drawCurve(upperLipCurve, 128, 0, 0, 0);

			colorFace();
			
		}

	}

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

void colorFace() {
	FB.floodFill(400,250,135,206,235,255,222,173);

	FB.floodFill(330,250,135,206,235,255,255,255);
	FB.floodFill(342,250,135,206,235,0,0,0);
	FB.floodFill(355,250,135,206,235,255,255,255);
	
	FB.floodFill(438,250,135,206,235,255,255,255);
	FB.floodFill(450,250,135,206,235,0,0,0);
	FB.floodFill(466,250,135,206,235,255,255,255);
}