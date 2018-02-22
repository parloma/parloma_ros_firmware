
#include "joint.hpp"
#include <string.h>


Joint::Joint(char *name, int pin, int min, int max):
    pin(pin)
    {
        strcpy(this->name, name);
        this->min = min;
        this->max = max;
    }


Joint::move(float pos) {
    if (pos > 1) pos = 1;
    else if (pos < 0) pos = 0;
    int ctrl = this->min + pos*(this->max-this->min);
    this->servo.write(ctrl);
}

Joint::attach() {
    this->servo.attach(this->pin);
}

Joint::detach() {
    this->servo.detach();
}

bool Joint::has_name(char* name) {
    return strcmp(this->name, name) == 0;
}