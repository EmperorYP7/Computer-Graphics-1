// Mid-Point Circle Drawing Algorithm

#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void EightWaySymmetricPlot(int xc, int yc, int x, int y) {

    putpixel(xc + x, yc + y, RED);
    putpixel(xc + x, yc - y, GREEN);
    putpixel(xc - x, yc - y, BROWN);
    putpixel(xc - x, yc + y, YELLOW);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, CYAN);
    putpixel(xc + y, yc - x, MAGENTA);
    putpixel(xc - y, yc - x, DARKGRAY);
}



int main () {

    int gdriver = DETECT, gmode, error;
    initgraph(&gdriver, &gmode, " ");

    int xc, yc, r, x1, y1;

    float dx, dy;
    cout << "Enter co-ordinates of center of circle (xc,yc): ";
    cin >> xc >> yc;
    cout << "Enter radius of circle: ";
    cin >> r;

    x1 = 0, y1 = r;

    int d = 1 - r;
    while (x1 <= y1) {
        if (d < 0) {
            d += (2 * x1) + 1;
        }
        else {
            d += 2 * (x1 - y1) + 1;
            y1 -= 1;
        }
        x1 += 1;
        EightWaySymmetricPlot(xc, yc, x1, y1);
        cout << "{" << x1 << ", " << y1 << "}\n";
    }

    _getch();

}
