#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <limits>
#include "SearchAlgorithm.h"

class IDDFS : public SearchAlgorithm {
public:
    IDDFS(Scenario scenario) : SearchAlgorithm(scenario) {}
    Path storeNode;
    void Search() override {
        int maxDepth = 0;
        bool found = false;
        storeNode.addCell(initialState);
        while (true) {
            Path path1;
            if (dfs(initialState, maxDepth, path1)) {
                path1.reversePath();
                for (size_t i = 1; i < path1.cells.size(); i++) {
                    int dx = path1.cells[i].x - path1.cells[i - 1].x;
                    int dy = path1.cells[i].y - path1.cells[i - 1].y;
                    if (dx == -1) actions.push_back("up");
                    else if (dx == 1) actions.push_back("down");
                    else if (dy == -1) actions.push_back("left");
                    else if (dy == 1) actions.push_back("right");
                }
                found = true;
            }
            if (found)
            {
                path = path1;
                break;
            }
            maxDepth++;
        }

    }

    bool dfs(Cell start, int maxDepth, Path& path) {
        std::stack<std::pair<Cell, int>> stack;
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        vector<vector<Cell>> parent(rows, vector<Cell>(cols, Cell(-1, -1)));
        stack.push(std::make_pair(start, 0));

        while (!stack.empty())
        {
            Cell currentState = stack.top().first;
            int depth = stack.top().second;
            stack.pop();

            if (isGoal(currentState, goals)) {
                while (currentState.x != -1 && currentState.y != -1)
                {
                    storeNode.addCell(currentState);
                    path.addCell(currentState);
                    currentState = parent[currentState.x][currentState.y];
                }
                return true; // Goal found
            }

            if (depth >= maxDepth) {
                continue; // Reached depth limit for this branch
            }

            visited[currentState.x][currentState.y] = true;

            int dx[] = { -1, 1, 0, 0 };
            int dy[] = { 0, 0, -1, 1 };

            for (int i = 0; i < 4; i++) {
                int newX = currentState.x + dx[i];
                int newY = currentState.y + dy[i];
                Cell newState(newX, newY);

                if (isValidCell(newX, newY, rows, cols) &&
                    scenario.grid.map[newX][newY] == 0 && !visited[newX][newY])
                {
                    nodes++;
                    stack.push(std::make_pair(newState, depth + 1));
                    parent[newX][newY] = currentState;
                    visited[newX][newY] = true;
                    storeNode.addCell(Cell(newX, newY));
                }
            }
        }

        return false; // Goal not found within the depth limit
    }
};
