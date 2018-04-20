#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\freeglut.h>

#include "Girl.h"
#include "background.h"
#include "Item.h"
#include "family.h"
#include <mmsystem.h> 

#define screenWidth		1280
#define screenHeight	768

#define FPS 50
#define PI 3.1415926535897

int xv, yv, xV, yV, xc, yc, xC, yC, xp, yp, xA, yA, xm, ym, xl, yl, xs, ys, xS, yS, xo, yo, xO, yO, xcl, ycl, xa, ya, xmn, ymn, xB, yB, xsb, ysb;
int	dx, dy, dxv, dyv, dxV, dyV, dxC, dyC, dxp, dyp, dxA, dyA, dxm, dym, dxl, dyl, dxs, dys, dxS, dyS, dxo, dyo, dxO, dyO, dxcl, dycl, dxa, dya, dxmn, dymn, bx, by, dbx, dby, dxB, dyB, dBallX, dBallY;

int girlx, girly, girldx, girldy, Tx, Ty, dxT, dyT, mfirex, mfirey, mfiredy, child_x, child_y, child_dx, toy_x, toy_y, toy_y2, toy_dx, toy_dy, toy_dy2, turkey_y, turkey_dy;
int timer = 0;

void nGon(int x, int y, int r, int n) {
	float inc = (2 * PI) / n;
	glBegin(GL_POLYGON);
	for (float theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2f(x + r*cos(theta), y + r*sin(theta));
	}
	glEnd();
}

void snowBall(int xsb, int ysb, int r, int n) {
	if (dBallY >= 0) {
		//Draw snow ball
		glColor3ub(255, 255, 255);
		nGon(xsb, ysb, r, n);
	}
}

void tear(int x, int y) {
	glColor3ub(0, 255, 255);
	nGon(x,y, 10, 100);
	glBegin(GL_POLYGON);
	glVertex2f(x - 12.5, y);
	glVertex2f(x + 12.5, y);
	glVertex2f(x, y+20);
	glEnd();
}


