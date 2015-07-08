#pragma once

#include "Stack.h"

#define MAZE_COLUMN_COUNT 5

class Point {
public:
	inline Point() { };
	Point(int x, int y);

	int X;
	int Y;
};

class Maze
{
public:
	Maze();
	~Maze();
	void Search(char maze[][MAZE_COLUMN_COUNT], int row);

private:
	Stack<Point>* stack;
	char** flags;
	bool IsVisited(int x, int y);
	void Visited(int x, int y);
};
