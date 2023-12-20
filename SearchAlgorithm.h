#pragma once
#include <string>
#include "Scenario.h"
#include "Path.h"
using namespace std;
class SearchAlgorithm {
public:

	Scenario scenario;
	int rows, cols;
	Goal goals;
	Cell initialState;
	Path storeNode;
	vector<string> actions;
	Path path;
	int nodes;
	SearchAlgorithm(Scenario scenario) : scenario(scenario), initialState(0, 0)
	{
		scenario = scenario;
		initialState = scenario.initialState;
		goals = scenario.goals;
		rows = scenario.grid.rows;
		cols = scenario.grid.cols;
		nodes = 1;
	}
	bool isGoal(Cell cell, Goal goals)
	{
		for (auto goal : goals.goals)
		{
			if (cell.x == goal.x && cell.y == goal.y)
			{
				return true;
			}
		}
		return false;
	}

	bool isValidCell(int x, int y, int rows, int cols) {
		return (x >= 0 && x < rows && y >= 0 && y < cols);
	}

	virtual void Search() = 0;
};