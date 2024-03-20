#include <SDL2/SDL_bgi.h>
#include <cstdint>
#include<iostream>
#include <graphics.h>
#include <string>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

using  namespace std;

string getString(){
    cout<<"Enter a string: ";
    string s;
    cin>>s;
    s.append("      ");
    return s;
}

void updateXYnSpeed(int& x, int& y, int& xSpeed, int& ySpeed){
    if(x< 0 || x >= WINDOW_WIDTH - 100)
        xSpeed = -xSpeed;
    if(y< 0 || y >= WINDOW_HEIGHT - 100)
        ySpeed = -ySpeed;
    x += xSpeed;
    y += ySpeed;


}

void rotate(string& s){
    char c = s[0];
    s.erase(s.begin());
    s.push_back(c);
}

char* toCharStar(const string& s){
    const char *ret = s.c_str();
    return (char*) ret;
}

int main() {
    
    string s = getString();
    int gd  = DETECT, gm;
    initgraph(&gd,&gm,NULL); 
    initwindow(WINDOW_WIDTH,WINDOW_HEIGHT);
    int x = 0, y = 0, xSpeed = 50, ySpeed = -5; 
    setcolor(LIGHTBLUE);
    settextstyle(3, 0, 10);// settextstyle(int fontType, int direction, int fontSize)
                           // direction = 0 -> horizontal, 1 -> vertical
    while (!xkb_hit()){
        outtextxy(x, y, toCharStar(s));
        delay(200);
        cleardevice();
        updateXYnSpeed(x,y,xSpeed,ySpeed);
        rotate(s);

    }

}

/* If on key press program does not terminates then click on the window heaader couples of time and click on any 
 * key on the keyboard wait for a while and xkb_hit will work
 */
