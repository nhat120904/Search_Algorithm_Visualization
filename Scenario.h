#pragma once
#include "Goal.h"
#include "Grid.h"
#include <vector>
#include "Cell.h"
using namespace std;
class Scenario {
public:
	Grid grid;
	Goal goals;
	Cell initialState;
	Scenario(Grid _grid, Cell _initialState, Goal goal) : grid(grid), initialState(initialState)
	{
		grid = _grid;
		goals = goal;
		initialState = _initialState;
	}
	void PrintScenario()
	{
		grid.PrintGrid();
		cout << initialState.x << " " << initialState.y << endl;
		for (auto& goal : goals.goals) {
			std::cout << goal.x << ' ' << goal.y << ' ';
		}
	}
};