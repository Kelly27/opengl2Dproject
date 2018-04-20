#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\freeglut.h>

void nGonT(int x, int y, int r, int n) {
	float inc = (2 * PI) / n;
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2f(x + r*cos(theta), y + r*sin(theta));
	}
	glEnd();
}

//toy
void toy(float x, float y, float w, float h) {
	//body
	glColor3ub(255, 255, 255);
	nGonT(x, y, w, h);

	//leftFur1
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x - w/1.11, y - w/3.3);
	glVertex2f(x - w, y - w);
	glVertex2f(x - w/2.22, y - w/1.11);
	glEnd();

	//leftFur2
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x - w, y);
	glVertex2f(x - w/0.8, y - w/1.4);
	glVertex2f(x - w/1.5, y - w/1.67);
	glEnd();

	//leftFur3
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x - w/1.11, y + w/3.3);
	glVertex2f(x - w/0.77, y - w/2.5);
	glVertex2f(x - w/1.3, y - w/2.5);
	glEnd();

	//rightFur1
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x + w/1.11, y - w/3.3);
	glVertex2f(x + w, y - w);
	glVertex2f(x + w/2.22, y - w/1.11);
	glEnd();

	//rightFur2
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x + w, y);
	glVertex2f(x + w/0.83, y - w/1.43);
	glVertex2f(x + w/1.54, y - w/1.67);
	glEnd();

	//rightFur3
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x + w/1.11, y + w/3.3);
	glVertex2f(x + w/0.77, y - w/2.5);
	glVertex2f(x + w/1.33, y - w/3.3);
	glEnd();

	//ButtomFur
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x + w/1.43, y - w/0.95);
	glVertex2f(x + w/10, y - w);
	glVertex2f(x, y - w/1.42);
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x - w/1.42, y - w/0.95);
	glVertex2f(x - w/10, y - w);
	glVertex2f(x, y - w/1.42);
	glEnd();


	//antenna1
	glColor3ub(220, 20, 60);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x, y + w/1.11);
	glVertex2f(x - w/3.33, y + w/1.11);
	glVertex2f(x - w/2.5, y + w/0.67);
	glEnd();

	//antenna2
	glColor3ub(220, 20, 60);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x, y + w/1.12);
	glVertex2f(x + w/3.3, y + w/1.11);
	glVertex2f(x + w/2.5, y + w/0.67);
	glEnd();

	//antenna circle
	glColor3ub(220, 20, 60);
	nGonT(x, y + w/1.05, 10, 10);


	//eye1
	glColor3ub(0, 0, 0);
	nGonT(x - w/2.5, y, w/5, 10);
	glColor3ub(255, 255, 255);
	nGonT(x - w/2.9, y + w/20, w/14, 10);

	//eye2
	glColor3ub(0, 0, 0);
	nGonT(x + w/2.5, y, w / 5, 10);
	glColor3ub(255, 255, 255);
	nGonT(x + w/2.5, y + w/20, w / 14, 10);

	//mouth
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	float inc = (2 * PI) / 100;
	for (float theta = 3.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(w/10 * cos(theta) + x - w/10, w/10 * sin(theta) + y - w/3.3);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (float theta = 3.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(w/10 * cos(theta) + x + w/10, w/10 * sin(theta) + y - w/3.3);
	}
	glEnd();

}

