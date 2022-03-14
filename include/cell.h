#pragma once

#include "structs.h"

class Cell {
    public:
        uint32_t id;
        bool active;
        Pos pos;
        bool alive;
        bool reproduceable;
        int age, death; // current age, age of death (nullable)
        int phys_dna, brain_dna; // physical dna, brain dna
        int sensors, actions; // sensors, actions
        
        Cell(bool active_) {
            active = active_;
            if (active_)
                Cell();
        }

        Cell() {
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

        void activate() { active = true; Cell(); }

        virtual void step() {
            pos = Pos((rand() % 1 + -1), (rand() % 1 + -1));
        }
};