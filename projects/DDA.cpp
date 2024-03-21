/*
 * DDA (Digital Differential Analyzer) is a line drawing algorithm used in computer graphics to generate a line segment between two specified endpoints. 
 *
 */
#include <SDL2/SDL_bgi.h>
#include <cstdlib>
#include <iostream>
#include <graphics.h>
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1024

void getCoords(int& x1, int& y1, int& x2, int& y2 ){
    std::cout<<"Enter Coordinates as space saparated  integral values:"<<std::endl;
    std::cout<<"Enter coordinates of 1st point: ";
    std::cin>>x1>>y1;
    std::cout<<"Enter coordinates of 2st point: ";
    std::cin>>x2>>y2;
}


void translation(int& x1, int& y1, int& x2, int& y2) {
    /* Since the origin is begin shifted to (WINDOW_WIDTH/2, WINDOW_HEIGHT/2) 
     * all other coordinates are translated w.r.t new origin.
     * */ 
    x1 = x1 + WINDOW_WIDTH/2;
    x2 = x2 + WINDOW_WIDTH/2;
    y1 = y1 + WINDOW_HEIGHT/2;
    y2 = y2 + WINDOW_HEIGHT/2;
}

void transformation(int& x1, int& y1, int& x2, int& y2) {
    /* change of y-aixs as given window has +Y in down direction  but actually it is in upper direction.
     -----------------------> +Y               ^ +Y  
     |                                         |      
     |                                         |
     |                           ====>         |              
     |                                         | 
     |                                         |    
     +Y                                        -----------------------------> +X


    */ 
    y1 = -y1;
    y2 = -y2;
    translation( x1, y1, x2,  y2);
}

void drawAxes() {
    setcolor(WHITE);
    line(0,WINDOW_HEIGHT/2,WINDOW_WIDTH,WINDOW_HEIGHT/2); // X-axis 
    line(WINDOW_WIDTH/2,0,WINDOW_WIDTH/2,WINDOW_HEIGHT); // Y-axis 
    settextstyle(1, 0, 5);
    outtextxy(WINDOW_WIDTH/2,0,(char*)"+Y");
    outtextxy(WINDOW_WIDTH/2,WINDOW_HEIGHT - 50,(char*)"-Y");
    outtextxy(0,WINDOW_HEIGHT/2,(char*)"-X");
    outtextxy(WINDOW_WIDTH - 50,WINDOW_HEIGHT/2,(char*)"+X");
    settextstyle(1, 0, 1);
    setcolor(RED);
    outtextxy(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, (char *)"(0,0)");
}

void initGraphAndWindow(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    drawAxes();
}

void putCoords(int oc[], int nc[]){
    settextstyle(1, 0, 1);
    char a[80],b[80];
    sprintf(a, "(%d,%d)",oc[0],oc[1]);
    sprintf(b, "(%d,%d)",oc[2],oc[3]);
    circle(nc[0], nc[1], 2);
    outtextxy(nc[0], nc[1], (char*)a);
    circle(nc[2], nc[3], 2);
    outtextxy(nc[2], nc[3], (char*)b);
}

/* ---------------------------------------------------------
* The DDA Algorithm to draw line.
* The algorithm is modified  to account the  window configuration and slope of the line to decide the increment decrement values for x and y *
*/ 
void DDA(int x1, int y1, int x2, int y2) {
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

/*-------------------------------------------------------------*/ 

void put(int x1,int y1,int x2,int y2){
    outtextxy(x1, y1, (char *)"(x1, y1)");
    outtextxy(x2, y2, (char *)"(x2, y2)");
}

int main() {
    int x1,y1,x2,y2;
    getCoords(x1, y1, x2, y2);
    int nx1 = x1, ny1 = y1, nx2 = x2, ny2 = y2; // nx1 -> newX1
    transformation(nx1,ny1,nx2,ny2);
    initGraphAndWindow();
    int originalCoods[] = {x1,y1,x2,y2};
    int newCoods[] = {nx1,ny1,nx2,ny2};
    putCoords(originalCoods, newCoods);
    DDA(nx1,ny1,nx2,ny2);
    getch();
    closegraph();
}
