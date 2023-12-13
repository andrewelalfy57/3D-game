#include <string>
#include <iostream>
#include <glut.h>
using namespace std;
float rotAng;
int countkilled = 0;
double zposition = 5;
double actx = 0;
bool doubleScore = false;
double acty = 0;
double actz = 0;
double actx2 = 0;
bool killed = false;
double xvalueserved=0;
double yvalueserved=0;
double acty2 = 0;
double actz2 = 0;
double diff = 0;
bool replay = false;
bool leftx=false;
bool rightx = false;
bool upy = false;
bool downy = false;
bool tot = false;
bool slowZ = false;
bool TwoBalls = false;
bool flag = false;
bool flag2 = false;
bool xaxis = false;
bool xaxistemp = false;
bool yaxistemp = false;
bool yaxis = false;
bool xaxis2 = false;
bool yaxis2 = false;
bool xzero = false;
bool khalas = false;
double xvalue = 0;
double xvauetemp = 0;
double yvauetemp = 0;
double xvalue2 = 0;
double yvalue = 0;
bool finish = false;
bool fired = false;
int currentScore=10;
int currentScoreTemp = 0;
int totalScore = 0;
bool entered = false;
bool fired2 = false;
double actxtemp = 0.0;
double actytemp = 0.0;
double actztemp = 0.0;
int number = 0;
bool slowmotion = false;
bool slowmotion_finish = false;
bool pressed = false;
bool pressed2 = false;
double cameraDirection = 5.0;
bool instructions = true;
void beginning(char* string, float x, float y, float z)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos3f(x, y,z);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}


void setupCamera() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 300 / 300, 0.1f, 300.0f);
	//gluPerspective(60, 640 / 480, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0, cameraDirection, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);

}

void setupCamera2() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 300 / 300, 0.1f, 300.0f);
	//gluPerspective(60, 640 / 480, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(200.0f, 200.0, 200.0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
}
void setupCamera3() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 300 / 300, 0.1f, 300.0f);
	//gluPerspective(60, 640 / 480, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-200.0f, -200.0, -200.0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);

}

void drawBitmapText(char* string, float x, float y, float z)
{ 
	char* c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != ' '; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
	
	if (finish || slowmotion_finish) {
		
		if (currentScore > 999) {
			currentScoreTemp = currentScore / 1000;
			char d = 48 + currentScoreTemp;
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, d);
		}
		if (currentScore > 99) {
			int currentScore2 = currentScore % 1000;
			int currentScoreTempt = currentScore2 / 100;
			char v = 48 + currentScoreTempt;
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, v);
		}
		if (currentScore > 9) {
			int currentScore3 = currentScore % 100;
			int currentScoreTempt3 = currentScore3 / 10;
			char v3 = 48 + currentScoreTempt3;
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, v3);
		}
		int currentScore24 = currentScore % 10;
		int currentScoreTempt4 = currentScore24 / 10;
		char v4 = 48 + currentScoreTempt4;
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, v4);
		
	}
}

void drawBitmapText3(char* string, float x, float y, float z)
{
	char* c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != ' '; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}

	if (finish == true) {
		if (!tot) {
			totalScore =totalScore+ currentScore;
		}
		if (totalScore > 999) {
			currentScoreTemp = totalScore / 1000;
			char d = 48 + currentScoreTemp;
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, d);
		}
		if (totalScore > 99) {
			int currentScore2 = totalScore % 1000;
			int currentScoreTempt = currentScore2 / 100;
			char v = 48 + currentScoreTempt;
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, v);
		}
		if (totalScore > 9) {
			int currentScore3 = totalScore % 100;
			int currentScoreTempt3 = currentScore3 / 10;
			char v3 = 48 + currentScoreTempt3;
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, v3);
		}
		int currentScore24 = totalScore % 10;
		int currentScoreTempt4 = currentScore24 / 10;
		char v4 = 48 + currentScoreTempt4;
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, v4);
		tot = true;
	}
}

