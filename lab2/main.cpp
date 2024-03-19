#include <graphics.h>
#include <iostream>
#include "figures.hpp"

#define WINDOW_HEIGHT 800
#define WINDOW_WEIGHT 1000 
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    initwindow(WINDOW_WEIGHT, WINDOW_HEIGHT);

    drawHouse();
    getch();
    cleardevice();

    drawHeart();
    getch();
    cleardevice();

    drawFace();
    getch();
    cleardevice();

    closegraph();

    return 0;
}
