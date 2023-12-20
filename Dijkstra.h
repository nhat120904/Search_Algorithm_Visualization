#pragma once
#include "SearchAlgorithm.h"
#include <queue>
class Dijkstra : public SearchAlgorithm
{
public:
	Dijkstra(Scenario scenario) : SearchAlgorithm(scenario) {}

	int heuristic(Cell cell1, Cell cell2) {
		return abs(cell1.x - cell2.x) + abs(cell1.y - cell2.y);
	}

	void Search() override
	{
		priority_queue<Cell, vector<Cell>, greater<Cell>> queue;
		vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
		vector<vector<Cell>> parent(rows, vector<Cell>(cols, Cell(-1, -1)));
		initialState.f = 0;
		distance[initialState.x][initialState.y] = 0;
		storeNode.addCell(initialState);
		queue.emplace(initialState);
		while (!queue.empty())
		{
			Cell currentState = queue.top();
			queue.pop();

			if (isGoal(currentState, goals))
			{
				while (currentState.x != -1 && currentState.y != -1)
				{
					storeNode.addCell(currentState);
					path.addCell(currentState);
					currentState = parent[currentState.x][currentState.y];
				}

			}

			int dx[] = { -1, 1, 0, 0 };
			int dy[] = { 0, 0, -1, 1 };

			for (int i = 0; i < 4; i++)
			{
				int newX = currentState.x + dx[i];
				int newY = currentState.y + dy[i];

				if (isValidCell(newX, newY, rows, cols) && scenario.grid.map[newX][newY] == 0 && currentState.f + 1 < distance[newX][newY])
				{
					nodes++;
					distance[newX][newY] = currentState.f + 1;
					Cell newState(newX, newY, distance[newX][newY], 0, 0);
					queue.emplace(newState);
					storeNode.addCell(newState);
					parent[newX][newY] = currentState;
				}
			}

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

};