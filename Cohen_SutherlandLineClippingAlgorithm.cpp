// Cohen-Sutherland Line Clipping Algorithm

#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;
void DrawRectangle() {
	line(100, 100, 300, 100);
	line(100, 300, 300, 300);
	line(100, 100, 100, 300);
	line(300, 100, 300, 300);
}
void stepping(double bit[4], double x, double y ) {
	if (x < 100)
		bit[0] = 1;
	else
		bit[0] = 0;
	if (x > 300)
		bit[1] = 1;
	else
		bit[1] = 0;
	if (y < 100)
		bit[2] = 1;
	else
		bit[2] = 0;
	if (y > 300)
		bit[3] = 1;
	else
		bit[3] = 0;

}
void clipping(double bit1[4], double bit2[1], double* x, double* y, double slope) {

	double x1 = *x, y1 = *y;
	bool f = true;
	for (int i = 0; i < 4; i++) {
		if (bit1[i] != 0 && bit2[i] != 0) {
			f = false;
			break;
		}
		if (f == 1) {
			if (bit1[0] != 0) {
				y1 = slope * (100 - x1) + y1;
				x1 = 100;
			}
			else if (bit1[1] != 0) {
				y1 = slope * (300 - x1) + y1;
				x1 = 300;
			}
			else if (bit1[2] != 0) {
				x1 = ((100 - y1) / slope) + x1;
				y1 = 100;
			}
			else if (bit1[3] != 0) {
				x1 = ((300 - y1) / slope) + x1;
				y1 = 300;
			}
		}
		if (f == 0)
			cout << "Line is outside.";
		*x = x1;
		*y = y1;
	}

}

int main () {

	int gdriver = DETECT, gmode, error;
	initgraph(&gdriver, &gmode, " ");

	double x1, y1, x2, y2;
	double bit1[4], bit2[4];

	cout << "Enter the starting co-ordinates (x1,y1) of line: ";
	cin >> x1 >> y1;

	cout << "Enter the ending co-ordinates (x2,y2) of line: ";
	cin >> x2 >> y2;

	DrawRectangle();
	line(x1, y1, x2, y2);

	double slope = float((y2 - y1) / (x2 - x1));
	stepping(bit1, x1, y1);
	stepping(bit2, x2, y2);
	clipping(bit1, bit2, &x1, &y1, slope);
	clipping(bit2, bit1, &x2, &y2, slope);

	DrawRectangle();
	line(x1, y1, x2, y2);
	_getch();

}
