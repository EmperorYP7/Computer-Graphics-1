// Bresenham's Line Drawing Algorithm

#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

int main () {

    int gdriver = DETECT, gmode, error;
    initgraph(&gdriver, &gmode, " ");

    int x1, x2, y1, y2, p;

    int dx, dy;
    cout << "Enter (x1,y1): ";
    cin >> x1 >> y1;
    cout << "Enter (x2,y2): ";
    cin >> x2 >> y2;
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
    _getch();
}
