#pragma once

#include <vector>
#include "structs.h"
#include "cell.h"
#include "cells.h"

const uint32_t EMPTY = 0;
const uint32_t BARRIER = 0xffffffff; // 32 bits max

class Grid {
    public:
        struct Row {
            Row(uint32_t nCols) : data { std::vector<uint32_t>(nCols, 0) } { }

            void zero_fill() { std::fill(data.begin(), data.end(), EMPTY); }
            uint32_t &operator[](uint32_t nCol) { return data[nCol]; }
            uint32_t size() { return data.size(); }

            private:
                std::vector<uint32_t> data;
        };

        Grid() { 
            std::vector<Cell> cells(0xffffffff-1);
            std::fill(cells.begin(), cells.end(), Cell(false));
            for (int i = 0; i < cells.size(); i++) 
                cells[i].id = i;
        }
        
        Row &operator[](uint32_t nRow) { return data[nRow]; }
        uint32_t sixeX() { return data.size(); }
        uint32_t sizeY() { return data[0].size(); }

        Cell get_cell(uint32_t id) { return cells[id]; }
        Cell at(Pos pos) { return cells[data[pos.y][pos.x]]; }
        void set(Pos pos, uint32_t val) { data[pos.y][pos.x] = val; }
        void add_cell(Cell& cell, uint32_t id) { cells[id] = cell; }
        void add_cell(Cell& cell) { // TODO
            uint32_t first_empty_index;
            for (uint32_t i = 1; i < cells.size() + 1; i++) {
                if (cells[i].id == EMPTY) first_empty_index = i;
            }
            cells[first_empty_index] = cell;
        }
        // void print() { for (Row &r: data) { for (int i; i < r.size(); i++) { std::cout << r[i] << std::endl; } }; }

    private:
        std::vector<Row> data;
        Cells cells;
};