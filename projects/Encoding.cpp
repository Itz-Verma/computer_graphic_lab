#include <string>
#include <graphics.h>
class Encoding {
    protected:
        std::string signal;
        int logicHigh = -50;
        int logicLow = 50;
        int base = 0;
        int distance = 20;
        int posX = 100;
        int posY = 300;

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

