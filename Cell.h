#pragma once
class Cell {
public:
	int x, y;
	int f, g, h;

	Cell(int x, int y) : x(x), y(y)
	{};
	Cell(int x, int y, int f, int g, int h) : x(x), y(y), f(f), g(g), h(h)
	{};

	bool operator>(const Cell& other) const
	{
		return f > other.f;
	}

	bool operator<(const Cell& other) const
	{
		return f < other.f;
	}
};