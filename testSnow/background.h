#include <Windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\freeglut.h>
#include <math.h>


#define screenWidth		1366
#define screenHeight	768

void nGonB(float x, float y, float r, float n) {
	float inc = (2 * PI / n);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*cos(theta) + x, r*sin(theta) + y);
	}
	glEnd();
}
void rectangleC(float x, float y, float w, float h) {
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y + h);
	glVertex2f(x, y + h);
	glEnd();
}
void rectangleB(float x, float y, float w, float h) {
	glBegin(GL_POLYGON);
	glVertex2f(x + 25, y);            //add 25 for the edge of the roof
	glVertex2f(x + 25 + w, y);
	glVertex2f(x + 25 + w, y + h);
	glVertex2f(x + 25, y + h);
	glEnd();
}
void triangle(float x, float y, float w, float h) {
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y + 300);                 //add 300 to move the triangle above the body [200(house)*1.5(house height = 300)]
	glVertex2f(x + w + 50, y + 300);        //add 50, both side have extra 25 for the edge of the roof
	glVertex2f(x + w / 2 + 25, y + h);    //x + half of the width(w/2) + extra 50/2=25
	glEnd();
}
void rectangleW(float x, float y, float w, float h) {
	glBegin(GL_POLYGON);
	glVertex2f(x + 50, y + 100);
	glVertex2f(x + 100, y + 100);
	glVertex2f(x + 100, y + 150);
	glVertex2f(x + 50, y + 150);
	glEnd();
}
void house(float x, float y, float s) {
	//half Building Body
	glColor3ub(91, 87, 88);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + 25, y);
	glVertex2f(x + 25, y + s*1.25);
	glVertex2f(x, y + s*1.25);
	glEnd();

	//1st Building Body
	glColor3ub(82, 104, 109);
	rectangleB(x, y, s, s*1.5);
	//1st Building Roof
	glColor3ub(50, 65, 68);
	triangle(x, y, s, s*2.25);
	//2nd Building Body
	glColor3ub(104, 145, 155);
	rectangleB(x + s, y, s, s);

	//3th Building Body
	glColor3ub(91, 99, 102);
	rectangleB(x + 2 * s, y, s, s*1.5);
	//4th Building Body
	glColor3ub(110, 124, 127);
	rectangleB(x + 3 * s, y, s, s*1.5);

	//5th Building Body
	glColor3ub(95, 121, 127);
	rectangleB(x + 4 * s, y, s, s);

	//6th Building Body
	glColor3ub(67, 86, 91);
	rectangleB(x + 5 * s, y, s, s*1.5);
	//6th Building Roof
	glColor3ub(80, 105, 112);
	triangle(x + 5 * s, y, s, s*2.25);

	//half Building Body
	glBegin(GL_POLYGON);
	glVertex2f(x + 6 * s + 25, y);
	glVertex2f(x + 7 * s, y);
	glVertex2f(x + 7 * s, y + s*1.25);
	glVertex2f(x + 6 * s + 25, y + s*1.25);
	glEnd();
	//1st Building Windows
	glColor3ub(255, 255, 0); rectangleW(x, y, s, s);    //windows size is 50x50
	glColor3ub(255, 255, 0); rectangleW(x, y + 75, s, s); //space between window(column)is 25
	glColor3ub(255, 255, 0); rectangleW(x, y + 75 * 2, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 100, y, s, s);    //space between window(row)is 10
	glColor3ub(255, 255, 0); rectangleW(x + 100, y, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 100, y + 75, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 100, y + 75 * 2, s, s);
	//2nd Building Windows
	glColor3ub(255, 255, 0); rectangleW(x + 200, y, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 200 + 100, y, s, s);
	//3th Building Windows
	glColor3ub(255, 255, 0); rectangleW(x + 400, y, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 400, y + 75, s, s);   //lower part
	glColor3ub(255, 165, 0); rectangleW(x + 400, y + 100, s, s);//upper part
	glColor3ub(255, 255, 0); rectangleW(x + 500, y, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 500, y + 75, s, s); //lower part
	glColor3ub(255, 165, 0); rectangleW(x + 500, y + 100, s, s);//upper part
																//4th Building Windows
	glColor3ub(255, 255, 0); rectangleW(x + 600, y, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 600, y + 75, s, s); //lower part
	glColor3ub(255, 165, 0); rectangleW(x + 600, y + 100, s, s);//upper part
	glColor3ub(255, 255, 0); rectangleW(x + 700, y, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 700, y + 75, s, s); //lower part
	glColor3ub(255, 165, 0); rectangleW(x + 700, y + 100, s, s);//upper part
																//5th Building Windows
	glColor3ub(255, 255, 0); rectangleW(x + 800, y, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 800 + 100, y, s, s);
	//6th Building Windows
	glColor3ub(255, 255, 0); rectangleW(x + 1000, y, s, s); //windows size is 50x50
	glColor3ub(255, 255, 0); rectangleW(x + 1000, y + 75, s, s); //space between window(column)is 25
	glColor3ub(255, 255, 0); rectangleW(x + 1000, y + 75 * 2, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 1000 + 100, y, s, s); //space between window(row)is 100
	glColor3ub(255, 255, 0); rectangleW(x + 1000 + 100, y, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 1000 + 100, y + 75, s, s);
	glColor3ub(255, 255, 0); rectangleW(x + 1000 + 100, y + 75 * 2, s, s);
}
void road(float x, float y, float w, float h) {
	glColor3ub(0, 0, 0);
	rectangle(x, y, w, h);
}
//void cat(float x, float y, float s) {
//	//ears
//	glColor3ub(244, 164, 96);
//	glBegin(GL_POINTS);
//	glVertex2f(x - s / 3 + 60, y - 50 + s*0.75);
//	glVertex2f(x + s / 3 - 30, y - 50 + s*0.75);
//	glEnd();
//	//tail
//	glColor3ub(244, 164, 96);
//	glBegin(GL_LINE_STRIP);
//	glVertex2f(x + 40, y - 38);
//	glVertex2f(x + 50, y - 32);
//	glVertex2f(x + 52, y - 28);
//	glVertex2f(x + 53, y - 26);
//	glVertex2f(x + 55, y - 25);
//	glVertex2f(x + 60, y - 23);
//	glVertex2f(x + 58, y - 35);
//	glVertex2f(x + 64, y - 24);
//	glVertex2f(x + 54, y - 50);
//	glVertex2f(x + 50, y - 48);
//	glVertex2f(x + 52, y - 40);
//	glVertex2f(x + 55, y - 25);
//	glVertex2f(x + 60, y - 23);
//	glVertex2f(x + 65, y - 20);
//	glVertex2f(x + 69, y - 25);
//	glVertex2f(x + 72, y - 40);
//	glVertex2f(x + 73, y - 35);
//	glVertex2f(x + 72, y - 33);
//	glVertex2f(x + 70, y - 30);
//	glVertex2f(x + 75, y - 35);
//	glVertex2f(x + 80, y - 38);
//	glVertex2f(x + 85, y - 10);
//	glEnd();
//	//head
//	glColor3ub(139, 69, 19);
//	nGonB(x + 15, y, s / 4, 50);
//	//body
//	glColor3ub(139, 69, 19);
//	nGonB(x + 15, y - 40, s / 3, 40);
//}
void light(float x, float y, float s) {
	//bulb
	glColor3ub(243, 243, 227);
	nGonB(x + 203, y + 26 + s / 6 + s*2.5, s / 7, 30);
	nGonB(x + 29, y + 26 + s / 6 + s*2.5, s / 7, 30);
	glColor3ub(255, 255, 102);
	nGonB(x + 203, y + 26 + s / 6 + s*2.5, s / 9, 30); //r
	nGonB(x + 29, y + 26 + s / 6 + s*2.5, s / 9, 30); //l

													 //stem
	glColor3ub(224, 224, 224);
	rectangleC(x + 109, y + 40 + s / 6, s / 9, s*2.5);
	nGonB(x + 115, y + 40 + s / 6 + s*2.5, s / 9, 30);
	rectangleC(x + 114, y + 28 + s / 6 + s*2.5, s, s / 10); //right
														   //glColor3ub(255,255,255);
	rectangleC(x + 18, y + 28 + s / 6 + s*2.5, s, s / 10); //left
														  //bottom
	glColor3ub(96, 96, 96);
	rectangleC(x + 103, y + 40 + s / 6, s / 4, s / 6);
}
void christmastree(float x, float y, float s) {
	//leaves
	glBegin(GL_POLYGON);
	glColor3ub(77, 158, 58);
	glVertex2f(x + 895, y + 70);
	glColor3ub(55, 139, 41);
	glVertex2f(x + 1050, y + 70);
	glColor3ub(116, 214, 128);
	glVertex2f(x + 965, y + 210);
	glEnd();
	glColor3ub(255, 255, rand()%255);
	nGonB(x + 950, y + 165, s / 22, 50);
	nGonB(x + 965, y + 161, s / 22, 50);
	nGonB(x + 980, y + 157, s / 22, 50);
	nGonB(x + 995, y + 152, s / 22, 50);
	nGonB(x + 925, y + 95, s / 22, 50);
	nGonB(x + 940, y + 100, s / 22, 50);
	nGonB(x + 965, y + 105, s / 22, 50);
	nGonB(x + 980, y + 110, s / 22, 50);
	nGonB(x + 995, y + 115, s / 22, 50);
	nGonB(x + 1012, y + 122, s / 22, 50);
	//stem
	glColor3ub(102, 51, 0);
	rectangleC(x + 950, y + 40 + s / 6, s*0.4, s*0.2);
	//snow
	glColor3ub(255, 255, 255);
	nGonB(x + 968, y + 23, s / 8, 30);
	nGonB(x + 995, y + 23, s / 6, 30);
	nGonB(x + 975, y + 23, s / 7, 30);
	nGonB(x + 960, y + 40, s / 4, 30);
	nGonB(x + 945, y + 135, s / 10, 30);
	nGonB(x + 960, y + 135, s / 8, 30);
	nGonB(x + 975, y + 135, s / 10, 30);
	//nGonB(x+960,y-68+s/6,s/6,30);

	glColor3ub(0, 0, 0);
	rectangleC(x + 880, y + 20, s * 5, s*0.35);
}
void christmastree1(float x, float y, float s) {
	//stem
	glColor3ub(102, 51, 0);
	rectangleC(x + 453, y - 70, s*0.4, s*0.2);
	//leaves
	glColor3ub(77, 158, 58);
	glBegin(GL_POLYGON);
	glColor3ub(116, 214, 128);
	glVertex2f(x + 395, y - 55);
	glColor3ub(55, 139, 41);
	glVertex2f(x + 550, y - 55);
	glColor3ub(77, 158, 58);
	glVertex2f(x + 465, y + 25);
	glEnd();
	glColor3ub(255, 255, 0);
	//snow
	glColor3ub(255, 255, 255);
	nGonB(x + 450, y, s / 12, 30);
	nGonB(x + 465, y, s / 11, 30);
	nGonB(x + 475, y, s / 12, 30);
	nGonB(x + 485, y - 25, s / 12, 30);
	nGonB(x + 500, y - 25, s / 11, 30);
	nGonB(x + 493, y - 25, s / 12, 30);
	glColor3ub(0, 0, 0);
	rectangleC(x + 920, y + 5, s * 4, s*0.3);
}
void fountain(float x, float y, float s) {
	//stem
	glColor3ub(204, 229, 255);
	rectangle(x + 995, y - 70, s*0.3, s*0.6);
	//bottom
	glColor3ub(25, 25, 12);
	rectangle(x + 984, y - 70, s / 2, s / 6);
	//bowl
	glColor3ub(204, 229, 255);
	nGonB(x + 1010, y + 15, s*0.5, 30);
	glColor3ub(0, 0, 0);
	rectangle(x + 945, y + 5, 150, 50);


	//water
	glColor3ub(54, 231, 237);
	rectangle(x + 1000, y + 5, 20, 55);

	glColor3ub(0, 0, rand() % 255 + 188);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, rand() % 255 + 188);
	glVertex2f(x + 990, y + 80);
	glColor3ub(0, 0, rand() % 255 + 188);
	glVertex2f(x + 1030, y + 80);
	glColor3ub(173, 255, 248);
	glVertex2f(x + 1040, y + 60);
	glColor3ub(173, 255, 248);
	glVertex2f(x + 980, y + 60);
	glEnd();

	glColor3ub(0, 188, 172);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, rand() % 255 + 188);
	glVertex2f(x + 980, y + 50);
	glColor3ub(0, 0, rand() % 255 + 188);
	glVertex2f(x + 1040, y + 50);
	glColor3ub(173, 255, 248);
	glVertex2f(x + 1060, y + 20);
	glColor3ub(173, 255, 248);
	glVertex2f(x + 960, y + 20);
	glEnd();

}
void extinguisher(float x, float y, float s) {
	//top
	glColor3ub(178, 34, 34);

	nGonB(x + 350, y + 155, s / 4, 30);
	/*glColor3ub(105,105,105);
	rectangleC(x+300,y+89,100,50);*/
	//body
	glColor3ub(178, 34, 34);
	rectangleC(x + 323, y + 75, 55, 70);
	glColor3ub(139, 0, 0);
	rectangleC(x + 310, y + 145, 80, 15);
	nGonB(x + 350, y + 120, s / 6, 30);
	//bottom
	glColor3ub(139, 0, 0);
	rectangleC(x + 310, y + 40 + s / 6, s*0.8, s*0.2);
	//sides
	glColor3ub(139, 0, 0);
	rectangleC(x + 308, y + 105, 15, 20);
	rectangleC(x + 378, y + 105, 15, 20);
}
void bench(float x, float y, float s) {
	//legs
	glColor3ub(51, 25, 0);
	rectangleC(x - 15, y + 135, s / 8, s*0.6);
	rectangleC(x + 52, y + 135, s / 8, s*0.6);
	rectangleC(x - 50, y + 40 + s / 6, s / 8, s*0.4);
	rectangleC(x - 30, y + 40 + s / 6, s / 8, s*0.4);
	rectangleC(x + 86, y + 40 + s / 6, s / 8, s*0.4);
	rectangleC(x + 66, y + 40 + s / 6, s / 8, s*0.4);
	//back
	glColor3ub(255, 160, 122);
	rectangleC(x - 35, y + 150, s*1.2, s / 8);
	rectangleC(x - 35, y + 165, s*1.2, s / 8);
	rectangleC(x - 35, y + 185, s*1.2, s / 8);

	glColor3ub(0, 0, 0);
	nGonB(x - 9, y + 155, s / 30, 50);
	nGonB(x + 59, y + 155, s / 30, 50);
	nGonB(x - 9, y + 170, s / 30, 50);
	nGonB(x + 59, y + 170, s / 30, 50);
	nGonB(x - 9, y + 190, s / 30, 50);
	nGonB(x + 59, y + 190, s / 30, 50);

	//sit
	glColor3ub(255, 127, 80);
	glBegin(GL_QUADS);
	glVertex2f(x - 35, y + 135);
	glVertex2f(x + 84, y + 135);
	glVertex2f(x + 98, y + 95);
	glVertex2f(x - 50, y + 95);
	glEnd();
}
void sky(float x, float y, float s) {
	glBegin(GL_QUADS);
	glColor3ub(27, 126, 166);
	glVertex2f(x - 100, y + 150);
	glColor3ub(27, 126, 166);
	glVertex2f(x + 1300, y + 150);
	glColor3ub(11, 26, 38);
	glVertex2f(x + 1250, y + 800);
	glColor3ub(11, 26, 38);
	glVertex2f(x - 100, y + 800);
	glEnd();
	glColor3ub(255, 255, 255);
	rectangleC(x - 100, y + 61, screenWidth, s*0.5);
	rectangleC(x - 100, y - 100, screenWidth, s*0.7);
}
void moon(float x, float y) {
	float inc = (2 * PI / 100);
	glBegin(GL_POLYGON);

	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glColor3ub(255, 255, 255);
		glVertex2f(40 * cos(theta) + x, 40 * sin(theta) + y);

		//for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glColor3ub(128, 128, 128);
		glVertex2f(30 * cos(theta) + x, 30 * sin(theta) + y);
	}
	glEnd();
}
void star(int xstar, int ystar, int sstar) {

	glLineWidth(1.0);
	glBegin(GL_LINES);
	glColor3ub(255, 255, rand() % 255);
	glVertex2f(xstar, ystar);
	glVertex2f(xstar, ystar - sstar*0.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(255, 255, rand()%255);
	glVertex2f(xstar - sstar*0.25, ystar - sstar*0.25);
	glVertex2f(xstar + sstar*0.25, ystar - sstar*0.25);
	glEnd();

}
void fire(float x, float y, float r, float z) {
	//glColor3ub(255, 120, 0);		//upper middle
	float inc = (2 * PI / 100);
	glBegin(GL_POLYGON);

	for (float theta = 0.0; theta <= PI + inc; theta += inc) {
		glColor3ub(255, 255, 0);
		glVertex2f(rand() % 50 * 0.25 *r * cos(theta) + x, rand() % 50 * r *0.2 *sin(theta) + y);
		//		glVertex2f(rand() % 50 *0.25 *r * cos(theta) + x, rand() % 50 *sin(theta) + y); - water 
		//for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glColor3ub(255, 120, 0);
		glVertex2f(z * cos(theta) + x, z * sin(theta) + y);
	}
	glEnd();
}
//snowman's bottom - to show bottom first
void snowmanbottom(float x, float y, float r) {
	//bottom
	float inct = (2 * PI / 100);
	glBegin(GL_POLYGON);

	for (float theta = 0.0; theta <= 2 * PI + inct; theta += inct) {
		glColor3ub(175, 238, 238);
		glVertex2f(r *1.5* cos(theta) + x + 80, r*1.5 * sin(theta) + y - 50);
		//		glVertex2f(rand() % 50 *0.25 *r * cos(theta) + x, rand() % 50 *sin(theta) + y); - water 
		for (float theta = 0.0; theta <= 2 * PI + inct; theta += inct) {
			glColor3ub(255, 255, 255);
			glVertex2f(r *1.5*cos(theta) + x + 80, r *1.5* sin(theta) + y - 50);
		}
	}
	glEnd();
}
void snowman(float x, float y, float r) {
	//bottom
	float inct = (2 * PI / 100);
	glBegin(GL_POLYGON);

	for (float theta = 0.0; theta <= 2 * PI + inct; theta += inct) {
		glColor3ub(175, 238, 238);
		glVertex2f(r *1.5* cos(theta) + x + 80, r*1.5 * sin(theta) + y - 50);
		//		glVertex2f(rand() % 50 *0.25 *r * cos(theta) + x, rand() % 50 *sin(theta) + y); - water 
		for (float theta = 0.0; theta <= 2 * PI + inct; theta += inct) {
			glColor3ub(255, 255, 255);
			glVertex2f(r *1.5*cos(theta) + x + 80, r *1.5* sin(theta) + y - 50);
		}
	}
	glEnd();

	//top
	inct = (2 * PI / 100);
	glBegin(GL_POLYGON);

	for (float theta = 0.0; theta <= 2 * PI + inct; theta += inct) {
		glColor3ub(175, 238, 238);
		glVertex2f(r * cos(theta) + x + 80, r * sin(theta) + y);
		//		glVertex2f(rand() % 50 *0.25 *r * cos(theta) + x, rand() % 50 *sin(theta) + y); - water 
		for (float theta = 0.0; theta <= 2 * PI + inct; theta += inct) {
			glColor3ub(255, 255, 255);
			glVertex2f(r * cos(theta) + x + 80, r * sin(theta) + y);
		}
	}
	glEnd();

	//scarf
	glColor3ub(0, 0, 205);
	glBegin(GL_POLYGON);
	glVertex2f(x + 55, y - 25);
	glVertex2f(x + 105, y - 25);
	glVertex2f(x + 105, y - 15);
	glVertex2f(x + 55, y - 15);
	glEnd();

	//nose
	glColor3ub(255, 69, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x + 60, y);
	glVertex2f(x + 80, y);
	glVertex2f(x + 80, y + 5);
	glEnd();

	//eyes
	glColor3ub(0, 0, 0);
	float inc = (2 * PI / 10);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*.15*cos(theta) + 130, r*.15*sin(theta) + 100);
	}
	glEnd();

	glColor3ub(0, 0, 0);
	inc = (2 * PI / 10);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*.15*cos(theta) + 140, r*.15*sin(theta) + 100);
	}
	glEnd();

	//hat
	glColor3ub(0, 0, 205);
	glBegin(GL_TRIANGLES);
	glVertex2f(x + 65, y + 20);
	glVertex2f(x + 95, y + 20);
	glVertex2f(x + 90, y + 50);
	glEnd();

	//hat fur
	glColor3ub(0, 191, 255);
	inc = (2 * PI / 10);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*.15*cos(theta) + 150, r*.15*sin(theta) + 140);
	}
	glEnd();

	//righthand
	glColor3ub(160, 82, 45);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 100, y - 40);
	glVertex2f(x + 130, y - 20);
	glVertex2f(x + 140, y - 25);
	glVertex2f(x + 130, y - 20);
	glVertex2f(x + 140, y - 15);
	glVertex2f(x + 130, y - 20);
	glVertex2f(x + 135, y - 5);
	glEnd();

	//lefthand
	glColor3ub(160, 82, 45);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 50, y - 40);
	glVertex2f(x + 30, y - 20);
	glVertex2f(x + 20, y - 25);
	glVertex2f(x + 30, y - 20);
	glVertex2f(x + 20, y - 15);
	glVertex2f(x + 30, y - 20);
	glVertex2f(x + 35, y - 5);
	glEnd();

	//buttons
	glColor3ub(0, 0, 0);
	inc = (2 * PI / 10);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*.2*cos(theta) + 130, r*.2*sin(theta) + 50);
	}
	glEnd();

	glColor3ub(0, 0, 0);
	inc = (2 * PI / 10);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*.2*cos(theta) + 130, r*.2*sin(theta) + 30);
	}
	glEnd();
}

