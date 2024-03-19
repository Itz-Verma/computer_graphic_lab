#include <graphics.h>
int delayTime2 = 500;
void drawHeart(){
    rectangle(150, 50, 450,350);
    delay(delayTime2);
    ellipse(250, 150, 0, 190, 50, 70);
    delay(delayTime2);
    ellipse(350, 150, -10, 180, 50, 70);
    delay(delayTime2);
    line(200,160,300,310);
    delay(delayTime2);
    line(400,160,300,310);
    delay(delayTime2);

    setfillstyle(10,4);
    floodfill(155, 200, WHITE);
    delay(delayTime2);
    setfillstyle(1,3);
    floodfill(300, 200, WHITE);
    delay(delayTime2);
        
}
