#include "matrix.h"

namespace matrix {
    matrix::matrix(std::vector<uint> rows, std::vector<uint> cols, void (*onPress)(uint), void (*onRelease)(uint)):
    rows(rows), cols(cols), onPress(onPress), onRelease(onRelease){
        for (auto r:rows) {
            gpio_init(r);
            gpio_set_dir(r, GPIO_OUT);
        }

        for (auto c: cols) {
            gpio_init(c);
            gpio_set_dir(c, GPIO_IN);
            gpio_pull_down(c);
        }

        state.resize(rows.size()*cols.size(), false);
    }

    matrix::~matrix() {
        for (auto r:rows) {
            gpio_deinit(r);
        }

        for (auto c: cols) {
            gpio_deinit(c);
        }
    }

    void matrix::scan() {
        uint i=0;

        for (auto r: rows){
            gpio_put(r, true);
            sleep_us(1);

            for(auto c: cols){
                auto v = gpio_get(c);
                if (v!=state[i]){
                    (v?onPress:onRelease)(i);
                    state[i]=v;
                }
                i++;
            }
            gpio_put(r, false);
        }
    }

} // matrix