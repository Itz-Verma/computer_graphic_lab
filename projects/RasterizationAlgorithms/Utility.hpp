#pragma once

#include<graphics.h>
#include<iostream>

void initGraphAndWindow(const int WINDOW_WIDTH, const int WINDOW_HEIGHT);
void getCoords(int& x1, int& y1, int& x2, int& y2 );
void putCoords(int oc[], int nc[]);
void translation(int& x1, int& y1, int& x2, int& y2, const int originX, const int  originY);
void transformation(int& x1, int& y1, int& x2, int& y2, const int originX, const int  originY);
void drawAxes(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, const int originX, const int originY);
