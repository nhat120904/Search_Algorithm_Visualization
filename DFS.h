#pragma once
#include "SearchAlgorithm.h"
#include <stack>
class DFS : public SearchAlgorithm
{
public:
    Path storeNode;
    DFS(Scenario scenario) : SearchAlgorithm(scenario)
    {}
    Path path;

    void Search() override
    {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        stack<Cell> stack;
        vector<vector<Cell>> parent(rows, vector<Cell>(cols, Cell(-1, -1)));
        storeNode.addCell(initialState);
        stack.push(initialState);
        visited[initialState.x][initialState.y] = true;

        while (!stack.empty())
        {
            Cell currentState = stack.top();

            if (isGoal(currentState, goals))
            {
                storeNode.addCell(currentState);
                while (currentState.x != -1 && currentState.y != -1)
                {
                    path.addCell(currentState);
                    currentState = parent[currentState.x][currentState.y];
                }
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

            bool found = false;
            int dx[] = { -1, 1, 0, 0 };
            int dy[] = { 0, 0, -1, 1 };
            for (int i = 0; i < 4; i++)
            {
                int newX = currentState.x + dx[i];
                int newY = currentState.y + dy[i];
                if (isValidCell(newX, newY, rows, cols) && scenario.grid.map[newX][newY] == 0 && !visited[newX][newY])
                {
                    nodes++;
                    visited[newX][newY] = true;
                    storeNode.addCell(Cell(newX, newY));
                    parent[newX][newY] = currentState;
                    stack.push(Cell(newX, newY));
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                stack.pop();
            }

        }
    }
};