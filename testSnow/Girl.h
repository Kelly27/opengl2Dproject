#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\freeglut.h>

#define PI 3.141592

//define circle
void circleFill(float x, float y, float r, float n) {
	//1st x-axis of centre pt, 2nd y-axis of centre pt, 3rd radius, 4th vertex (corner)
	float inc = (2 * PI) / n;
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc)
		glVertex2f(r*cos(theta) + x, r*sin(theta) + y);
	glEnd();
}
void circleBlank(float x, float y, float r, float n) {
	float inc = (2 * PI) / n;
	glBegin(GL_LINE_STRIP);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc)
		glVertex2f(r*cos(theta) + x, r*sin(theta) + y);
	glEnd();
}

void ovalFillVertical(float x, float y, float r, float n) {
	float inc = (2 * PI) / n;
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc)
		glVertex2f(1.5*r*cos(theta) + x, 2 * r*sin(theta) + y);
	glEnd();
}
void ovalBlankVertical(float x, float y, float r, float n) {
	float inc = (2 * PI) / n;
	glBegin(GL_LINE_STRIP);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc)
		glVertex2f(1.5*r*cos(theta) + x, 2 * r*sin(theta) + y);
	glEnd();
}
void ovalFillHorizontal(float x, float y, float r, float n) {
	float inc = (2 * PI) / n;
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc)
		glVertex2f(2 * r*cos(theta) + x, r*sin(theta) + y);
	glEnd();
}

//define rectangle
void rectangle(float x, float y, float w, float h) {
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y + h);
	glVertex2f(x, y + h);
	glEnd();
}
void triangleReverse(float x, float y, float w, float h) {
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w / 2, y - h);
	glEnd();
}

void face(float x, float y, float w, float h) {
	glColor3ub(255, 241, 229);
	circleFill((x + (w / 2)), (y + (h / 65 * 56)), (h / 65 * 9), 200);
}
void rightEye(float x, float y, float w, float h) {
	//white part
	glColor3ub(0, 0, 0);
	ovalFillVertical((x + (w / 18 * 7)), (y + (h / 65 * 54)), (h / 325 * 6), 200);
	//middle part
	glColor3ub(255, 255, 255);
	ovalFillVertical((x + (w / 180 * 71)), (y + (h / 325 * 270)), (h / 325 * 3), 200);
	ovalFillVertical((x + (w / 180 * 71)), (y + (h / 325 * 260)), (h / 325 * 1), 200);
	//outer part
	glColor3ub(0, 0, 0);
	ovalBlankVertical((x + (w / 18 * 7)), (y + (h / 65 * 54)), (h / 325 * 6), 200);
}
void leftEye(float x, float y, float w, float h) {
	//white part
	glColor3ub(0, 0, 0);
	ovalFillVertical((x + (w / 18 * 11)), (y + (h / 65 * 54)), (h / 325 * 6), 200);
	//middle part
	glColor3ub(255, 255, 255);
	ovalFillVertical((x + (w / 180 * 109)), (y + (h / 325 * 270)), (h / 325 * 3), 200);
	ovalFillVertical((x + (w / 180 * 109)), (y + (h / 325 * 260)), (h / 325 * 1), 200);
	//outer part
	glColor3ub(0, 0, 0);
	ovalBlankVertical((x + (w / 18 * 11)), (y + (h / 65 * 54)), (h / 325 * 6), 200);
}
void eyebrown(float x, float y, float w, float h) {
	glColor3ub(160, 130, 60);
	for (int i = (x + (w / 12 * 7)); i<(x + (w / 3 * 2)); i++) {
		glBegin(GL_LINES);
		glVertex2f(i, y + (h / 325 * 288));
		glVertex2f(i - 5, y + (h / 65 * 57));
		glEnd();
	}
	for (int i = (x + (w / 3)); i<(x + (w / 12 * 5)); i++) {
		glBegin(GL_LINES);
		glVertex2f(i, y + (h / 325 * 288));
		glVertex2f(i + 5, y + (h / 65 * 57));
		glEnd();
	}
}
void mouth(float x, float y, float w, float h) {
	glColor3ub(255, 43, 43);
	ovalFillHorizontal((x + (w / 2)), (y + (h / 65 * 49)), (h / 130), 100);
}
void nose(float x, float y, float w, float h) {
	glColor3ub(255, 219, 163);
	ovalFillVertical((x + (w / 2)), (y + (h / 5 * 4)), (h / 325), 50);
}
void hairFront(float x, float y, float w, float h) {
	glColor3ub(160, 130, 60);	//glColor3ub(188, 181, 188);
	for (int i = (x + (w / 3)); i<(x + (w / 18 * 11)); i += 5) {
		triangleReverse(i, y + (h / 65 * 62), (w / 18), (h / 65 * 4));
		i += 5;
		triangleReverse(i, y + (h / 65 * 62), (w / 9), (h / 65 * 4));
		i += 15;
	}
	float inc = (2 * PI) / 50;
	glBegin(GL_POLYGON);	//GL_LINE_STRIP for circle line
	for (float theta = 0.0; theta <= (PI + inc) / 1.5; theta += inc)
		glVertex2f((h / 325 * 46)*-cos(theta) + (x + (w / 2)), (h / 325 * 46)*sin(theta) + (y + (h / 65 * 56)));
	glEnd();
	glBegin(GL_POLYGON);	//GL_LINE_STRIP for circle line
	for (float theta = 0.0; theta <= (PI + inc) / 1.5; theta += inc)
		glVertex2f((h / 325 * 46)*cos(theta) + (x + (w / 2)), (h / 325 * 46)*sin(theta) + (y + (h / 65 * 56)));
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(x + (w / 4), y + (h / 65 * 56));
	glVertex2f(x + (w / 9 * 2), y + (h / 65 * 46));
	glVertex2f(x + (w / 36 * 11), y + (h / 65 * 46));
	glVertex2f(x + (w / 36 * 11), y + (h / 65 * 58));
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(x + (w / 4 * 3), y + (h / 65 * 56));
	glVertex2f(x + (w / 9 * 7), y + (h / 65 * 46));
	glVertex2f(x + (w / 36 * 25), y + (h / 65 * 46));
	glVertex2f(x + (w / 36 * 25), y + (h / 65 * 58));
	glEnd();
}
void hairBack(float x, float y, float w, float h) {
	glColor3ub(122, 96, 41);
	glBegin(GL_POLYGON);
	glVertex2f(x + (w / 4), y + (h / 65 * 56));
	glVertex2f(x + (w / 6), y + (h / 5 * 2));
	glVertex2f(x + (w / 6 * 5), y + (h / 5 * 2));
	glVertex2f(x + (w / 4 * 3), y + (h / 65 * 56));
	glEnd();
	for (int i = (x + (w / 6)); i<(x + (w / 9 * 7)); i += 5) {
		triangleReverse(i, y + (h / 5 * 2), (w / 18), (h / 65 * 4));
		i += 5;
		triangleReverse(i, y + (h / 5 * 2), (w / 12), (h / 65 * 4));
		i += 15;
	}
}
void head(float x, float y, float w, float h) {
	face(x, y, w, h);
	rightEye(x, y, w, h);
	leftEye(x, y, w, h);
	mouth(x, y, w, h);
	nose(x, y, w, h);
	hairFront(x, y, w, h);
	eyebrown(x, y, w, h);
}

