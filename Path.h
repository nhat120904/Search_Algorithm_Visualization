#pragma once
#include <vector>
#include "Cell.h"
using namespace std;
class Path {
public:
	vector<Cell> cells;
	Path()
	{};
	Path(const vector<Cell>& cells) : cells(cells)
	{}

	void addCell(const Cell& cell)
	{
		cells.push_back(cell);
	}

	bool isEmpty() const
	{
		return cells.empty();
	}

	void reversePath()
	{
		reverse(cells.begin(), cells.end());
	}

	void popCell()
	{
		cells.pop_back();
	}

	void clear()
	{
		cells.clear();
	}
};