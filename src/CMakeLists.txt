add_executable(MPKeypad
        main.cpp
        matrix/matrix.cpp matrix/matrix.h
        rotary/rotary.cpp rotary/rotary.h
        keyboard/keyboard.cpp keyboard/keyboard.h
        )

target_sources(MPKeypad PUBLIC
        main.cpp
        keyboard/usb_descriptors.c
        )

target_include_directories(MPKeypad PUBLIC keyboard)

pico_enable_stdio_usb(MPKeypad 0)
pico_enable_stdio_uart(MPKeypad 1)

target_link_libraries(MPKeypad pico_stdlib tinyusb_device tinyusb_board)

pico_add_extra_outputs(MPKeypad)