#include <iostream>
#include "pico/stdlib.h"
#include "pico/binary_info.h"

#include <vector>

#include "matrix/matrix.h"
#include "rotary/rotary.h"
#include "keyboard/keyboard.h"

#include "tusb.h"

const uint keys[]{HID_KEY_A, HID_KEY_B, HID_KEY_C, HID_KEY_D,
            HID_KEY_E, HID_KEY_ARROW_UP, HID_KEY_G, HID_KEY_H,
            HID_KEY_ARROW_LEFT, HID_KEY_ARROW_DOWN, HID_KEY_ARROW_RIGHT, HID_KEY_ENTER};

keyboard kbd;

void onChange(const rotary::direction direction){
    std::cout<<((direction==rotary::clockwise)?"CW":"CCW")<<std::endl;
}

void onPress(uint i){
    std::cout<<"Press "<<i<<std::endl;
    kbd.press(keys[i]);
}

void onRelease(uint i){
    std::cout<<"Release "<<i<<std::endl;
    kbd.release(keys[i]);
}

void r_onPress(){
    std::cout<<"r_Press"<<std::endl;
}

void r_onRelease(){
    std::cout<<"r_Release"<<std::endl;
}

int main() {
    stdio_init_all();

    auto rows = std::vector<uint>{18, 17, 16};
    auto cols = std::vector<uint>{15, 13, 14, 12};

    rotary::rotary ro(20, onChange, r_onPress, r_onRelease);
    matrix::matrix mat(rows, cols, onPress, onRelease);

    while (true){
        kbd.run();
        ro.scan();
        mat.scan();
    }
}