void rightHand(float x, float y, float w, float h) {
	glColor3ub(255, 241, 229);
	//arm
	glBegin(GL_POLYGON);
	glVertex2f(x + (w / 36 * 11), y + (h / 65 * 38));
	glVertex2f(x + (w / 15 * 4), y + (h / 65 * 36));
	glVertex2f(x + (w / 15 * 4), y + (h / 65 * 31));
	glVertex2f(x + (w / 12 * 5), y + (h / 65 * 38));
	glEnd();
}
void leftHand(float x, float y, float w, float h) {
	glColor3ub(255, 241, 229);
	//arm
	glBegin(GL_POLYGON);
	glVertex2f(x + (w / 36 * 25), y + (h / 65 * 38));
	glVertex2f(x + (w / 15 * 11), y + (h / 65 * 36));
	glVertex2f(x + (w / 15 * 11), y + (h / 65 * 31));
	glVertex2f(x + (w / 12 * 7), y + (h / 65 * 38));
	glEnd();
}
void rightLeg(float x, float y, float w, float h) {
	glColor3ub(236, 236, 236);
	rectangle(x + (w / 3), y + (h / 13 * 2), (w / 12), (h / 65 * 4));
	rectangle(x + (w / 36 * 11), y + (h / 65 * 7), (w / 36 * 5), (h / 65 * 3));
	glBegin(GL_POLYGON);
	glVertex2d(x + (w / 36 * 11), y + (h / 65 * 7));
	glVertex2d(x + (w / 18 * 5), y + (h / 65 * 3));
	glVertex2d(x + (w / 18 * 5), y + (h / 65));
	glVertex2d(x + (w / 45 * 17), y);
	glVertex2d(x + (w / 36 * 17), y + (h / 65));
	glVertex2d(x + (w / 36 * 17), y + (h / 65 * 3));
	glVertex2d(x + (w / 9 * 4), y + (h / 65 * 7));
	glEnd();
}
void leftLeg(float x, float y, float w, float h) {
	glColor3ub(236, 236, 236);
	rectangle(x + (w / 12 * 7), y + (h / 13 * 2), (w / 12), (h / 65 * 4));
	rectangle(x + (w / 9 * 5), y + (h / 65 * 7), (w / 36 * 5), (h / 65 * 3));
	glBegin(GL_POLYGON);
	glVertex2d(x + (w / 9 * 5), y + (h / 65 * 7));
	glVertex2d(x + (w / 36 * 19), y + (h / 65 * 3));
	glVertex2d(x + (w / 36 * 19), y + (h / 65));
	glVertex2d(x + (w / 180 * 113), y);
	glVertex2d(x + (w / 18 * 13), y + (h / 65));
	glVertex2d(x + (w / 18 * 13), y + (h / 65 * 3));
	glVertex2d(x + (w / 36 * 25), y + (h / 65 * 7));
	glEnd();
}
void body(float x, float y, float w, float h) {
	rightHand(x, y, w, h);
	leftHand(x, y, w, h);
	rightLeg(x, y, w, h);
	leftLeg(x, y, w, h);
}

