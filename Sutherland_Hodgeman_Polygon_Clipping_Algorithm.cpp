
// Sutherland-Hodgeman Polygon Clipping Algorithm

#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;
const int MAX_POINTS = 20;
int intersection_x(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

int intersection_y(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

void clipper(int polygon[][2], int &poly_sz, int x1, int y1, int x2, int y2)
{

	int np[MAX_POINTS][2], new_polygon_sz = 0;


	for (int i = 0; i < poly_sz; i++) {

		int q = (i + 1) % poly_sz;
		int xi = polygon[i][0];
		int yi = polygon[i][1];
		int qx = polygon[q][0];
		int qy = polygon[q][1];

		int i_position = (x2 - x1) * (yi - y1) - (y2 - y1) * (xi - x1);
		int q_position = (x2 - x1) * (qy - y1) - (y2 - y1) * (qx - x1);

		if (i_position < 0 && q_position < 0) {

			np[new_polygon_sz][0] = qx;
			np[new_polygon_sz][1] = qy;
			new_polygon_sz++;
		}

		else if (i_position >= 0 && q_position < 0) {

			np[new_polygon_sz][0] = intersection_x(x1, y1, x2, y2, xi, yi, qx, qy);
			np[new_polygon_sz][1] = intersection_y(x1, y1, x2, y2, xi, yi, qx, qy);

			new_polygon_sz++;
			np[new_polygon_sz][0] = qx;
			np[new_polygon_sz][1] = qy;
			new_polygon_sz++;
		}
		else if (i_position < 0 && q_position >= 0) {

			np[new_polygon_sz][0] = intersection_x(x1, y1, x2, y2, xi, yi, qx, qy);
			np[new_polygon_sz][1] = intersection_y(x1, y1, x2, y2, xi, yi, qx, qy);

			new_polygon_sz++;
		}
		else {

		}

	}
	poly_sz = new_polygon_sz;
	for (int i = 0; i < poly_sz; i++) {
		polygon[i][0] = np[i][0];
		polygon[i][1] = np[i][1];

	}
}

int intersection_x(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {

	int n1 = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);

	int d1 = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	return n1 / d1;

}

int intersection_y(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {

	int n1 = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
	int d1 = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	int fraction = n1 / d1;
	return n1 / d1;

}

void SutherlandHodgemanClip(int polygon[][2], int poly_sz, int clipperPoints[][2], int clipper_sz) {


	for (int i = 0; i < clipper_sz; i++) {
		int q = (i + 1) % clipper_sz;
		clipper(polygon, poly_sz, clipperPoints[i][0], clipperPoints[i][1], clipperPoints[q][0], clipperPoints[q][1]);
	}

	int points[20];
	int x1 = 0;
	cout << "Points: \n";
	for (int i = 0; i < poly_sz; i++) {
		cout << "( " << polygon[i][0] << ", " << polygon[i][1] << " )\n";
		points[x1++] = polygon[i][0];
		points[x1++] = polygon[i][1];
	}
	fillpoly(5, points);
}

int main () {

	int gdriver = DETECT, gmode, error;
	initgraph(&gdriver, &gmode, " ");

	int poly_sz ;
	int polygon[20][2];

	cout << "Enter the number of sides of the Polygon: \n";
	cin >> poly_sz;

	cout << "Enter the co-ordinates of the Polygon (x,y) : \n";

	for (int i = 0; i < poly_sz; i++) {
		cin >> polygon[i][0] >> polygon[i][1];
	}

	int clipper_sz;
	int clipperPoints[20][2];

	cout << "Enter the number of points of the Clipper Area: \n";
	cin >> clipper_sz;

	cout << "Enter the co-ordinates of the Clipping Area (x,y) : \n";
	for (int i = 0; i < clipper_sz; i++) {
		cin >> clipperPoints[i][0] >> clipperPoints[i][1];
	}

	setcolor(GREEN);
	rectangle(150, 150, 350, 350);

	SutherlandHodgemanClip(polygon, poly_sz, clipperPoints, clipper_sz);



	_getch();
	closegraph();

}

// Date: 28.October.2021
// Created by: Hari Om Yadav
