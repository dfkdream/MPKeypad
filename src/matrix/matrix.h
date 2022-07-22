#ifndef MPKEYPAD_MATRIX_H
#define MPKEYPAD_MATRIX_H

#include "pico/stdlib.h"
#include <vector>
#include <bitset>

namespace matrix {

    class matrix {
    public:
        matrix(std::vector<uint> rows, std::vector<uint> cols, void (*onPress)(uint), void (*onRelease)(uint));
        ~matrix();
        void scan();
    private:
        std::vector<uint> rows, cols;
        std::vector<bool> state;
        void (*onPress)(uint);
        void (*onRelease)(uint);
    };

} // matrix

#endif //MPKEYPAD_MATRIX_H
