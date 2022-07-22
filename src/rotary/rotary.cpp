#include "rotary.h"

const uint8_t mask = 0x03;
const uint8_t mask3 = 0x3F;

namespace rotary{
    rotary::rotary(uint pin, callbackWithDirection onChange, callback onPress, callback onRelease):
            pin(pin), onChange(onChange), onPress(onPress), onRelease(onRelease) {
        gpio_init(pin);
        gpio_set_dir(pin, GPIO_IN);
        gpio_pull_down(pin);

        gpio_init(pin+1);
        gpio_set_dir(pin+1, GPIO_IN);
        gpio_pull_down(pin+1);

        gpio_init(pin+2);
        gpio_set_dir(pin+2, GPIO_IN);
        gpio_pull_down(pin+2);
    }

    void rotary::scan() {
        bool pState = !gpio_get(pin+2);
        if (pushState!=pState){
            pushState = pState;
            (pushState?onPress:onRelease)();
        }

        uint8_t new_rotary_values = 0;
        new_rotary_values|=gpio_get(pin);
        new_rotary_values<<=1;
        new_rotary_values|=gpio_get(pin+1);

        if ((rotary_values&mask) == new_rotary_values) return;

        rotary_values<<=2;
        rotary_values|=new_rotary_values;

        if ((rotary_values&mask3)==33) onChange(clockwise);
        if ((rotary_values&mask3)==18) onChange(counterClockwise);
    }
}


