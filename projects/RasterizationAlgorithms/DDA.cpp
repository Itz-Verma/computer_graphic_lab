#include "RasterAlgo.hpp"


/*
 * DDA (Digital Differential Analyzer) is a line drawing algorithm used in computer graphics to generate a line segment between two specified endpoints. 
 
* The algorithm is modified  to account the  window configuration and slope of the line to decide the increment decrement values for x and y
*/ 

void RasterAlgo::DDA(int& x1, int& y1, int& x2, int& y2) {
    int deltaX = std::abs(x1-x2);
    int deltaY = std::abs(y1-y2);
    int steps= std::max(std::abs(deltaX), std::abs(deltaY));
    float xIncrement = deltaX/float(steps);
    float  yIncrement = deltaY/float(steps);

    float x,y,m;
    if (x1 != x2){
     x = std::min(x1,x2);
     y = (x == x1) ? y1 : y2;
     m = (y2-y1)/(x2-x1);
    } else {
        x = x1;
        y = std::max(y1,y2);
        m = 0;
    }
    for(int i = 0; i<steps; i++) {
        putpixel(x,y, RED);
        x += xIncrement;
        if ( m<=0)
            y -= yIncrement; 
        else 
            y += yIncrement; 
    }
}

void RasterAlgo::BresenhamAlgo(int& x1, int& y1, int& x2, int& y2){}