// Bresenham's Circle Drawing Algorithm

#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void EightWaySymmetricPlot(int xc, int yc, int x, int y) {

    putpixel(xc + x, yc + y, GREEN);
    putpixel(xc + x, yc - y, RED);
    putpixel(xc - x, yc - y, YELLOW);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + y, yc + x, BROWN);
    putpixel(xc - y, yc + x, MAGENTA);
    putpixel(xc + y, yc - x, DARKGRAY);
    putpixel(xc - y, yc - x, CYAN);
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
        EightWaySymmetricPlot(xc, yc, x1, y1);
        cout << "{" << x1 << ", " << y1 << "}\n";
    }

    _getch();

}
