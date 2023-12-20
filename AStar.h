#pragma once
#include "SearchAlgorithm.h"
#include <queue>
#include <map>
#include <limits>
class AStar : public SearchAlgorithm {
public:
    AStar(Scenario scenario) : SearchAlgorithm(scenario) {}

    int heuristic(Cell cell1, Cell cell2) {
        return abs(cell1.x - cell2.x) + abs(cell1.y - cell2.y);
    }

    void Search() override {
        priority_queue<Cell, vector<Cell>, greater<Cell>> queue;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<Cell>> parent(rows, vector<Cell>(cols, Cell(-1, -1, INT_MAX, INT_MAX, INT_MAX)));
        storeNode.addCell(initialState);
        initialState.f = 0;
        initialState.g = 0;
        initialState.h = 0;

        queue.push(initialState);

        while (!queue.empty()) {
            Cell currentState = queue.top();
            queue.pop();

            int dx[] = { -1, 1, 0, 0 };
            int dy[] = { 0, 0, -1, 1 };

            for (int i = 0; i < 4; i++)
            {
                int newX = currentState.x + dx[i];
                int newY = currentState.y + dy[i];

                if (isValidCell(newX, newY, rows, cols) && scenario.grid.map[newX][newY] == 0 && !visited[newX][newY]) {
                    nodes++;
                    visited[newX][newY] = true;
                    storeNode.addCell(Cell(newX, newY));
                    int tentativeG = currentState.g + 1;

                    if (tentativeG < parent[newX][newY].g) {
                        parent[newX][newY] = currentState;
                        parent[newX][newY].g = tentativeG;
                        parent[newX][newY].h = heuristic(Cell(newX, newY), goals.goals[0]);
                        parent[newX][newY].f = tentativeG + parent[newX][newY].h;
                        queue.push(Cell(newX, newY, parent[newX][newY].f, tentativeG, parent[newX][newY].h));
                    }
                }
            }
        }

        Cell currentCell = goals.goals[0];
        storeNode.addCell(currentCell);

        while (!(currentCell.x == initialState.x && currentCell.y == initialState.y)) {
            path.addCell(currentCell);
            currentCell = parent[currentCell.x][currentCell.y];
        }
        path.addCell(initialState);

        path.reversePath();

        for (size_t i = 1; i < path.cells.size(); i++) {
            int dx = path.cells[i].x - path.cells[i - 1].x;
            int dy = path.cells[i].y - path.cells[i - 1].y;
            if (dx == -1) actions.push_back("up");
            else if (dx == 1) actions.push_back("down");
            else if (dy == -1) actions.push_back("left");
            else if (dy == 1) actions.push_back("right");
        }

    }
};
