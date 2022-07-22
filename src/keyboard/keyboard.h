#ifndef MPKEYPAD_KEYBOARD_H
#define MPKEYPAD_KEYBOARD_H

#include "pico/stdlib.h"
#include <set>


class keyboard {
public:
    keyboard();
    void run();
    bool press(uint8_t keycode);
    bool release(uint8_t keycode);
    bool releaseAll();
private:
    std::set<uint8_t> pressed;
    void pressAll();
};


#endif //MPKEYPAD_KEYBOARD_H
