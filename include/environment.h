#pragma once

#include <vector>
#include "cell.h"
#include "grid.h"

class Environment {
    public:
        int clock;
        Grid grid;

        Environment() {
            clock = 0;
        }

        int next() {
            
        }
};