#include <stdio.h>
#include <bits/stdc++.h>
#include <graphics.h>

typedef long long ll;


using namespace std;


int main () {

	int gdriver = DETECT, gmode, error;
	initgraph(&gdriver, &gmode, " ");

	long long int t;
	t = 1;

	while (t--) {


		int x1, x2, y1, y2, p;

		int dx, dy;
		cin >> x1 >> y1 >> x2 >> y2;
		dx = x2 - x1;
		dy = y2 - y1;
		putpixel(x1, y1, GREEN);
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
			putpixel(x1, y1, GREEN);
			cout << x1 << " " << y1 << "\n";
		}

	}
	getch();
}
