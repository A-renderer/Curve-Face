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
	vector<Point> hair_vector =  matrixToPolygon(v_hair,sizeof(v_hair)/sizeof(*v_hair));
	vector<Point> eyeTagVector = matrixToPolygon(eye_tag, sizeof(eye_tag)/sizeof(*eye_tag));
	vector<Point> lipTagVector = matrixToPolygon(lip_tag, sizeof(lip_tag)/sizeof(*lip_tag));
	vector<Point> mouthTagVector = matrixToPolygon(mouth_tag, sizeof(mouth_tag)/sizeof(*mouth_tag));

	map<string, vector<Point> > faceMap;

	float d = 0.02;

	Curve face(face_vector,d);
	Curve left_eyebrow(left_eyebrow_vector,d);
	Curve right_eyebrow(right_eyebrow_vector,d);
	Curve left_upper_eye(left_upper_eye_vector,d);
	Curve right_upper_eye(right_upper_eye_vector,d);
	Curve left_lower_eye(left_lower_eye_vector,d);
	Curve right_lower_eye(right_lower_eye_vector,d);
	Curve noseCurve(nose_vector, d);
	Curve upperLipCurve(upperLipVector, d);
	Curve bottomLipCurve(bottomLipVector, d);
	Curve hairCurve(hair_vector,d);

	Face myFace;
	//0
	myFace.head = face;
	myFace.face.push_back(myFace.head);
	myFace.normal_exp.push_back(myFace.head);
	//1
	myFace.nose = noseCurve;
	myFace.face.push_back(myFace.nose);
	myFace.normal_exp.push_back(myFace.nose);
	//2
	myFace.eyebrows.push_back(right_eyebrow);
	myFace.face.push_back(myFace.eyebrows.at(0));
	myFace.normal_exp.push_back(myFace.eyebrows.at(0));
	//3
	myFace.eyebrows.push_back(left_eyebrow);
	myFace.face.push_back(myFace.eyebrows.at(1));
	myFace.normal_exp.push_back(myFace.eyebrows.at(1));
	//4
	myFace.eyes.push_back(right_upper_eye);
	myFace.face.push_back(myFace.eyes.at(0));
	myFace.normal_exp.push_back(myFace.eyes.at(0));
	//5
	myFace.eyes.push_back(right_lower_eye);
	myFace.face.push_back(myFace.eyes.at(1));
	myFace.normal_exp.push_back(myFace.eyes.at(1));
	//6
	myFace.eyes.push_back(left_upper_eye);
	myFace.face.push_back(myFace.eyes.at(2));
	myFace.normal_exp.push_back(myFace.eyes.at(2));
	//7
	myFace.eyes.push_back(left_lower_eye);
	myFace.face.push_back(myFace.eyes.at(3));
	myFace.normal_exp.push_back(myFace.eyes.at(3));
	//8
	myFace.lips.push_back(upperLipCurve);
	myFace.face.push_back(myFace.lips.at(0));
	myFace.normal_exp.push_back(myFace.lips.at(0));
	//9
	myFace.lips.push_back(bottomLipCurve);
	myFace.face.push_back(myFace.lips.at(1));
	myFace.normal_exp.push_back(myFace.lips.at(1));
	//10
	myFace.hair = hairCurve;
	myFace.face.push_back(myFace.hair);
	myFace.normal_exp.push_back(myFace.hair);

	myFace.tags.insert(std::pair<std::string, vector<Point> >("lipTag", lipTagVector));
	myFace.tags.insert(std::pair<std::string, vector<Point> >("laughTag", mouthTagVector));
	myFace.tags.insert(std::pair<std::string, vector<Point> >("eyeTag", eyeTagVector));
	

	// --------------END OF INIT-------------- //

	system("clear");
	FB.clearscreen();


	while(!quit){
		if(kbhit()){
			key=getchar();
			FB.cleararea(200,90,600,500);
			//PANGGIL FUNGSI UNTUK REDRAW MOVEMENT
			if(key=='a' || key=='A') {
				// SMILE
				myFace.smile(10);
				
				FB.drawCircle(Point(345,248),9,255, 255, 255, 0);
				FB.drawCircle(Point(455,248),9,255, 255, 255, 0);
			}
			else if(key=='s' || key=='S') {
				// LAUGH
				myFace.laugh(20);

				FB.drawCircle(Point(345,248),9,255, 255, 255, 0);
				FB.drawCircle(Point(455,248),9,255, 255, 255, 0);
			}
			else if(key=='d' || key=='D') {
				// CRY
				myFace.cry(10,25);

				FB.drawCircle(Point(345,252),9,255, 255, 255, 0);
				FB.drawCircle(Point(455,252),9,255, 255, 255, 0);

				//nangis kiri
				FB.drawCircle(Point(340,265),2,205,206,235,0);
				FB.drawCircle(Point(338,275),2,205,206,235,0);
				FB.drawCircle(Point(335,285),2,205,206,235,0);
				FB.drawCircle(Point(332,295),2,205,206,235,0);
				FB.drawCircle(Point(330,305),2,205,206,235,0);

				//nangis kanan
				FB.drawCircle(Point(460,265),2,205,206,235,0);
				FB.drawCircle(Point(462,275),2,205,206,235,0);
				FB.drawCircle(Point(465,285),2,205,206,235,0);
				FB.drawCircle(Point(468,295),2,205,206,235,0);
				FB.drawCircle(Point(470,305),2,205,206,235,0);

			}
			else if(key=='f' || key=='F') {
				// MEREM
				myFace.eyesClosed();
			}
			else if(key=='g' || key=='G') {
				// WINK
				myFace.wink();
				FB.drawCircle(Point(455,248),9,255, 255, 255, 0);
			}
			else if(key=='q') {
				// QUIT
				myFace.normalExpression();
				FB.drawCircle(Point(345,248),9,255, 255, 255, 0);
				FB.drawCircle(Point(455,248),9,255, 255, 255, 0);
				quit = true;
			}
			else {
				// BACK TO NORMAL
				myFace.normalExpression();
				FB.drawCircle(Point(345,248),9,255, 255, 255, 0);
				FB.drawCircle(Point(455,248),9,255, 255, 255, 0);
			}
			myFace.drawFace();
			colorFace();
			
			if (key=='1'){ //pirang
				FB.floodFill(400,170,0,0,0,218,165,32);
			} else if (key=='2'){ //coklat
				FB.floodFill(400,170,0,0,0,139,0,0);
			} else if (key=='3'){ //storm
				FB.floodFill(400,170,0,0,0,255,255,255);
				FB.floodFill(342,250,0,0,0,255,255,255);
				FB.floodFill(450,250,0,0,0,255,255,255);
			}
			
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
	
	//rambut
	FB.floodFill(400,170,135,206,235,0,0,0);
}