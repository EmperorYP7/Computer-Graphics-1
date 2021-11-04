// Bresenham's Circle Drawing Algorithm using OpenGL

#include<stdio.h>
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

int xc, yc, r, x1, y1;

void EightWaySymmetricPlot(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f(xc + x, yc + y);
	glVertex2f(xc + x, yc - y);
	glVertex2f(xc - x, yc - y);
	glVertex2f(xc - x, yc + y);
	glVertex2f(xc + y, yc + x);
	glVertex2f(xc - y, yc + x);
	glVertex2f(xc + y, yc - x);
	glVertex2f(xc - y, yc - x);
	glEnd();
}
void Display(void) {

	int d = 3 - (2 * r);
	x1 = 0, y1 = r;
	while (x1 <= y1) {
		if (d <= 0) {
			d += (4 * x1) + 6;
		}
		else {
			d += 4 * (x1 - y1) + 10;
			y1 -= 1;
		}
		x1 += 1;
		EightWaySymmetricPlot(x1, y1);
		cout << "(" << x1 << ", " << y1 << ")\n";
	}

	glFlush();

}


void init() {

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 640, 0, 480);

}


int main(int argc, char *argv[]) {

	cout << "Enter co-ordinates of center of circle (xc,yc): ";
	cin >> xc >> yc;
	cout << "Enter radius of circle: ";
	cin >> r;

	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Bresenham's Circle Drawing Algorithm using OpenGL");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return EXIT_SUCCESS;
}


// Date: 04.November.2021
// Created by: Hari Om Yadav
