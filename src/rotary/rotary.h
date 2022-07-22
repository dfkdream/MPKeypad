#ifndef MPKEYPAD_ROTARY_H
#define MPKEYPAD_ROTARY_H

#include "pico/stdlib.h"

namespace rotary{
    enum direction {clockwise, counterClockwise};
    typedef void (*callback)();
    typedef void (*callbackWithDirection)(const direction);

    class rotary {
    public:
        rotary(uint pin, callbackWithDirection onChange, callback onPress, callback onRelease);
        void scan();
    private:
        callbackWithDirection onChange;
        callback onPress;
        callback onRelease;
        uint8_t rotary_values = 0;
        uint pin;
        bool pushState = false;
    };
}

#endif //MPKEYPAD_ROTARY_H
