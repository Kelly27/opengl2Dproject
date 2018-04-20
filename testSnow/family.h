#include <Windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\freeglut.h>
#include <math.h>			

#define PI 3.141592

void nGonCy(float x, float y, float r, float n) {
	float inc = (2 * PI) / n; //n control how round the circle is 
	glBegin(GL_POLYGON); //GL_POLYGON to fill the circle, GL_LINE_STRIP for unfilled-circle
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*cos(theta) + x, r*sin(theta) + y);
	}
	glEnd();
}


void rectangleCY(float x, float y, float w, float h) {
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y + h);
	glVertex2f(x, y + h);
	glEnd();
}



void car(float x, float y, float s) {
	//body1
	glColor3ub(0, 0, 250);
	rectangleCY(x, y, s / 2, s / 4);

	//body2
	glColor3ub(250, 0, 0);
	rectangleCY(x - s*0.25, y - s*0.2, s / 2 + s / 2, s / 4);

	//left wheel
	glColor3ub(0, 0, 0);
	nGonCy(x, y - s*0.2, 15, 50);

	//right wheel
	glColor3ub(0, 0, 0);
	nGonCy(x + s*0.5, y - s*0.2, 15, 50);
}

void background(float x, float y) {
	glColor3ub(250, 225, 0);
	rectangle(x, y, 450, 800);

	glColor3ub(252, 244, 0);
	rectangle(450, y, 850, 800);


	glColor3ub(250, 225, 0);
	rectangle(900, y, 450, 800);

}

void photoframe(float x, float y) {
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glLineWidth(10.0);
	glVertex2f(x, y);
	glVertex2f(x + 70, y + 40);
	glVertex2f(x + 140, y);
	glEnd();

	glColor3ub(145, 106, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glColor3ub(51, 37, 0);
	glVertex2f(x + 140, y);
	glVertex2f(x + 140, y - 150);
	glColor3ub(51, 37, 0);
	glVertex2f(x, y - 150);
	glEnd();

	glColor3ub(255, 251, 142);
	rectangle(x + 10, y - 140, 120, 130);

	//family photo
	//first human
	glColor3ub(2, 232, 224);
	rectangle(x + 20, y - 140, 42, 70);

	glColor3ub(0, 0, 0);
	nGonCy(x + 40, y - 50, 20, 50);

	glColor3ub(241, 247, 180);
	nGonCy(x + 40, y - 55, 17, 50);

	//second human
	glColor3ub(255, 107, 141);
	rectangle(x + 80, y - 140, 42, 70);

	glColor3ub(0, 0, 0);
	nGonCy(x + 100, y - 50, 20, 50);

	glColor3ub(241, 247, 180);
	nGonCy(x + 100, y - 55, 17, 50);

	//thrid human
	glColor3ub(255, 255, 255);
	rectangle(x + 32, y - 140, 32, 35);

	glColor3ub(0, 0, 0);
	nGonCy(x + 47, y - 90, 18, 50);

	glColor3ub(241, 247, 180);
	nGonCy(x + 47, y - 95, 15, 50);

	//forth human
	glColor3ub(255, 161, 10);
	rectangle(x + 70, y - 140, 32, 45);

	glColor3ub(0, 0, 0);
	nGonCy(x + 85, y - 80, 18, 50);

	glColor3ub(241, 247, 180);
	nGonCy(x + 85, y - 85, 15, 50);


}

void turkey(float x, float y, float r) {

	float inc = (2 * PI) / 100;

	//bone

	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex2f(x + r / 8, y + r / 7);
	glVertex2f(x + r*1.2, y + r / 3);
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

	//body
	glColor3ub(160, 82, 45);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 2 * cos(theta) + x, r / 2 * sin(theta) + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 5 * cos(theta) + x + r / 2, r / 5 * sin(theta) + y + r / 4.5);
	}
	glEnd();

	//shadowOfBody
	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	for (float theta = 4.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 2 * cos(theta) + x, r / 2 * sin(theta) + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 4.5; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 5 * cos(theta) + x + r / 2, r / 5 * sin(theta) + y + r / 4.5);
	}
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 2.3 * cos(theta) + x, r / 2.3 * sin(theta) + y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r / 5 * cos(theta) + x + r / 2.2, r / 6.11 * sin(theta) + y + r / 5);
	}
	glEnd();

	//vegetables
	glColor3ub(0, 216, 39);
	nGonCy(x - r*0.5, y - r*0.3, r / 8, r);
	glColor3ub(0, 216, 39);
	nGonCy(x - r*0.1, y - r*0.4, r / 7, r);
	glColor3ub(0, 216, 39);
	nGonCy(x + r*0.3, y - r*0.4, r / 7, r);
	glColor3ub(26, 244, 66);
	nGonCy(x - r*0.3, y - r*0.35, r / 10, r);
	glColor3ub(26, 244, 66);
	nGonCy(x + r*0.1, y - r*0.35, r / 8, r);
	glColor3ub(26, 244, 66);
	nGonCy(x + r*0.5, y - r*0.35, r / 8, r);




	//plate
	glColor3ub(255, 211, 219);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= PI + inc; theta += inc) {
		glVertex2f(-r / 1.5 * cos(theta) + x, -r / 4 * sin(theta) + y - r / 2.5);
	}
	glEnd();


}

