#ifndef SIMULATION_H
#define SIMULATION_H

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

#endif