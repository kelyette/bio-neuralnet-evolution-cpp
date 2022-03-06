#ifndef CELL_H
#define CELL_H

#include "structs.h"

class Cell {
    public:
        uint32_t id;
        Pos pos;
        bool alive;
        bool reproduceable;
        int age, death; // current age, age of death (nullable)
        int phys_dna, brain_dna; // physical dna, brain dna
        int sensors, actions; // sensors, actions

        operator std::string() const { return "|"; }
        
        Cell() {
            id = 1;
            alive = true;
            reproduceable = false;
            age = 0;
            death = 10;
        }

        void next() {
            age++;
            
            if (age >= death) {
                alive = false;
            }

            step();
        }

        virtual void step() {
            pos = Pos((rand() % 1 + -1), (rand() % 1 + -1));
        }
};

#endif