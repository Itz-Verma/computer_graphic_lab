#pragma once
#include<graphics.h>

class RasterAlgo {
    int x1,y1,x2,y2;
    public:
        RasterAlgo(){}
        void DDA(int& x1, int& y1, int& x2, int& y2);
        void BresenhamAlgo(int& x1, int& y1, int& x2, int& y2);
};