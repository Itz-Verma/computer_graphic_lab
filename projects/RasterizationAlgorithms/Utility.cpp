
#include"Utility.hpp"

void getCoords(int& x1, int& y1, int& x2, int& y2 ){
    std::cout<<"Enter Coordinates as space saparated  integral values:"<<std::endl;
    std::cout<<"Enter coordinates of 1st point: ";
    std::cin>>x1>>y1;
    std::cout<<"Enter coordinates of 2st point: ";
    std::cin>>x2>>y2;
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

void transformation(int& x1, int& y1, int& x2, int& y2, const int originX, const int  originY) {
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
    translation( x1, y1, x2,  y2, originX, originY);
}

void translation(int& x1, int& y1, int& x2, int& y2, const int originX, const int  originY) {
    /* Since the origin is begin shifted to (WINDOW_WIDTH/2, WINDOW_HEIGHT/2) 
     * all other coordinates are translated w.r.t new origin.
     * */ 
    x1 = x1 + originX;
    x2 = x2 + originX;
    y1 = y1 + originY;
    y2 = y2 + originY;
}

void initGraphAndWindow(const int WINDOW_WIDTH, const int WINDOW_HEIGHT){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void drawAxes(const int WINDOW_WIDTH, const int WINDOW_HEIGHT, const int originX, const int originY) {
    setcolor(WHITE);
    line(0, originY, WINDOW_WIDTH, originY); // X-axis 
    line(originX, 0, originX, WINDOW_HEIGHT); // Y-axis 
    settextstyle(1, 0, 5);
    outtextxy(originX,0,(char*)"+Y");
    outtextxy(originX,WINDOW_HEIGHT - 50,(char*)"-Y");
    outtextxy(0,originY,(char*)"-X");
    outtextxy(WINDOW_WIDTH - 50,originY,(char*)"+X");
    settextstyle(1, 0, 1);
    setcolor(RED);
    outtextxy(originX, originY, (char *)"(0,0)");
}