void bulb(float x, float y) {
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	nGonCy(x, y, 7, 20);
}

void christmasTree(float x, float y, float s) {
	glColor3ub(145, 116, 13);
	rectangle(x + s*0.4, y - s*0.4, s*0.2, s*0.4);

	glColor3ub(26, 145, 13);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + s, y);
	glColor3ub(26, 145, 13);
	glVertex2f(x + s*0.5, y + s*0.5);
	glEnd();

	glColor3ub(26, 145, 13);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.1, y + s*0.3);
	glColor3ub(26, 145, 13);
	glVertex2f(x + s*0.9, y + s*0.3);
	glVertex2f(x + s*0.5, y + s*0.8);
	glEnd();

	glColor3ub(26, 145, 13);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.2, y + s*0.6);
	glColor3ub(26, 145, 13);
	glVertex2f(x + s*0.8, y + s*0.6);
	glVertex2f(x + s*0.5, y + s*1.0);
	glEnd();

	glColor3ub(26, 145, 13);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.3, y + s*0.9);
	glColor3ub(26, 145, 13);
	glVertex2f(x + s*0.7, y + s*0.9);
	glColor3ub(255, 255, 255);
	glVertex2f(x + s*0.5, y + s*1.3);
	glEnd();

	bulb(x + s*0.35, y + s);
	bulb(x + s*0.45, y + s * 0.95);
	bulb(x + s*0.55, y + s*0.95);
	bulb(x + s*0.65, y + s);

	bulb(x + s*0.35, y + s*0.6);
	bulb(x + s*0.45, y + s * 0.55);
	bulb(x + s*0.55, y + s*0.55);
	bulb(x + s*0.65, y + s*0.6);

	bulb(x + s*0.25, y + s*0.15);
	bulb(x + s*0.35, y + s*0.1);
	bulb(x + s*0.45, y + s * 0.05);
	bulb(x + s*0.55, y + s*0.05);
	bulb(x + s*0.65, y + s*0.1);
	bulb(x + s*0.75, y + s*0.15);


}

void windowFrame(float x, float y) {
	glColor3ub(91, 99, 102);
	rectangle(x, y, 100, 800);

	glColor3ub(91, 99, 102);
	rectangle(x + 1100, y, 200, 800);

	glColor3ub(91, 99, 102);
	rectangle(x, y + 700, 1200, 200);

	glColor3ub(91, 99, 102);
	rectangle(x, y, 1200, 80);


	glColor3ub(107, 114, 127);
	rectangle(x + 100, y + 80, 1000, 50);

	glColor3ub(107, 114, 127);
	rectangle(x + 100, y + 650, 1000, 50);

	glColor3ub(107, 114, 127);
	rectangle(x + 100, y + 80, 50, 600);

	glColor3ub(107, 114, 127);
	rectangle(x + 1050, y + 80, 50, 600);

}

void human1(float x, float y, float s) {
	//body
	glColor3ub(250, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + s / 3);
	glVertex2f(x + s / 9, y + s / 2);
	glVertex2f(x + s / 7, y + s / 2);
	glVertex2f(x + s / 5, y + s / 3);
	glVertex2f(x + s / 5, y - s / 4);
	glVertex2f(x, y - s / 4);
	glEnd();

	//head
	glColor3ub(255, 251, 175);
	nGonCy(x + s / 10, y + s *0.5, 30, 50);
	//hair
	glColor3ub(0, 0, 0);
	rectangle(x - s / 35, y + s*0.55, s / 4, s / 12);
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x + s *0.22, y + s*0.55);
	glVertex2f(x + s *0.22, y + s*0.45);
	glVertex2f(x - s / 85, y + s*0.55);
	glEnd();

}