void idle() {
	DWORD start = GetTickCount();
	while (GetTickCount() - start < 1000 / FPS);

	if (xc > screenWidth * 5 || xc < -screenWidth * 4 - 720)dx *= 0;
	if (yc > screenHeight || yc < 0) dy *= -1;

	xc -= dx;
	yc += dy;

	if (xC > screenWidth * 5 || xC < -screenWidth * 4 - 770) dxC *= 0;
	if (yC > screenHeight || yC < 0) dyC *= -1;

	xC -= dxC;
	yC += dyC;

	if (xp > screenWidth * 5 || xp < -screenWidth * 4 - 760) dxp *= 0;
	if (yp > screenHeight || yp < 0) dyp *= -1;

	xp -= dxp;
	yp += dyp;

	if (xA > screenWidth * 6 || xA < -screenWidth * 4 - 780) dxA *= 0;
	if (yA > screenHeight || yA < 0) dyA *= -1;

	xA -= dxA;
	yA += dyA;

	if (xm > screenWidth + 800 || xm < -500) dxm *= -1;
	if (ym > screenHeight || ym < 0) dym *= -1;

	xm += dxm;
	ym += dym;

	if (xl > screenWidth + 1000 || xl < -500) dxl *= -1;
	if (yl > screenHeight || yl < 0) dyl *= -1;

	xl += dxl;
	yl += dyl;

	if (xs > screenWidth + 800 || xs < -500) dxs *= -1;
	if (ys > screenHeight || ys < 0) dys *= -1;

	xs += dxs;
	ys += dys;

	if (xS > screenWidth + 500 || xS < -2500) dxS *= 0;
	if (yS > screenHeight || yS < 0) dyS *= -1;

	xS -= dxS;
	yS += dyS;

	if (xo > screenWidth + 1500 || xo < -700) dxo *= -1;
	if (yo > screenHeight || yo < 0) dyo *= -1;

	xo += dxo;
	yo += dyo;

	if (xO > screenWidth + 1200 || xO < -3000) dxO *= 0;
	if (yO > screenHeight || yO < 0) dyO *= -1;

	xO -= dxO;
	yO += dyO;

	if (xv > screenWidth * 3 + 600 || xv < -screenWidth * 2 - 900) dxv *= 0;
	if (yv > screenHeight || yv < 0) dyv *= -1;

	xv += dxv;
	yv += dyv;

	if (xV > screenWidth + 300 || xV < -1700) dxV *= 0;
	if (yV > screenHeight || yv < 0) dyV *= -1;

	xV -= dxV;
	yV += dyV;

	if (xa < -1300) dxa *= 0;
	if (ya > screenHeight || ya < 0) dya *= -1;

	xa -= dxa;
	ya += dya;

	if (xcl > screenWidth * 1 / 2 || xcl < 0) dxcl *= -1;
	if (ycl > screenHeight || ycl < 0) dycl *= -1;

	xcl += dxcl;
	ycl += dycl;

	if (xmn < -150) dxmn *= 0;
	if (ymn > screenHeight || ymn < 0) dymn *= -1;

	xmn -= dxmn;
	ymn += dymn;

	if (bx > screenWidth*0.15 || bx < -30) dbx *= -1;
	if (by > screenHeight*0.15 || by < 80) dby *= -1;

	bx -= dbx;
	by += dby;

	if (xB > screenWidth*0.8 || xB < 0) dxB *= 0;
	if (yB > screenHeight*0.15 || yB < 80) dyB *= -1;

	xB += dxB;
	yB += dyB;

	if (xsb > screenWidth || xsb < 0) dBallX *= -1;
	if (ysb > screenHeight || ysb < -1300) dBallY *= -1;

	xsb += dBallX;
	ysb -= dBallY;

	//if (timer > 430 && timer < 650) {
	//	xc -= dx;
	//}

	if (mfirey >= 180 || mfirey <= 210) mfiredy *= -1;
	mfirey -= mfiredy;

	if (Ty >= 50 || Ty <= 200) dyT *= -1;
	Ty -= dyT;

	if (timer >= 0 && timer <= 150) {
		if (girlx <= 0 || girlx >= screenWidth / 2)girldx *= 1; // if one direction only no need dx
		girlx += girldx;
		if (timer >= 0 && timer <= 20) {
			if (child_x >= -10 || child_x <= 50) child_dx *= 1;
			child_x += child_dx;
		}
	}
	if (timer >= 500 && timer <= 630) {
		if (turkey_y <= 0 || turkey_y >= screenHeight/2) turkey_dy *= 1;
		turkey_y -= turkey_dy;
	}
	if (timer >= 1100 && timer <= 1250) {
		if (toy_y <= 0 || toy_y >= screenHeight / 2) toy_dy2 *= 1;
		toy_y2 -= toy_dy2;
	}

	if (timer >= 1850 && timer <= 1900) {
		if (girly <= 20 || girly >= screenHeight / 7)girldy *= -1; 
		girly -= girldy;
	}
	if (timer >= 1900 && timer <= 2500) {
		if (toy_x <= 680 || toy_x >= 800) toy_dx *= -1;
		if (toy_y <= 50 || toy_y >= 130) toy_dy *= -1;
		toy_x += toy_dx;
		toy_y -= toy_dy;
	}
	
	if (timer >= 2500) {
		if (toy_x <= screenWidth/2 || toy_x >= screenWidth-200) toy_dx *= -1;
		if (toy_y <= 0 || toy_y >= screenHeight/2) toy_dy *= -1;
		toy_x += toy_dx;
		toy_y -= toy_dy;
	}

	timer++;

	glutPostRedisplay();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);

	
	//background
	sky(100, 100, 100); 
	//star
	for (int i = 0; i < 10; i++) {
		star(rand()%1200, 500+ rand()%300, rand()%(50-20));
	}

	house(0, 200, 200);
	moon(1000, 700);
	road(0, 50, 1280, 110);

	//big fire !!!!!
	if (timer >= 1750 && timer <= 1800) {
		matchfire(rand() % 350 + 500, 200, 20, 20);
		matchfire(rand() % 350 + 500, 200, 20, 20);
	}

	//toy save the fire
	if (timer >= 1800 && timer <= 2100) {
		/*toy(toy_x, toy_y, 30, 100);*/
		fire(510, 200, 40, 20);
		fire(560, 200, 40, 20);
	}

	if (timer >= 1800) {
		toy(toy_x, toy_y, 30, 100);
	}
	light(100, 100, 100);
	extinguisher(100, 100, 100);
	bench(100, 100, 100);

	human(girlx, girly, 120, timer);
	
	christmastree(100, 100, 100);
	christmastree1(100, 100, 100);
	fountain(100, 100, 100);
	
	if (timer >= 1600 && timer <= 1800) {
		toy(700, 100, 30, 100);
	}

	if (timer >= 30 ) snowmanbottom(child_x, child_y, 25);
	if (timer >= 100) snowman(child_x, child_y, 25);
	if (timer >= 0 && timer <= 300) child1(child_x, child_y, 25);

	//save the fire 
	glColor3ub(31, 162, 224);
	if (timer >= 2000 && timer <= 2050) nGon(450, 250, 100, 100);
	if (timer >= 2050 && timer <= 2100) nGon(450, 250, 150, 100);
	if (timer >= 2100 && timer <= 2150) nGon(450, 250, 200, 100);
	if (timer >= 2150 && timer <= 2200) nGon(450, 250, 400, 100);
	if (timer >= 2200 && timer <= 2250) nGon(450, 250, 800, 100);
	if (timer >= 2250 && timer <= 2300) nGon(450, 250, 1000, 100);

	if (timer >= 0 && timer <= 300)
	basket(girlx+100, girly+80, 50);


	if (timer >= 350 && timer <= 500 || timer >= 950 && timer <= 1100 || timer >= 1650 && timer <= 1800) {
		matches(girlx, girly, 120, timer);
	}
	if (timer >= 400 && timer <= 500 || timer >= 1000 && timer <= 1100 || timer >= 1700 && timer <= 1800) {
		matchfire(mfirex, mfirey, 10, 5);
	}
	//thinking - want a turkey
	if (timer >= 190 && timer <= 350) {
		family();
		human(-100, -400, 400, timer);
		if (timer >= 250 && timer <= 350) {
			cloud(200, 600, 110);
			turkey(250, 550, 130);
			tear(50, 150);
		}	
	}

	if (timer >= 500 && timer <= 750) {
		turkey(700, turkey_y, 100);
		if (timer >= 550 && timer <= 750) heart(girlx, girly + 100, 5);
		if (timer >= 575 && timer <= 750) heart(girlx + 100, girly + 50, 3);
		if (timer >= 600 && timer <= 750) heart(girlx + 150, girly + 100, 5);
		if (timer >= 635 && timer <= 750) heart(girlx + 100, girly + 70, 2);
		if (timer >= 645 && timer <= 750) heart(girlx + 50, girly + 150, 5);
	}

	if (timer >= 750 && timer <= 850) {
		bone(700, 100, 100);
	}
	
	//thinking - want a toy
	if (timer >= 850 && timer <= 950) {
		family();
		human(200, -400, 400, timer);
		cloud(600, 600, 110);
		toy(700, 550, 70, 100);
		tear(350, 150);
	}

	//get the toy - <3 <3 <#
	if (timer >= 1100 && timer <= 1450) {
		toy(750, toy_y2, 30, 100);
		if (timer >= 1100 && timer <= 1400) heart(girlx, girly+100, 5);
		if (timer >= 1150 && timer <= 1400) heart(girlx+100, girly + 50, 3);
		if (timer >= 1200 && timer <= 1400) heart(girlx + 150, girly + 100, 5);
		if (timer >= 1250 && timer <= 1400) heart(girlx + 100, girly + 70, 2);
		if (timer >= 1300 && timer <= 1400) heart(girlx + 50, girly + 150, 5);
	}
	//thinking - want a house
	if (timer >= 1450 && timer <= 1600) {
		family();
		human(-100, -400, 400, timer);
		cloud(100, 600, 110);
		smallhouse(100, 450, 150);
		tear(50, 150);
	}

	if (timer >= 0 && timer <= 3000) {
		snowBall(xsb + 450, ysb + 350, 15, 25);
		snowBall(xsb - 200, ysb + 500, 10, 20);
		snowBall(xsb - 350, ysb + 90, 15, 25);
		snowBall(xsb - 100, ysb + 300, 13, 10);
		snowBall(xsb + 800, ysb + 300, 5, 15);
		snowBall(xsb + 250, ysb + 100, 20, 20);
		snowBall(xsb + 300, ysb + 200, 12, 25);
		snowBall(xsb - 350, ysb + 400, 10, 25);
		snowBall(xsb - 500, ysb + 300, 10, 25);
		snowBall(xsb - 100, ysb + 1000, 10, 25);
		snowBall(xsb + 300, ysb + 900, 10, 25);
		snowBall(xsb - 350, ysb + 1200, 10, 25);
		snowBall(xsb + 180, ysb + 700, 10, 25);
		snowBall(xsb + 400, ysb + 600, 10, 25);
		snowBall(xsb - 500, ysb + 100, 13, 10);
		snowBall(xsb + 900, ysb + 900, 5, 15);
		snowBall(xsb + 300, ysb + 1000, 10, 25);
		snowBall(xsb - 350, ysb + 800, 10, 25);
		snowBall(xsb + 180, ysb + 1300, 10, 25);
		snowBall(xsb + 400, ysb + 600, 10, 25);
		snowBall(xsb - 100, ysb + 1100, 13, 10);
		snowBall(xsb + 700, ysb + 900, 5, 15);
	}
	
	//ending
	if (timer >= 2500) {
		glColor3ub(0, 0, 0);
		rectangle(0, 0, 1280, 800);
		human(screenWidth / 4, screenHeight / 4, 200, timer);
		toy(toy_x + 100, toy_y+200, 50, 100);
		heart(rand()%1280, rand()%800, rand()%20);
		heart(rand() % 1280, rand() % 800, rand() % 20);
	}

	glFlush();
	glutSwapBuffers();
}


void initGLSB() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);

	girlx = screenWidth / 10;
	girly = screenHeight / 8;

	girldx = 3;
	girldy = 6;

	xsb = screenWidth / 2;
	ysb = screenHeight / 2;
	dBallX = 0;
	dBallY = 3;

	mfirex = 560;
	mfirey = girly + 150;
	mfiredy = 3;

	child_x = 0;
	child_y = 90;
	child_dx = 3;

	toy_x = 700;
	toy_y = 100;
	toy_y2 = 550;
	toy_dx = 1;
	toy_dy = 1;
	toy_dy2 = 3;

	turkey_y = 550;
	turkey_dy = 3;
}


int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow("The Little Match Girl");
	PlaySound("Winter Sonata.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	initGLSB();
	
	glutMainLoop();

	return 1;
}