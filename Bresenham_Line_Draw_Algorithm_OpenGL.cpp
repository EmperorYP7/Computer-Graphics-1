// Bresenham's Line Drawing Algorithm using OpenGL

#include<stdio.h>
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

int x1, y1, x2, y2, p;

void Display(void) {
    float dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;
    glBegin(GL_POINT);
    glVertex2f(x1, y1);

    glEnd();
    glBegin(GL_POINTS);

    p = (2 * dy) - dx;
    while (x1 < x2) {

        if (p >= 0) {
            y1 += 1;
            p = p + (2 * dy - 2 * dx);
        }
        else
        {
            p = p + 2 * dy;
        }

        x1 += 1;
        cout << "(" << x1 << "," << y1 << ")\n";
        glVertex2f(x1, y1);
    }
    glEnd();
    glFlush();

}


void init() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);

}


int main(int argc, char *argv[]) {

    cout << "Enter the start co-ordinates (x1,y1): ";
    cin >> x1 >> y1;

    cout << "Enter the end co-ordinates (x2,y2): ";
    cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Bresenham's Line Drawing Algorithm using OpenGL");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return EXIT_SUCCESS;
}


// Date: 04.November.2021
// Created by: Hari Om Yadav