void shirt(float x, float y, float w, float h) {
	glBegin(GL_POLYGON);
	glColor3ub(255, 187, 183);
	glVertex2f(x + (w / 18 * 7), y + (h / 65 * 42));
	glVertex2f(x + (w / 18 * 11), y + (h / 65 * 42));
	glVertex2f(x + (w / 12 * 7), y + (h / 65 * 32));
	glVertex2f(x + (w / 12 * 5), y + (h / 65 * 32));
	glEnd();
}
void skirt(float x, float y, float w, float h) {
	glBegin(GL_POLYGON);
	glColor3ub(94, 72, 191);
	glVertex2f(x + (w / 18 * 13), y + (h / 65 * 12));
	glVertex2f(x + (w / 18 * 11), y + (h / 65 * 28));
	glVertex2f(x + (w / 12 * 7), y + (h / 65 * 32));
	glVertex2f(x + (w / 12 * 5), y + (h / 65 * 32));
	glVertex2f(x + (w / 18 * 7), y + (h / 65 * 28));
	glVertex2f(x + (w / 18 * 5), y + (h / 65 * 12));
	glEnd();
}
void collar(float x, float y, float w, float h) {
	glColor3ub(255, 114, 107);
	//neck
	glBegin(GL_POLYGON);
	glVertex2f(x + (w / 36 * 19), y + (h / 65 * 48));
	glVertex2f(x + (w / 9 * 5), y + (h / 65 * 44));
	glVertex2f(x + (w / 9 * 4), y + (h / 65 * 44));
	glVertex2f(x + (w / 36 * 17), y + (h / 65 * 48));
	glEnd();
	//body
	glBegin(GL_POLYGON);
	glVertex2f(x + (w / 9 * 5), y + (h / 65 * 44));
	glVertex2f(x + (w / 36 * 25), y + (h / 65 * 38));
	glVertex2f(x + (w / 36 * 11), y + (h / 65 * 38));
	glVertex2f(x + (w / 9 * 4), y + (h / 65 * 44));
	glEnd();
}
void rightHandSock(float x, float y, float w, float h, float handUP) {
	glColor3ub(147, 201, 255);
	if (handUP >= 400 && handUP <= 500 || handUP >= 1000 && handUP <= 1100 || handUP >= 1700 && handUP <= 1800) {
		//hand's up
		glBegin(GL_POLYGON);
		glVertex2f(x + (w / 15 * 4), y + (h / 65 * 36));
		glVertex2f(x + (w / 9 * 1), y + (h / 65 * 44));
		glVertex2f(x + (w / 9 * 1), y + (h / 65 * 40));
		glVertex2f(x + (w / 15 * 4), y + (h / 65 * 31));
		glEnd();
		///hand
		glBegin(GL_POLYGON);
		glVertex2f(x + (w / 9 * 1), y + (h / 65 * 44));
		glVertex2f(x, y + (h / 65 * 44));
		glVertex2f(x, y + (h / 65 * 40));
		glVertex2f(x + (w / 9 * 1), y + (h / 65 * 40));
		glEnd();
	}
	else {
		//arm
		glBegin(GL_POLYGON);
		glVertex2f(x + (w / 15 * 4), y + (h / 65 * 36));
		glVertex2f(x + (w / 9 * 1), y + (h / 65 * 28));
		glVertex2f(x + (w / 9 * 1), y + (h / 65 * 24));
		glVertex2f(x + (w / 15 * 4), y + (h / 65 * 31));
		glEnd();
		///hand
		glBegin(GL_POLYGON);
		glVertex2f(x + (w / 9 * 1), y + (h / 65 * 28));
		glVertex2f(x, y + (h / 65 * 26));
		glVertex2f(x, y + (h / 65 * 22));
		glVertex2f(x + (w / 9 * 1), y + (h / 65 * 24));
		glEnd();
	}
}
void leftHandSock(float x, float y, float w, float h, float handUP) {
	glColor3ub(147, 201, 255);
	if (handUP >= 400 && handUP <= 500 || handUP >= 1000 && handUP <= 1100 || handUP >= 1700 && handUP <= 1800) {
		//hand's up
		glBegin(GL_POLYGON);
		glVertex2f(x + (w / 15 * 11), y + (h / 65 * 36));
		glVertex2f(x + (w / 9 * 8), y + (h / 65 * 44));
		glVertex2f(x + (w / 9 * 8), y + (h / 65 * 40));
		glVertex2f(x + (w / 15 * 11), y + (h / 65 * 31));
		glEnd();
		///hand
		glBegin(GL_POLYGON);
		glVertex2f(x + (w / 9 * 8), y + (h / 65 * 44));
		glVertex2f(x + w, y + (h / 65 * 44));
		glVertex2f(x + w, y + (h / 65 * 40));
		glVertex2f(x + (w / 9 * 8), y + (h / 65 * 40));
		glEnd();
	}
	else {
		//arm
		glBegin(GL_POLYGON);
		glVertex2f(x + (w / 15 * 11), y + (h / 65 * 36));
		glVertex2f(x + (w / 9 * 8), y + (h / 65 * 28));
		glVertex2f(x + (w / 9 * 8), y + (h / 65 * 24));
		glVertex2f(x + (w / 15 * 11), y + (h / 65 * 31));
		glEnd();
		///hand
		glBegin(GL_POLYGON);
		glVertex2f(x + (w / 9 * 8), y + (h / 65 * 28));
		glVertex2f(x + w, y + (h / 65 * 26));
		glVertex2f(x + w, y + (h / 65 * 22));
		glVertex2f(x + (w / 9 * 8), y + (h / 65 * 24));
		glEnd();
	}
}
void clothes(float x, float y, float w, float h, float handUP) {
	skirt(x, y, w, h);
	shirt(x, y, w, h);
	collar(x, y, w, h);
	rightHandSock(x, y, w, h, handUP);
	leftHandSock(x, y, w, h, handUP);
}