void human2(float x, float y, float s) {
	//body
	glColor3ub(221, 109, 255);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + s / 3);
	glVertex2f(x + s / 9, y + s / 2);
	glVertex2f(x + s / 7, y + s / 2);
	glVertex2f(x + s / 5, y + s / 3);
	glVertex2f(x + s / 5, y - s / 4);
	glVertex2f(x, y - s / 4);
	glEnd();

	//head
	glColor3ub(255, 251, 175);
	nGonCy(x + s / 10, y + s *0.5, 30, 50);
	//hair
	glColor3ub(0, 0, 0);
	rectangle(x - s / 35, y + s*0.55, s / 4, s / 12);
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x - s / 35, y + s*0.55);
	glVertex2f(x - s / 35, y + s*0.45);
	glVertex2f(x + s / 45, y + s*0.55);
	glEnd();

}

void bookrack(float x, float y, float s) {

	glColor3ub(130, 71, 0);
	rectangle(x + s / 10, y + s, s * 8, s * 9);

	glColor3ub(255, 135, 15);
	rectangle(x, y, s, s * 10);

	glColor3ub(255, 135, 15);
	rectangle(x + 300, y, s, s * 10);

	glColor3ub(255, 135, 15);
	rectangle(x, y + s * 10, s*8.5, s *0.5);

	glColor3ub(255, 135, 15);
	rectangle(x, y + s * 7, s*8.5, s);

	glColor3ub(255, 135, 15);
	rectangle(x, y + s * 4, s*8.5, s);

	glColor3ub(255, 135, 15);
	rectangle(x, y, s*8.5, s * 2);



	//books
	//first row
	glColor3ub(37, 29, 196);
	rectangle(x + s*2.6, y + s * 8, s*0.7, s*1.5);
	glColor3ub(255, 104, 252);
	rectangle(x + s*3.4, y + s * 8, s*0.6, s*1.5);
	glColor3ub(249, 255, 104);
	rectangle(x + s*4.1, y + s * 8, s*0.7, s*1.6);
	glColor3ub(104, 142, 255);
	rectangle(x + s*4.9, y + s * 8, s*0.6, s*1.7);
	glColor3ub(104, 255, 104);
	rectangle(x + s*5.6, y + s * 8, s*0.6, s*1.6);

	//second row
	glColor3ub(155, 242, 239);
	rectangle(x + s * 2, y + s * 5, s*0.6, s*1.5);
	glColor3ub(255, 143, 137);
	rectangle(x + s*2.7, y + s * 5, s*0.5, s*1.6);
	glColor3ub(167, 249, 178);
	rectangle(x + s * 3.6, y + s * 5, s*0.5, s*1.6);
	glColor3ub(167, 182, 249);
	rectangle(x + s * 4.2, y + s * 5, s*0.6, s*1.7);
}

void kid1(float x, float y, float s) {
	//body
	glColor3ub(8, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + s / 4);
	glVertex2f(x + s / 10, y + s / 2);
	glVertex2f(x + s / 6, y + s / 3);
	glVertex2f(x + s / 6, y + s / 3);
	glVertex2f(x + s / 4, y - s / 3);
	glVertex2f(x, y - s / 3);
	glEnd();

	//head
	glColor3ub(255, 251, 175);
	nGonCy(x + s / 10, y + s *0.5, 30, 50);
	//hair
	glColor3ub(0, 0, 0);
	rectangle(x - s / 35, y + s*0.55, s / 4, s / 12);
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x - s / 35, y + s*0.55);
	glVertex2f(x - s / 35, y + s*0.45);
	glVertex2f(x + s / 45, y + s*0.55);
	glEnd();
}

void kid2(float x, float y, float s) {
	//body
	glColor3ub(255, 0, 144);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + s / 3);
	glVertex2f(x + s / 9, y + s / 2);
	glVertex2f(x + s / 7, y + s / 2);
	glVertex2f(x + s / 5, y + s / 3);
	glVertex2f(x + s / 5, y - s / 4);
	glVertex2f(x, y - s / 4);
	glEnd();

	//head
	glColor3ub(255, 251, 175);
	nGonCy(x + s / 10, y + s *0.5, 30, 50);
	//hair
	glColor3ub(0, 0, 0);
	rectangle(x - s / 35, y + s*0.55, s / 4, s / 12);
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x + s *0.22, y + s*0.55);
	glVertex2f(x + s *0.22, y + s*0.45);
	glVertex2f(x - s / 85, y + s*0.55);
	glEnd();


}