//Thinking in mind - cloud
void cloud(float x, float y, float r) {
	float inc = (2 * PI) / 100;

	glColor3ub(101, 198, 235);

	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r * cos(theta) + x, r * 0.6 * sin(theta) + y - 45);
	}
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r * cos(theta) + x + 150, r * 0.6 * sin(theta) + y - 45);
	}
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r * cos(theta) + x + 120, r * 0.6 * sin(theta) + y);
	}
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r * cos(theta) + x + 150, r * 0.6 * sin(theta) + y - 100);
	}
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r * cos(theta) + x + 50, r * 0.6 * sin(theta) + y - 100);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*0.4 * cos(theta) + x+20, r * 0.35 * sin(theta) + y - 200);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*0.3 * cos(theta) + x - 20, r * 0.25 * sin(theta) + y - 260);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*0.2 * cos(theta) + x - 40, r * 0.15 * sin(theta) + y - 300);
	}
	glEnd();
}
void bone(float x, float y, float r) {
	float inc = (2 * PI) / 100;
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex2f(x + r / 2, y+ r /7 );
	glVertex2f(x + r*1.2, y +r/3);
	glVertex2f(x + r*1.2, y + r / 2);
	glVertex2f(x + r / 2, y + r / 3);
	glEnd();

	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 9 * cos(theta) + x + r*1.1, r / 9 * sin(theta) + y + r *.5);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 9 * cos(theta) + x + r*1.2, r / 9 * sin(theta) + y + r *.35);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 9 * cos(theta) + x + r*1.1, r / 9 * sin(theta) + y + r*.25);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 9 * cos(theta) + x + r/2, r / 9 * sin(theta) + y + r*.4);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 9 * cos(theta) + x + r / 2.5, r / 9 * sin(theta) + y + r*.3);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 9 * cos(theta) + x + r / 2, r / 9 * sin(theta) + y + r*.15);
	}
	glEnd();
}
void heart(float x, float y, float s) {
	glColor3ub(255, 0, 0);
	nGonT(x - (s * 0.9), y + s, s, 50);
	nGonT(x + (s * 0.9), y + s, s, 50);
	glBegin(GL_POLYGON);
	glVertex2f(x - (s * 1.5), y + (s * 0.5));
	glVertex2f(x + (s * 1.5), y + (s * 0.5));
	glVertex2f(x, y - (s * 1.5));
	glEnd();

}
void smallhouse(int x, int y, int size) {

	//draw main body
	glColor3ub(255, 211, 144);
	rectangle(x, y, size, size*0.5);

	//draw door
	int doorsize = size / 5;
	glColor3ub(105, 36, 36);
	rectangle(x + size / 2 - doorsize / 2, y, doorsize, doorsize*1.5);

	//draw windows
	glColor3ub(80, 151, 249);
	rectangle(x + doorsize / 2, y + doorsize, doorsize, doorsize);

	glColor3ub(80, 151, 249);
	rectangle(x + size - doorsize*1.5, y + doorsize, doorsize, doorsize);

	//draw roof
	glColor3ub(255, 8, 45);
	glBegin(GL_POLYGON);
	glVertex2i(x - doorsize / 2, y + size*0.5);
	glVertex2i(x + size + doorsize / 2, y + size*0.5);
	glVertex2i(x + size, y + size*0.5 + doorsize*1.5);
	glVertex2i(x, y + size*0.5 + doorsize*1.5);
	glVertex2i(x - doorsize / 2, y + size*0.5);
	glEnd();

	//draw chimney
	glColor3ub(78, 79, 79);
	rectangle(x + doorsize / 2, y + size*0.5 + doorsize*1.5, doorsize / 2, doorsize);

}
void basket(float x, float y, float s) {
	glColor3ub(247, 179, 96);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + s, y);
	glVertex2f(x + s*0.9, y - s*0.5);
	glVertex2f(x + s*0.1, y - s*0.5);
	glEnd();

	glColor3ub(247, 179, 96);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x, y);
	glVertex2f(x + s*0.05, y + s*0.3);
	glVertex2f(x + s*0.95, y + s*0.3);
	glVertex2f(x + s, y);
	glEnd();
	glColor3ub(247, 179, 96);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x, y);
	glVertex2f(x + s*0.1, y + s*0.2);
	glVertex2f(x + s*0.9, y + s*0.2);
	glVertex2f(x + s, y);
	glEnd();

	glColor3ub(237, 154, 54);
	float n = y;
	for (int j = 0; j < 4; j++) {
		float m = x;
		for (int i = 0; i < 4; i++) {
			rectangle(m + s*0.1, n - s*0.1, s*0.15, s*0.05);
			m += s*0.22;
		}
		n -= s * 0.1;
	}
}