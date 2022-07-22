#include "keyboard.h"

#include "bsp/board.h"
#include "tusb.h"

#include "usb_descriptors.h"
#include <iostream>

void tud_mount_cb(void)
{
    std::cout<<"Mounted"<<std::endl;
}

// Invoked when sent REPORT successfully to host
// Application can use this to send the next report
// Note: For composite reports, report[0] is report ID
void tud_hid_report_complete_cb(uint8_t instance, uint8_t const* report, uint8_t len)
{
    (void) instance;
    (void) len;

    std::cout<<"REPORT_COMPLETE_CB "<<(int)report[0]<<std::endl;
}

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request
uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen)
{
    // TODO not Implemented
    (void) instance;
    (void) report_id;
    (void) report_type;
    (void) buffer;
    (void) reqlen;

    return 0;
}

// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )
void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize)
{
    (void) instance;
    (void) report_type;
    (void) buffer;
    (void) bufsize;
    (void) buffer;
    std::cout<<"SET_REPORT_CB "<<(int)report_id<<" "<<(int)buffer[0]<<std::endl;

}

keyboard::keyboard() {
    board_init();
    tusb_init();
}

void keyboard::run() {
    tud_task();
}

bool keyboard::press(uint8_t keycode) {
    auto inserted = pressed.insert(keycode).second;
    if (inserted) pressAll();
    return inserted;
}

bool keyboard::release(uint8_t keycode) {
    auto erased = pressed.erase(keycode);
    if (erased) pressAll();
    return erased;
}

bool keyboard::releaseAll() {
    bool isEmpty = pressed.empty();
    if (!isEmpty) {
        pressed.clear();
        pressAll();
    }
    return !isEmpty;
}

void keyboard::pressAll() {
    uint8_t keycodes[6] = {0, };
    int idx = 0;
    for (auto i: pressed){
        if (idx>5) break;
        keycodes[idx++] = i;
    }
    tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keycodes);
}
