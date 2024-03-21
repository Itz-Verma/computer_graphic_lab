#include <cstdlib>
#include <graphics.h>

#include "Utility.hpp"
#include "RasterAlgo.hpp"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800


int main() {
    int x1,y1,x2,y2;
    getCoords(x1, y1, x2, y2);

    int nx1 = x1, ny1 = y1, nx2 = x2, ny2 = y2; // nx1 -> newX1
    int originX = WINDOW_WIDTH/2, originY = WINDOW_HEIGHT/2;
    transformation(nx1,ny1,nx2,ny2,originX + 100, originY + 100);

    initGraphAndWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    drawAxes(WINDOW_WIDTH, WINDOW_HEIGHT, originX + 100, originY + 100);

    int originalCoods[] = {x1,y1,x2,y2};
    int newCoods[] = {nx1,ny1,nx2,ny2};
    putCoords(originalCoods, newCoods);

    RasterAlgo ra;
    ra.DDA(nx1,ny1,nx2,ny2);
    getch();
    cleardevice();

    ra.BresenhamAlgo(nx1,ny1,nx2,ny2);
    getch();
    cleardevice();
    closegraph();
}
