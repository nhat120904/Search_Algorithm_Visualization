#pragma once

#include <vector>

class Walls {
public:
    struct Wall {
        int x, y, w, h;
    };

    std::vector<Wall> walls;

    void addWall(int x, int y, int w, int h)
    {
        Wall wall{ x, y, w, h };
        walls.push_back(wall);
    };
};