void matches(float x, float y, float s, float handUP) {
	float w = s;
	float h = s * 65 / 36;
	if (handUP >= 400 && handUP <= 500 || handUP >= 1000 && handUP <= 1100 || handUP >= 1700 && handUP <= 1800) {
		glColor3ub(57, 35, 23);
		circleFill(x - 23, y + (h / 65 * 43) + 2, 5, 50);
		glBegin(GL_POLYGON);
		glColor3ub(185, 122, 87);
		glVertex2f(x - 20, y + (h / 65 * 43) + 5);
		glVertex2f(x, y + (h / 65 * 43));
		glVertex2f(x, y + (h / 65 * 41));
		glVertex2f(x - 20, y + (h / 65 * 41) + 5);
		glEnd();

	}
	else {
		glColor3ub(57, 35, 23);
		circleFill(x - 23, y + (h / 65 * 25) + 2, 5, 50);
		glBegin(GL_POLYGON);
		glColor3ub(185, 122, 87);
		glVertex2f(x - 20, y + (h / 65 * 25) + 5);
		glVertex2f(x, y + (h / 65 * 25));
		glVertex2f(x, y + (h / 65 * 23));
		glVertex2f(x - 20, y + (h / 65 * 23) + 5);
		glEnd();
		//fire(x, y, 2, 1);
	}
}
void matchfire(float x, float y, float r, float z) {
	//glColor3ub(255, 120, 0);		//upper middle
	float inc = (2 * PI / 100);
	glBegin(GL_POLYGON);

	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glColor3ub(255, 255, 0);
		glVertex2f(0.25 * r * cos(theta) + x, r *0.2 *sin(theta) + y);
		//		glVertex2f(rand() % 50 *0.25 *r * cos(theta) + x, rand() % 50 *sin(theta) + y); - water 
		for (float theta = 0.0; theta <= PI + inc; theta += inc) {
			glColor3ub(255, 120, 0);
			glVertex2f(z * cos(theta) + x, z * 5 * sin(theta) + y);
		}
	}
	glEnd();
}

void human(float x, float y, float s, float handUP) {
	float w = s;
	float h = s * 65 / 36;
	hairBack(x, y, w, h);
	body(x, y, w, h);
	clothes(x, y, w, h, handUP);
	head(x, y, w, h);
}