void setupLights() {
	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupLights2() {
	GLfloat ambient2[] = { 0.1f, 0.1, 0.1, 1.5f };
	GLfloat diffuse2[] = { 0.1f, 0.1f, 0.1, 1.5f };
	GLfloat specular2[] = { 1.6f, 1.6f, 1.0, 1.6f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity2[] = { 0.27f, 0.47f, 1, 1.0f };
	GLfloat lightPosition2[] = { -7.40f, 6.40f, 3.70f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition2);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity2);
}

void setupLights3() {
	GLfloat ambient3[] = { 0.37f, 0.57f, 0.67, 1.90f };
	GLfloat diffuse3[] = { 0.36f, 0.46f, 0.76, 1.80f };
	GLfloat specular3[] = { 1.30f, 1.40f, 1.70, 1.80f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient3);
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse3);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular3);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity3[] = { 0.76f, 0.97f, 1, 1.80f };
	GLfloat lightPosition3[] = { -7.70f, 6.70f, 3.90f, 0.900f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition3);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity3);
}

void setupLights4() {
	GLfloat ambient[] = { 1.957f, 0.247f, 0.37, 0.20f };
	GLfloat diffuse[] = { 1.956f, 0.166f, 0.26, 0.10f };
	GLfloat specular[] = { 1.560f, 0.290f, 0.180, 0.170f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.47f, 0.74f, 1.6, 1.60f };
	GLfloat lightPosition[] = { -7.40f, 6.02f, 3.5f, 0.40f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupLights5() {
	GLfloat ambient[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat diffuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat specular[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.47f, 0.74f, 1.6, 1.60f };
	GLfloat lightPosition[] = { -7.40f, 6.02f, 3.5f, 0.40f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupLights6() {
	GLfloat ambient[] = { 90.7f, 3.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 10.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}
void setupLights7() {
	GLfloat ambient[] = { 190.7f, 35.7f, 05.7, 15.0f };
	GLfloat diffuse[] = { 150.6f, 0.56f, 50.6, 15.0f };
	GLfloat specular[] = { 15.0f, 15.0f, 15.0, 51.0f };
	GLfloat shininess[] = { 550 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 5.7f, 50.7f, 15, 15.0f };
	GLfloat lightPosition[] = { -75.0f, 56.0f, 3.50f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}
void setupLights8() {
	GLfloat ambient[] = { 17.0f, 3.7f, 105.7, 150.0f };
	GLfloat diffuse[] = { 50.6f, 20.56f, 5.6, 150.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 150.0, 5.10f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 5.7f, 50.7f, 15, 15.0f };
	GLfloat lightPosition[] = { -75.0f, 56.0f, 3.50f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}
void setupLights9() {
	GLfloat ambient[] = { 0.9907f, 93.7f, 50.7, 11.0f };
	GLfloat diffuse[] = { 0.106f, 90.6f, 70.6, 11.0f };
	GLfloat specular[] = { 51.0f, 641.0f, 91.0, 51.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}
void setupLights10() {
	GLfloat ambient[] = { 90000.7f, 0.07f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 9.6, 1.0f };
	GLfloat specular[] = { 19.0f, 17.0f, 1.0, .0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if (instructions == true) {
		setupCamera2();
	}
	else {
		setupCamera();
	}

	setupLights();
	//7eta shemal ta7t
	glPushMatrix();
	glTranslatef(-1.7,-1.7, 0);
	glRotatef(90, 1 ,0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights6();
	glPushMatrix();
	glTranslatef(-1.7, -1.7, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	
	setupLights3();
	glPushMatrix();
	glTranslatef(-1.7, -1.7, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-1.7, -1.7, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-1.7, -1.7, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(-1.7, -1.7, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

// shemal fo2

	glPushMatrix();
	glTranslatef(-1.7, -0.7, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	
	setupLights3();
	glPushMatrix();
	glTranslatef(-1.7, -0.7, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	
	setupLights2();
	glPushMatrix();
	glTranslatef(-1.7, -0.7, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-1.7, -0.7, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-1.7, -0.7, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(-1.7, -0.7, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	//shemal fo2 khales

	glPushMatrix();
	glTranslatef(-1.7, 0.3, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-1.7, 0.3, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-1.7, 0.3, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(-1.7, 0.3, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(-1.7, 0.3, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-1.7, 0.3, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	//shemal fo2 akher 7aga

	glPushMatrix();
	glTranslatef(-1.7, 1.3, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-1.7, 1.3, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-1.7, 1.3, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(-1.7, 1.3, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(-1.7, 1.3, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-1.7, 1.3, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	//shemal fo2 fo2 akher 7aga


	glPushMatrix();
	glTranslatef(-1.7, 2.3, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-1.7, 2.3, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-1.7, 2.3, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(-1.7, 2.3, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(-1.7, 2.3, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-1.7, 2.3, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();



	// emeen ta7t
	glPushMatrix();
	glTranslatef(1.7, -1.7, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	//henaaa
	setupLights7();
	glPushMatrix();
	glTranslatef(1.7, -1.7, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(1.7, -1.7, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(1.7, -1.7, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(1.7, -1.7, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(1.7, -1.7, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();



	// emen fo2

	glPushMatrix();
	glTranslatef(1.7, -0.7, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(1.7, -0.7, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(1.7, -0.7, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(1.7, -0.7, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(1.7, -0.7, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(1.7, -0.7, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	//emeen fo2 khales

	glPushMatrix();
	glTranslatef(1.7, 0.3, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(1.7, 0.3, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(1.7, 0.3, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(1.7, 0.3, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(1.7, 0.3, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(1.7, 0.3, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	//emeen fo2 akher 7aga

	glPushMatrix();
	glTranslatef(1.7, 1.3, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(1.7, 1.3, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(1.7, 1.3, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(1.7, 1.3, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(1.7, 1.3, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(1.7, 1.3, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	//emeen fo2 fo2 akher 7aga

	
	glPushMatrix();
	glTranslatef(1.7, 2.3, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(1.7, 2.3, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(1.7, 2.3, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(1.7, 2.3, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(1.7, 2.3, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(1.7, 2.3, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	//top right
	setupLights();
	glPushMatrix();
	glTranslatef(0.7, 2.3, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights9();
	glPushMatrix();
	glTranslatef(0.7, 2.3, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(0.7, 2.3, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(0.7, 2.3, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(0.7, 2.3, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(0.7, 2.3, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	//top left

	setupLights2();
	glPushMatrix();
	glTranslatef(-0.3, 2.3, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-0.3, 2.3, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(-0.3, 2.3, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(-0.3, 2.3, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-0.3, 2.3, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-0.3, 2.3, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	//top left el shemal
	setupLights2();
	glPushMatrix();
	glTranslatef(-1.3, 2.3, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	setupLights4();
	glPushMatrix();
	glTranslatef(-1.3, 2.3, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(-1.3, 2.3, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(-1.3, 2.3, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-1.3, 2.3, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-1.3, 2.3, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	//bottom
	

	glPushMatrix();
	glTranslatef(0.7, -2.5, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(0.7, -2.5, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(0.7, -2.5, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(0.7, -2.5, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(0.7, -2.5, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(0.7, -2.5, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	//top left

	setupLights2();
	glPushMatrix();
	glTranslatef(-0.3, -2.5, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights10();
	glPushMatrix();
	glTranslatef(-0.3, -2.5, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(-0.3, -2.5, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(-0.3, -2.5, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-0.3, -2.5, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-0.3, -2.5, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	//top left el shemal
	setupLights();
	glPushMatrix();
	glTranslatef(-1.3, -2.5, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	setupLights10();
	glPushMatrix();
	glTranslatef(-1.3, -2.5, -1);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights3();
	glPushMatrix();
	glTranslatef(-1.3, -2.5, -2);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(-1.3, -2.5, -3);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights();
	glPushMatrix();
	glTranslatef(-1.3, -2.5, -4);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights4();
	glPushMatrix();
	glTranslatef(-1.3, -2.5, -5);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	//back

	setupLights5();
	glPushMatrix();
	glTranslatef(0, -0.09, -8);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(3);
	glPopMatrix();


	setupLights3();
	glPushMatrix();
	glTranslatef(0, -0.09, -7);
	glRotatef(90, 1, 0, 0);
	glRotatef(rotAng, 0, 1, 0);
	glutSolidCube(2);
	glPopMatrix();

	setupLights2();
	glPushMatrix();
	glTranslatef(0, -0.09, -6);
	glRotatef(90, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	setupLights6();
	if (!slowmotion) {
		glPushMatrix();
		glTranslatef(0, -1.7, 0);
		glTranslatef(actx2, acty2, actz2);
		glutSolidSphere(0.2, 45, 45);
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glTranslatef(0, -1.7, 0);
		glTranslatef(actxtemp, actytemp, actz2);
		glutSolidSphere(0.2, 45, 45);
		glPopMatrix();
	}
	setupLights6();
	glPushMatrix();
	glTranslatef(actx, acty, actz);
	glutWireSphere(0.2,15,15);
	glPopMatrix();

	if (TwoBalls) {
		glPushMatrix();
		glTranslatef(0, -1.7, 0);
		glTranslatef(actxtemp, actytemp, actz2);
		glutSolidSphere(0.2, 45, 45);
		glPopMatrix();
	}

	glBegin(GL_LINES);
	glVertex3f(0.0f, -1.7f, 0.0f);
	glVertex3f(actx, acty, actz);
	glEnd();

	
	if (khalas == true) {
		setupCamera3();
		beginning("GAME OVER", -170, -140, -150);
		drawBitmapText3("Your_Total_Score_is_ ", -150, -135, -150);
		beginning("Press Q to exit", -130, -140, -150);
	}
	else {
		if (instructions == false) {
			drawBitmapText("Round_Score_is_ ", 0.5, 1.5, 1);
			beginning("Camera: Simple motion", 0.5, 1.2, 1);
			
			drawBitmapText3("Total_Score_is_ ", -1.5, 1.5, 1);
			if (TwoBalls) {
			beginning("Two balls ability is activated ", -1, 1, -5);
			}
			else {
				if (countkilled>0) {
					beginning("Killedf by MAGIC", -1, 1, -5);
				}
				else {
					if (slowZ) {
						beginning("Fast Z traverse Ability", -1, 1, -5);
					}
					else {
						if (doubleScore) {
							beginning("Double Score feature activated", -1, 1, -5);
						}
					}
				}
			}
			
		}
		else {
			beginning("Game Instruction :", 50, 100, 150);
			beginning("1)To shoot the ball press on 's' ", 60, 100, 140);
			beginning("2)To return to instructions from game press 'c' ", 80, 100, 140);
			beginning("3)To start game press 'c' ", 100, 100, 140);
			
			beginning("5)Special powers : yellow -> 3 times score", 130, 100, 140);
			beginning("indigo -> continue with 2 balls", 140, 100, 140);
			beginning("white -> repeat round from beggining", 150, 100, 140);
			beginning("pale pink -> Fast z axis traverse", 160, 100, 140);
			beginning("yellow -> 3 times score", 170, 100, 140);
		

		}
	}
	
	

	glFlush();
}

void keyUp(unsigned char k, int x, int y)//keyboard up function is called whenever the keyboard key is released
{
	countkilled = 0;
	if (instructions == false) {
		if (k == 's' || k == 'S') {

			if (!pressed && !slowmotion) {
				pressed = true;
				currentScore = 0;


				if (actx == 0) {
					xvalue = 0;
					xzero = true;
				}
				else {
					if (actx < 0) {
						xaxis = true;
					}
					else {
						xaxis = false;
					}
					if (acty < -1.3) {
						xvalue = 0.001;
						yvalue = 0.0002;
					}
					else {
						if (acty < -0.7) {
							xvalue = 0.001;
							yvalue = 0.001;
						}
						else {
							if (acty < 0.3) {
								xvalue = 0.0006;
								yvalue = 0.001;
							}
							else {
								if (acty < 1.3) {
									xvalue = 0.0006;
									yvalue = 0.0015;
								}
								else {
									if (acty < 2.3) {
										xvalue = 0.0006;
										yvalue = 0.003;
									}
								}
							}
						}

					}

				}
				xvalueserved = xvalue;
				yvalueserved = yvalue;

				yaxis = true;
				actx = 0;
				acty = -20;
				xaxis2 = xaxis;
				yaxis2 = yaxis;
				flag = true;
				fired = true;
				finish = false;

			}
		}
	/*	if (k == 'r' || k == 'R') {
			if (!pressed2) {
				if (number > 0) {
					currentScore = 0;
					replay = true;
					actx = 0;
					acty = -20;
					pressed2 = true;
					actx2 = 0;
					acty2 = 0;
					actz2 = 0;
					slowmotion = true;
					flag2 = true;
					xaxis = xaxis2;
					xvalue = xvalueserved / 2;
					yvalue = yvalueserved / 2;
					slowmotion_finish = false;
				}
			}
		}*/
	}
	if (k == 'C' || k == 'c') {
		instructions = !instructions;
	}
	if (khalas) {
		if (k == 'q' || k == 'Q') {
			exit(EXIT_SUCCESS);
		}
	}

	glutPostRedisplay();//redisplay to update the screen with the changed
}

void spe(int k, int x, int y)// keyboard special key function takes 3 parameters
							// int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
{
	countkilled = 0;
	if (fired == false) {
		if (actx > -1) {
			if (actx < 1) {
				if (k == GLUT_KEY_RIGHT)//if the right arrow is pressed, then the object will be translated in the x axis by 10. (moving right)	
					actx += 0.1;
				if (k == GLUT_KEY_LEFT)//if the left arrow is pressed, then the object will be translated in the x axis by -10. (moving left)
					actx -= 0.1;
				glutPostRedisplay();//redisplay to update the screen with the changes
			}
			else {
				if (k == GLUT_KEY_LEFT)//if the left arrow is pressed, then the object will be translated in the x axis by -10. (moving left)
					actx -= 0.1;

				glutPostRedisplay();//redisplay to update the screen with the changes
			}


		}
		else {
			if (k == GLUT_KEY_RIGHT)//if the right arrow is pressed, then the object will be translated in the x axis by 10. (moving right)	
				actx += 0.1;
			glutPostRedisplay();//redisplay to update the screen with the changes
		}

		if (acty > -2) {
			if (acty < 1.7) {

				if (k == GLUT_KEY_UP)//if the up arrow is pressed, then the object will be translated in the y axis by 10. (moving upwords)
					acty += 0.1;
				if (k == GLUT_KEY_DOWN)//if the down arrow is pressed, then the object will be translated in the y axis by -10. (moving downwords)
					acty -= 0.1;
				glutPostRedisplay();//redisplay to update the screen with the changes
			}
			else {

				if (k == GLUT_KEY_DOWN)//if the down arrow is pressed, then the object will be translated in the y axis by -10. (moving downwords)
					acty -= 0.1;
				glutPostRedisplay();//redisplay to update the screen with the changes
			}


		}
		else {
			if (k == GLUT_KEY_UP)//if the up arrow is pressed, then the object will be translated in the y axis by 10. (moving upwords)
				acty += 0.1;
			glutPostRedisplay();//redisplay to update the screen with the changes
		}

	}
}
void res(){
	doubleScore = false;
	TwoBalls = false;
	killed = false;
	slowZ = false;
	actx2 = 0;
	acty2 = 0;
	acty = 0;
	actx = 0;
	actz = 0;
	actz2 = 0;
    leftx=false;
    rightx = false;
    upy = false;
    downy = false;
	tot = false;
	cameraDirection = 5;

}
void Anim() {
	if (TwoBalls) {

		if (actztemp <= -5) {
				currentScore = currentScore * 2;
			TwoBalls = false;
		

		}
				actztemp = actz2-0.0001;
				xvauetemp = xvalue;
				yvauetemp = yvalue;
				if (actxtemp < -0.9) {
					xaxistemp = false;
				}
				else {
					if (actxtemp > 0.9) {
						xaxistemp = true;
					}
				}
				if (xaxistemp == true) {
					actxtemp -= xvauetemp;
				}
				else {
					actxtemp += xvauetemp;
				}
				if (actytemp < 0) {
					yaxistemp = true;
				}
				else {
					if (actytemp > 3) {
						yaxistemp = false;;
					}
				}
				if (yaxistemp == true) {
					actytemp += yvauetemp;
				}
				else {
					actytemp -= yvauetemp;
				}
		}
	
	if (slowZ) {
		actz2 -= 0.002;
		cameraDirection -= 0.002;
	}

	if (doubleScore) {
		currentScore = currentScore + 400;
	}

	if (killed == true) {
		actz2 = -6;
		countkilled++;
		killed = false;
		
	}
	if (instructions == false) {
		if (!slowmotion) {
			rotAng += 0.01;
			if (actz2 <= -5) {
				finish = true;
				if (number < 2) {
					number++;

					pressed = false;
					flag = false;
					fired = false;
					res();
				}
				else {
					khalas = true;
					
				}
			}
			if (flag == true && finish == false) {

				if (xvalue == 0) {
					actz2 -= 0.02;
					acty2 += 0.007;
					cameraDirection -= 0.02;
				}
				else {
					actz2 = actz2 - xvalue + 0.00001;
					cameraDirection -= (xvalue + 0.000001);
					if (actx2 < -0.9) {
						xaxis = false;
					}
					else {
						if (actx2 > 0.9) {
							xaxis = true;
						}
					}
					if (xaxis == true) {
						actx2 -= xvalue;
					}
					else {
						actx2 += xvalue;
					}
					if (acty2 < 0) {
						yaxis = true;
					}
					else {
						if (acty2 > 3) {
							yaxis = false;;
						}
					}
					if (yaxis == true) {
						acty2 += yvalue;
					}
					else {
						acty2 -= yvalue;
					}



				}
			}
		}
		else {
			rotAng += 0.001;
			if (actz2 <= -5) {
				slowmotion_finish = true;
				slowmotion = false;
				pressed2 = false;
				if (replay) {
					replay = !replay;
				}
				res();
			}
			if (flag2 == true && slowmotion_finish == false) {
				if (xzero) {
					actz2 -= 0.002;
					acty2 += 0.0007;
					cameraDirection -= 0.002;
				}
				else {
				
					if (actx2 < -0.9) {
						xaxis = false;
					}
					else {
						if (actx2 > 0.9) {
							xaxis = true;
						}
					}
					if (xaxis == true) {
						actx2 -= xvalue;
					}
					else {
						actx2 += xvalue;
					}
					if (acty2 < 0) {
						yaxis = true;
					}
					else {
						if (acty2 > 3) {
							yaxis = false;;
						}
					}
					if (yaxis == true) {
						acty2 += yvalue;
					}
					else {
						acty2 -= yvalue;
					}
				}
			}

		}
		if (!replay) {
			if (actx2 <= -0.8) {
				if (!leftx) {
					if (acty2 >= 0.0 && acty2 <= 0.7) {
						if (actz2 <= 0 && actz2 > -1) {
							
							doubleScore = true;
						}
						if (actz2 <= -1 && actz2 >= -2) {
							currentScore += 10;
							
						}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore += 20;
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore -= 10;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore += 10;
						}if (actz2 <= -5 && actz2 > -6) {
							currentScore += 30;
						}

					}
					//second
					if (acty2 > 0.7 && acty2 <= 1.7) {
						if (actz2 <= 0 && actz2 > -1) {
							currentScore += 30;
						}
						if (actz2 <= -1 && actz2 > -2) {
							currentScore += 20;
						}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore += 30;
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore += 10;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore -= 10;
						}
						if (actz2 <= -5 && actz2 > -6) {
							currentScore += 20;
						}

					}
					//third

					if (acty2 > 1.7 && acty2 <= 2.3) {
						if (actz2 <= 0 && actz2 > -1) {
							currentScore += 20;
						}
						if (actz2 <= -1 && actz2 > -2) {
							currentScore += 10;
						}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore -= 10;
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore += 20;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore += 30;
						}
						if (actz2 <= -5 && actz2 > -6) {
							currentScore += 10;
						}
					}
					//fourth
					if (acty2 > 2.3 && acty2 <= 3) {
						if (actz2 <= 0 && actz2 > -1) {
							currentScore += 10;
						}
						if (actz2 <= -1 && actz2 > -2) {
							currentScore -= 10;
						}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore += 10;
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore += 30;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore += 20;
						}
						if (actz2 <= -5 && actz2 > -6) {
							currentScore -= 10;
						}
					}
					leftx = true;
					upy = false;
					rightx = false;
					downy = false;

				}
			}
			if (actx2 >= 0.8) {
				if (!rightx) {
					if (acty2 > 0 && acty2 <= 0.7) {
						if (actz2 <= 0 && actz2 > -1) {
						
							killed = true;
						}
						if (actz2 <= -1 && actz2 > -2) {
							currentScore += 30;
						}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore += 20;
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore -= 10;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore += 10;
						}if (actz2 <= -5 && actz2 > -6) {
							currentScore += 30;
						}

					}
					//second
					if (acty2 > 0.7 && acty2 <= 1.7) {
						if (actz2 <= 0 && actz2 > -1) {
							currentScore += 30;
						}
						if (actz2 <= -1 && actz2 > -2) {
							currentScore += 20;
						}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore += 30;
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore += 10;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore -= 10;
						}
						if (actz2 <= -5 && actz2 > -6) {
							currentScore += 20;
						}

					}
					//third

					if (acty2 > 1.7 && acty2 <= 2.3) {
						if (actz2 <= 0 && actz2 > -1) {
							currentScore += 20;
						
					
						}
						if (actz2 <= -1 && actz2 > -2) {
							currentScore += 10;
						}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore -= 10;
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore += 20;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore += 30;
						}
						if (actz2 <= -5 && actz2 > -6) {
							currentScore += 10;
						}
					}
					//fourth
					if (acty2 > 2.3 && acty2 <= 3) {
						if (actz2 <= 0 && actz2 > -1) {
							currentScore += 10;
						}
						if (actz2 <= -1 && actz2 > -2) {
							currentScore -= 10;
						}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore += 10;
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore += 30;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore += 20;
						}
						if (actz2 <= -5 && actz2 > -6) {
							currentScore -= 10;
						}
					}
					leftx = false;
					upy = false;
					rightx = true;
					downy = false;
				}
			}
			if (actx2 > -0.8 && actx2 < 0.1) {
				if (acty2 >= 2.9) {
					if (!upy) {
						if (actz2 < 0 && actz2 > -1) {
							currentScore += 30;
						
						}
						if (actz2 <= -1 && actz2 > -2) {
							currentScore -= 10;
						}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore += 20;
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore += 30;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore += 10;
						}
						if (actz2 <= -5 && actz2 > -6) {
							currentScore -= 10;
						}
						leftx = false;
						upy = true;
						rightx = false;
						downy = false;
					}
				}
				if (acty2 <=0.2) {
					if (!downy) {
						if (actz2 < 0 && actz2 > -1) {
							currentScore += 30;
						}
						if (actz2 <= -1 && actz2 > -2) {
							currentScore -= 10;
							slowZ = true;
													}
						if (actz2 <= -2 && actz2 > -3) {
							currentScore += 20;
							
						}
						if (actz2 <= -3 && actz2 > -4) {
							currentScore += 30;
						}
						if (actz2 <= -4 && actz2 > -5) {
							currentScore += 10;
						}
						if (actz2 <= -5 && actz2 > -6) {
							currentScore -= 10;
						}
						leftx = false;
						upy = false;
						rightx = false;
						downy = true;
					}
				}
				if (acty2 == 0) {
					currentScore = currentScore;
				}
			}
			if (actx2 >= 0.1 && actx2 < 0.8) {
				if (acty2 >= 2.9) {
					if (actz2 <= 0 && actz2 > -1) {
						currentScore += 30;
						TwoBalls = true;

					}
					if (actz2 <= -1 && actz2 > -2) {
						currentScore += 10;
						
					}
					if (actz2 <= -2 && actz2 > -3) {
						currentScore -= 10;
						
					}
					if (actz2 <= -3 && actz2 > -4) {
						currentScore += 20;
						

					}
					if (actz2 <= -4 && actz2 > -5) {
						currentScore += 30;
						
					}if (actz2 <= -5 && actz2 > -6) {
						currentScore += 10;
						
					}
				}
				if (acty2 == 0.1) {
					if (actz2 <= 0 && actz2 > -1) {
						currentScore -= 30;
					}
					if (actz2 <= -1 && actz2 > -2) {
						currentScore += 10;
					}
					if (actz2 <= -2 && actz2 > -3) {
						currentScore -= 10;
					}
					if (actz2 <= -3 && actz2 > -4) {
						currentScore += 20;
					}
					if (actz2 <= -4 && actz2 > -5) {
						currentScore += 30;
					}if (actz2 <= -5 && actz2 > -6) {
						currentScore += 10;
					}

				}
			}
		}

		glutPostRedisplay();
	}
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(750, 650);
	glutInitWindowPosition(250, 60);
	glutCreateWindow("Andrew");
	glutDisplayFunc(Display);
	glutKeyboardUpFunc(keyUp);		//call the keyboard up function
	glutSpecialFunc(spe);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	
	glutIdleFunc(Anim);
	glClearColor(0.1, 0.1, 0.1, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glutMainLoop();
}