void table(float x, float y, float s) {
	glColor3ub(186, 141, 20);
	glBegin(GL_POLYGON);
	glVertex2f(x - s / 6, y + s *0.4); //a
	glVertex2f(x + s + s / 6, y + s *0.4); //b
	glVertex2f(x + s, y + s*0.7); //c 
	glVertex2f(x, y + s*0.7);//d
	glEnd();

	//table leg
	glColor3ub(186, 141, 20);
	rectangle(x - s / 6.5, y, s*0.1, s*0.4);
	glColor3ub(186, 141, 20);
	rectangle(x + s + s*0.05, y, s*0.1, s*0.4);
	glColor3ub(186, 141, 20);
	rectangle(x + s *0.05, y + s*0.2, s*0.1, s*0.4);
	glColor3ub(186, 141, 20);
	rectangle(x + s *0.85, y + s*0.2, s*0.1, s*0.4);

	glColor3ub(186, 141, 20);
	rectangle(x - s / 6, y + s*0.36, s + s*0.335, 17);



	//food
	glColor3ub(6, 8, 38);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.14, y + s *0.55); //a
	glVertex2f(x + s*0.36, y + s *0.55); //b
	glVertex2f(x + s*0.37, y + s*0.5); //c 
	glVertex2f(x + s*0.13, y + s*0.5);// d
	glEnd();

	glColor3ub(255, 20, 20);
	nGonCy(x + s *0.25, y + s *0.56, 10, 50);

	glColor3ub(6, 8, 38);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.64, y + s *0.55); //a
	glVertex2f(x + s*0.86, y + s *0.55); //b
	glVertex2f(x + s*0.87, y + s*0.5); //c 
	glVertex2f(x + s*0.65, y + s*0.5);// d
	glEnd();

	glColor3ub(255, 20, 20);
	nGonCy(x + s *0.75, y + s *0.56, 10, 50);

	glColor3ub(6, 8, 38);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.14, y + s *0.75); //a
	glVertex2f(x + s*0.36, y + s *0.75); //b
	glVertex2f(x + s*0.37, y + s*0.7); //c 
	glVertex2f(x + s*0.13, y + s*0.7);// d
	glEnd();

	glColor3ub(255, 20, 20);
	nGonCy(x + s *0.25, y + s *0.76, 10, 50);

	glColor3ub(6, 8, 38);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.64, y + s *0.75); //a
	glVertex2f(x + s*0.86, y + s *0.75); //b
	glVertex2f(x + s*0.87, y + s*0.7); //c 
	glVertex2f(x + s*0.65, y + s*0.7);// d
	glEnd();

	glColor3ub(255, 20, 20);
	nGonCy(x + s *0.75, y + s *0.76, 10, 50);


	//plates
	glColor3ub(249, 248, 172);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.1, y + s *0.5); //a
	glVertex2f(x + s*0.4, y + s *0.5); //b
	glVertex2f(x + s*0.36, y + s*0.45); //c 
	glVertex2f(x + s*0.14, y + s*0.45);//d
	glEnd();

	glColor3ub(249, 248, 172);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.6, y + s *0.5); //a
	glVertex2f(x + s*0.9, y + s *0.5); //b
	glVertex2f(x + s*0.86, y + s*0.45); //c 
	glVertex2f(x + s*0.64, y + s*0.45);//d
	glEnd();

	glColor3ub(249, 248, 172);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.6, y + s *0.7); //a
	glVertex2f(x + s*0.9, y + s *0.7); //b
	glVertex2f(x + s*0.86, y + s*0.65); //c 
	glVertex2f(x + s*0.64, y + s*0.65);//d
	glEnd();

	glColor3ub(249, 248, 172);
	glBegin(GL_POLYGON);
	glVertex2f(x + s*0.1, y + s *0.7); //a
	glVertex2f(x + s*0.4, y + s *0.7); //b
	glVertex2f(x + s*0.36, y + s*0.65); //c 
	glVertex2f(x + s*0.14, y + s*0.65);//d
	glEnd();

	turkey(x + s * 0.5, y + s*0.68, 80);
}
void family() {
	background(0, 0);
	photoframe(500, 500);
	bookrack(0, 200, 40);
	car(220, 435, 90);
	christmasTree(650, 350, 250);
	human2(370, 240, 250);
	human1(880, 240, 250);
	kid1(375, 150, 250);
	kid2(870, 150, 250);
	table(450, 10, 400);
	toy(250, 310, 30, 100);
	windowFrame(0, 0);
}