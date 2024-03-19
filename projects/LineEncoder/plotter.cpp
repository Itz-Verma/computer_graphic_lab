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
        virtual void draw() = 0;
        virtual void one() {}
        virtual void zero() {};

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

                delay(delayTime);
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
class RZ : Encoding {
    public:
        explicit RZ(std::string sgn) : Encoding(sgn) {
            setcolor(MAGENTA);
        };


        void title() {
            outtextxy(300, 100, (char *) "RZ Encoding");
        }

        void draw() {
            for (char c: signal) {
                if (c == '1')
                    one();
                else
                    zero();

                delay(delayTime);
            }
        }


        void zero() {
            signalShift(posX, 300 + logicLow);
            signalMove(distance/2, 0);
            signalShift(posX, 300  + base);
            signalMove(distance/2, 0);
        }

        void one() {
            signalShift(posX, 300 + logicHigh);
            signalMove(distance/2, 0);
            signalShift(posX, 300 + base);
            signalMove(distance/2, 0);
        }
};

class Bipolar : Encoding {
    private:

        int prev = 0;

    public:
        explicit Bipolar(std::string sgn) : Encoding(sgn) {
            setcolor(BROWN);
        };
        void title() {
            outtextxy(300, 100, (char *) "Bipolar Encoding");
        }

        void draw() {
            for (char c: signal) {
                if (c == '1') {
                    one(prev);
                    prev = (prev == 0) ? 1 : 0;
                }
                else
                    zero();

                delay(delayTime);
            }
        }

        void zero() {
            signalShift(posX, 300 + base);
            signalMove(distance, 0);
        }

        void one(int num) {
            if (num == 0) {
                signalShift(posX, 300 + (logicHigh));
                signalMove(distance, 0);
            }
            else {
                signalShift(posX, 300 + (logicLow));
                signalMove(distance, 0);
            }
        }
};

class Manchester : Encoding {
    public:
        explicit Manchester(std::string sgn) : Encoding(sgn) {
            setcolor(CYAN);
        };
        void title() {
            outtextxy(200, 100, (char *) "Manchester Encoding");
        }

        void draw() {
            for (char c: signal) {
                if (c == '1')
                    one();
                else
                    zero();

                delay(delayTime);
            }
        }

        void zero() {
            signalShift(posX, 300 + logicHigh);
            signalMove(distance/2, 0);
            signalShift(posX, 300 + logicLow);
            signalMove(distance/2, 0);
        }

        void one() {
            signalShift(posX, 300 + logicLow);
            signalMove(distance/2, 0);
            signalShift(posX, 300 + logicHigh);
            signalMove(distance/2, 0);
        }
};

class Diff_Manchester : Encoding {
    int prev = 2;

    public:
    explicit Diff_Manchester(std::string sgn) : Encoding(sgn) {
        setcolor(LIGHTGREEN);
    };

    void title() {
        outtextxy(100, 100, (char *) "Differential Manchester Encoding");
    }
    void draw() {
        for (char c: signal) {
            if (c == '1') {
                int n = (prev == 2 ? 1 : 2);
                pattern(n);
                prev = n;
            } else 
                pattern(prev);

            delay(delayTime);
        }
    }

    void pattern(int num) {
        if (num == 2) {
            signalShift(posX, 300 + logicLow);
            signalMove(distance/2, 0);
            signalShift(posX, 300 + logicHigh);
            signalMove(distance/2, 0);
        } else if (num == 1) {
            signalShift(posX, 300 + logicHigh);
            signalMove(distance/2, 0);
            signalShift(posX, 300 + logicLow);
            signalMove(distance/2, 0);
        }
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
                   Bipolar signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }
        case 5:{
                   RZ signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }

        case 6:{
                   Manchester signal(sgn);
                   signal.title();
                   signal.draw();
                   break;
               }

        case 7:{
                   Diff_Manchester signal(sgn);
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
