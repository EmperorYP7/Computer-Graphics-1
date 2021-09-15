//Mid-Point Ellipse Drawing Algorithm

#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

int main () {

	int gdriver = DETECT, gmode, error;
	initgraph(&gdriver, &gmode, " ");

	int a, b, x, y, fx, fy, p, xc, yc;
	cout << "Enter center of Ellipse (xc,yc): ";
	cin >> xc >> yc;

	cout << "Enter length of semi-major axis (a): ";
	cin >> a;
	cout << "Enter length of semi-minor axis (b): ";
	cin >> b;

	x = 0, y = b;
	fx = 0;
	fy = a * a;
	fy *= 2 * b;
	p = (b * b) - (fy / 2) + (a * a) / 4;
	while (fx < fy)
	{
		if (p < 0) {
			p = p + fx + (b * b);
		}
		else {
			fy = fy - (2 * a * a);
			p = p + fx + (b * b) - fy;
			y--;
		}
		fx = fx + 2 * (b * b);
		x++;

		putpixel(xc + x, yc + y, GREEN);
		putpixel(xc + x, yc - y, GREEN);
		putpixel(xc - x, yc + y, GREEN);
		putpixel(xc - x, yc - y, GREEN);

	}

	p = (b * b) * (x + 0.5) * (x + 0.5) + (a * a) * (y - 1) * (y - 1) - (a * a) * (b * b);
	while (y > 0) {

		if (p < 0) {
			x++;
			fx = fx + 2 * (b * b);
			p = p + fx - fy + (a * a);
		}
		else {
			p = p - fy + (a * a);
		}

		--y;
		fy -= 2 * (a * a);
		putpixel(xc + x, yc + y, GREEN);
		putpixel(xc + x, yc - y, GREEN);
		putpixel(xc - x, yc + y, GREEN);
		putpixel(xc - x, yc - y, GREEN);

	}
	_getch();

}
