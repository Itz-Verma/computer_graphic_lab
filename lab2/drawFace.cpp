#include <SDL2/SDL_bgi.h>
#include <graphics.h>
int delayTime3 = 500;
void drawFace() {
    setcolor(YELLOW);
    circle(500, 400, 350);

    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(501, 401, YELLOW);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    // Draw eyes
    fillellipse(351, 301, 30, 80);
    fillellipse(651, 301, 30, 80);

    // Draw smile
    for(int i = 90; i < 150; i++)
        ellipse(500, 500, 200, 340, 200,i);
   setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(351, 301, 30, 80);
    delay(500);
   setfillstyle(SOLID_FILL, BLACK);
    fillellipse(351, 301, 30, 80);


}

