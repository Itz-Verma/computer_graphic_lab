#include <SDL2/SDL_bgi.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    setcolor(RED); // set the color of the line.


     // Draw a line between two point A(x1,y1) and B(x2,y2) 
     int x1 = 30, y1 = 50, x2 = 300, y2 = 500;
     line(x1, y1, x2, y2);
     getch();
     cleardevice();

     // Draw circle
     int centerX = 500, centerY = 200, radius = 50;
     circle(centerX, centerY, radius);
     getch();
     cleardevice();

     // Draw rectangle
     rectangle(x1, y1, x2, y2);
     getch();
     cleardevice();

     // Draw ellipse
     int startAngle = 0, endAngle = 360, xRadius = 100, yRadius = 200;
     ellipse(centerX, centerY, startAngle, endAngle, xRadius, yRadius);
     getch();
     cleardevice();

     // Draw pieslice
     endAngle = 90;
     pieslice(centerX, centerY, startAngle, endAngle, radius);
     getch();
     cleardevice();

     // Draw sector 
     sector(centerX, centerY, startAngle, endAngle, xRadius, yRadius);
     getch();
     cleardevice();

     // Draw arc
     arc(centerX, centerY, startAngle, endAngle, radius);
     getch();
     cleardevice();

     // Draw polygon
     int vertices = 3;
     int x3 = 400, y3 = 100;
     int openPolygonPoints[] = {x1,y1,x2,y2,x3,y3};
     drawpoly(vertices, openPolygonPoints); // it will draw open polygon.
     getch();
     cleardevice();

     int closePolygonPoints[] = {x1,y1,x2,y2,x3,y3,x1,y1};
     drawpoly(vertices + 1, closePolygonPoints); // it will draw close polygon.
                                             // for close polygon we have to enter the n+1 point which is the
                                             // the 1st point.
     getch();
     cleardevice();

}
