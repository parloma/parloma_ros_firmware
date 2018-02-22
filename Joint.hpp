#ifndef __JOINT__
#define __JOINT__

#include <Servo.h>

class Joint {
    public:
        char name[20];
        Joint(char *name, int pin, int min = 0, int max = 180);
        move(float pos);
        attach();
        detach();
        bool has_name(char* name);

    private:
        Servo servo;
        int min;
        int max;
        int pin;
};

#endif