#pragma once

#include <vector>
#include "cell.h"

class Cells {
    public:
        Cells();
        
        Cell &operator[](uint32_t index) { return data[index]; }
        uint32_t size() { return data.size(); }
        
    private:
        std::vector<Cell> data;
};