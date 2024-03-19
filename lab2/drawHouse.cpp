#include <SDL2/SDL_bgi.h>
#include <graphics.h>

int delayTime = 500;
void drawHouse(){
    
    // Draw Roof
    line(100, 100, 150, 50);
    delay(delayTime);
    line(150,50,200,100);
    delay(delayTime);
    line(150,50,350,50);
    delay(delayTime);
    line(350,50,400,100);
    delay(delayTime);
    
    // Draw font of house
    rectangle(100,100,200,200);
    delay(delayTime);

    // Draw latral face of house 
    rectangle(200,100,400,200);
    delay(delayTime);

    // Draw door
    rectangle(130,130,170,200);
    delay(delayTime);

    // Draw Window of the house 
    rectangle(250,120,350,180);
    delay(delayTime);

    setfillstyle(2,3);

    // Color Door
    floodfill(131,131,WHITE);
    delay(delayTime);

    // Color Latral face of the house 
    floodfill(201,101,WHITE);
    delay(delayTime);

    setfillstyle(11,7);

    // Color Front 
    floodfill(101,101,WHITE);
    delay(delayTime);

    // Color Roof
    floodfill(150,52,WHITE);
    delay(delayTime);
    floodfill(163,55,WHITE);
    delay(delayTime);

    // Color Window
    floodfill(251,121,WHITE);
    delay(delayTime);
    
}
