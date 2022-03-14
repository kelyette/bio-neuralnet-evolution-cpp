#pragma once

#include <stdlib.h>
#include <iostream>
#include "environment.h"

class Simulation {
    public:
        Environment env;

        Simulation() {
            env = Environment();
        }
};