#ifndef GRID_H
#define GRID_H

#include <vector>
#include "structs.h"

const uint32_t EMPTY = 0;
const uint32_t BARRIED = 0xffffffff;

class Grid {
    public:
        struct Row {
            Row(uint32_t nCols) : data { std::vector<uint32_t>(nCols, 0) } { }

            void zeroFill() { std::fill(data.begin(), data.end(), 0); }
            uint32_t &operator[](uint32_t nCol) { return data[nCol]; }
            uint32_t size() { return data.size(); }

            private:
                std::vector<uint32_t> data;
        };

        uint32_t sixeX() { return data.size(); }
        uint32_t sizeY() { return data[0].size(); }
        void set(Pos pos, uint32_t val) { data[pos.y][pos.x] = val; }
        Row &operator[](uint32_t nRow) { return data[nRow]; }
        // void print() { for (Row &r: data) { for (int i; i < r.size(); i++) { std::cout << r[i] << std::endl; } }; }

    private:
        std::vector<Row> data;
};

#endif