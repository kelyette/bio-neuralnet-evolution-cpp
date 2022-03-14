#pragma once

struct Pos {
    uint32_t x;
    uint32_t y;

    Pos() {
        x = 0;
        y = 0;
    }

    Pos(uint32_t x_, uint32_t y_) {
        x = x_;
        y = y_;
    }
};