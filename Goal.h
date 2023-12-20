#pragma once
#include <vector>
#include "Cell.h"
class Goal {
public:
    std::vector<Cell> goals;
    void addGoal(Cell cell) {
        goals.emplace_back(cell);
    }
};