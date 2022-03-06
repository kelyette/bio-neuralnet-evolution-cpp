#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include "cell.h"
#include "grid.h"

class Environment {
    public:
        int clock;
        Grid grid;
        std::vector<Cell> cells;

        Environment() {
            clock = 0;

            for (int c = 0; c < 1; c++) {
                cells.push_back(Cell());
            }

            updateMat();
        }

        int next() {
            for (Cell &cell: cells) {
                cell.next();
            }
        }

        void updateMat() {
            for (Cell c: cells) {
                std::cout << c.pos.x << ' ';
                std::cout << c.pos.y << '\n';

                grid.set(c.pos, c.id); // TODO breaks cout for some odd reason
            }
        }
};

#endif