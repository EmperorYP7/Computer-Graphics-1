//DDA Line Drawing Algorithm

#include <stdio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

int main () {

	int gdriver = DETECT, gmode, error;
	initgraph(&gdriver, &gmode, " ");

	int x1, x2, y1, y2;

	float dx, dy, P;
	cout << "Enter (x1,y1): ";
	cin >> x1 >> y1;

	cout << "Enter (x2,y2): ";
	cin >> x2 >> y2;

	dx = float(x2 - x1);
	dy = float(y2 - y1);


	if (abs(dx) >= abs(dy))
		p = abs(dx);
	else
		p = abs(dy);

	float inx = dx / p;
	float iny = dy / p;
	for (int i = 1; i <= p; i++) {

		putpixel(x1, y1, WHITE);
		x1 += inx;
		y1 += iny;

	}

	getch();
}