void child1(float x, float y, float r) {
	//Snow ball
	float inct = (2 * PI / 100);
	glBegin(GL_POLYGON);

	for (float theta = 0.0; theta <= 2 * PI + inct; theta += inct) {
		glColor3ub(175, 238, 238);
		glVertex2f(r *1.5* cos(theta) + x + 40, r*1.5 * sin(theta) + y - 30);
		//		glVertex2f(rand() % 50 *0.25 *r * cos(theta) + x, rand() % 50 *sin(theta) + y); - water 
		for (float theta = 0.0; theta <= 2 * PI + inct; theta += inct) {
			glColor3ub(255, 255, 255);
			glVertex2f(5 * cos(theta) + x + 40, 5 * sin(theta) + y - 30);
		}
	}
	glEnd();

	//body
	glColor3ub(0, 100, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x - 32, y - 70);
	glVertex2f(x + 30, y - 70);
	glVertex2f(x / 2 + 25, y + 25);
	glEnd();

	//face
	glColor3ub(255, 241, 229);
	float inc = (2 * PI / 10);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(r*cos(theta) + x, r*sin(theta) + y);
	}
	glEnd();

	//hat
	glColor3ub(20, 0, 205);
	inc = (2 * PI / 10);
	glBegin(GL_POLYGON);
	for (float theta = 0.2; theta <= PI + inc; theta += inc) {
		glVertex2f(r*cos(theta) + x, r*sin(theta) + y);
	}
	glEnd();

	glColor3ub(255, 0, 0);
	inc = (2 * PI / 10);
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI + inc; theta += inc) {
		glVertex2f(8 * cos(theta) + x - 21, 8 * sin(theta) + y + 20);
	}
	glEnd();

	//scarf
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 20, y - 25);
	glVertex2f(x + 18, y - 25);
	glVertex2f(x + 18, y - 15);
	glVertex2f(x - 20, y - 15);
	glEnd();

	//hand
	glColor3ub(0, 100, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 5, y - 30);
	glVertex2f(x + 30, y - 40);
	glVertex2f(x + 30, y - 30);
	glVertex2f(x - 5, y - 40);
	glEnd();
}
