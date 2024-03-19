#include <SDL2/SDL_bgi.h>
#include <graphics.h>
#include <iostream>
#include <string>

int gd, gm;
int posX = 50, posY  = 300;
int delayTime = 300;

void drawAxes() {
    line(0, posY, 640, posY);
    line(posX,posY - 200,posX,posY+200);
    settextstyle(1,0, 5);
    outtextxy(5, posY+10, (char*) "X");
    outtextxy(posX - 5, posY - 250, (char*) "Y");
}

void initGraph() {
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    drawAxes();
}

std::string getSignal() {
    std::string signal;
    std::cout<<"Enter signal to be coded: ";
    std::cin>>signal;
    return signal;
}

int getEncoding() {
    int choice;
    std::cout<<"Choose Encoding Sceme:"<<std::endl;
    std::cout<<"1. Unipolar NRZ:\n2. Polar NRZ:\n3. NRZ Inverted\n4. Bipolar\n5. RZ\n6. Manchester\n7. Differential Manchester"<<std::endl;
    std::cin>>choice;
    return choice;
}


class Encoding {
    protected:
        std::string signal;
        int logicHigh = -50;
        int logicLow = 50;
        int base = 0;
        int distance = 20;

    public:
        explicit Encoding(std::string sgn){
            signal = sgn;
        }

        void signalMove(int offsetX, int offsetY){
            line(posX, posY, posX+offsetX, posY+offsetY);
            posX += offsetX;
            posY += offsetY;
        }

        void signalShift(int newX, int newY) {
            line(posX, posY, newX, newY);
            posX = newX;
            posY = newY;
        }

        virtual void title() = 0;
        virtual void zero() = 0;
        virtual void one() = 0;
        virtual void draw() = 0;

};

class Unipolar_NRZ : Encoding {
    private:
        int logicLow = 0;
    public:
        explicit Unipolar_NRZ(std::string sgn): Encoding(sgn){
            setcolor(RED);
        };
        void title() {
            outtextxy(300, 100, (char *) "Unipolar NRZ Encoding");
        }

        void draw() {

            for(char c: signal) {
                if(c=='1')
                    one();
                else
                    zero();
                delay(delayTime);
            }
        }

        void zero() {
            signalShift(posX, 300+logicLow);
            signalMove(distance,0);
        }

        void one() {
            signalShift(posX, 300+logicHigh);
            signalMove(distance,0);
        }


};

class Polar_NRZ : Encoding {
    public:
        explicit Polar_NRZ(std::string sgn) : Encoding(sgn){
            setcolor(BLUE);
        };

        void draw() {
            for(char c: signal) {
                if(c=='1')
                    one();
                else
                    zero();
                delay(delayTime);
            }
        }

        void title() {
            outtextxy(300, 100, (char *) "Polar NRZ Encoding");
        }

        void zero() {
            signalShift(posX, 300+logicLow);
            signalMove(distance,0);
        }

        void one() {
            signalShift(posX, 300+logicHigh);
            signalMove(distance,0);
        }


};

class NRZ_I : Encoding {
    public:
        explicit NRZ_I(std::string sgn) : Encoding(sgn) {
            setcolor(GREEN);
        }

         void title() {
            outtextxy(300, 100, (char *) "NRZ Inverted Encoding");
        }
        void draw() {
            posY = 300 + logicHigh;
            for(char c: signal) {
                if(c=='1')
                    one();
                else
                    zero();
            }
        }

        void zero() {
            signalMove(distance, 0);
        }

        void one() {
            if(posY == 300 + logicLow)
                signalShift(posX, 300+logicHigh);
            else if(posY == 300 + logicHigh)
                signalShift(posX, 300 + logicLow);
            signalMove(distance, 0);
        }
};

void errorMsg();
int main() {
    std::string sgn;
    int c;
    sgn = getSignal();
    c = getEncoding();

    initGraph();

    switch (c) {
        case 1:{
                   Unipolar_NRZ signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }

        case 2:{
                   Polar_NRZ signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }
        case 3:{
                   NRZ_I signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }

        case 4:{
                   Polar_NRZ signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }
        case 5:{
                   Unipolar_NRZ signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }

        case 6:{
                   Polar_NRZ signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }

        case 7:{
                   Polar_NRZ signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }
        default: {
                     errorMsg();
                     break;
                 }
    }
    getch();
    closegraph();
}

void errorMsg(){
    setcolor(RED);
    cleardevice();
    settextstyle(3,0, 6);
    outtextxy(250, 250, (char *)"INVALID INPUT!");
    settextstyle(1, 0, 3);
    outtextxy(0, 550, (char *)"Press any key to exit.");

}
