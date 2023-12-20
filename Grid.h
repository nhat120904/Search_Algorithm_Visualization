#pragma once
#include "Wall.h"
#include <iostream>
class Grid {
public:
	int rows, cols;
	Walls walls;
	std::vector<std::vector<int>> map;
	Grid(int Rows, int Cols, Walls Walls)
	{
		rows = Rows;
		cols = Cols;
		walls = Walls;
	}
	void Initialize(int rows, int cols) {
		map = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));

		for (const Walls::Wall& wall : walls.walls)
		{
			for (int i = wall.x; i < wall.x + wall.w; ++i)
			{
				for (int j = wall.y; j < wall.y + wall.h; ++j)
				{
					if (i >= 0 && i < cols && j >= 0 && j < rows)
					{
						map[j][i] = 1;
					}
				}
			}
		}
	}
	void PrintGrid() {
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				std::cout << map[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};