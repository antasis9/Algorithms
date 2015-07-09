#include "Maze.h"
#include <iostream>

using namespace std;

/*class Point {
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
};*/

Point::Point(int x, int y) {
	this->X = x;
	this->Y = y;
}

Maze::Maze() {
	stack = new Stack<Point>(1000);
	flags = NULL;
}

Maze::~Maze() { }

bool Maze::IsVisited(int x, int y) {
	if (flags[y][x] != NULL) {
		return true;
	}
	else {
		return false;
	}
}

void Maze::Visited(int x, int y) {
	flags[y][x] = '1';
}

void Maze::Search(char maze[][MAZE_COLUMN_COUNT], int row) {
	flags = new char*[row];
	for (int rowIndex = 0; rowIndex < row; rowIndex++) {
		flags[rowIndex] = new char[MAZE_COLUMN_COUNT];

		for (int columnIndex = 0; columnIndex < MAZE_COLUMN_COUNT; columnIndex++) {
			flags[rowIndex][columnIndex] = NULL;
		}
	}

	stack->Add(Point(0, 0));

	while (true) {
		Point currentPoint;

		if (stack->IsEmpty()) {
			cout << "The stack is empty." << endl;

			break;
		}

		stack->Delete(currentPoint);

		cout << "Visit to (" << currentPoint.Y << ", " << currentPoint.X << ")" <<  endl;

		// 이미 방문한 내역이 있는 곳
		if (IsVisited(currentPoint.X, currentPoint.Y)) {
			cout << "	Already visited (" << currentPoint.Y << ", " << currentPoint.X << ")" << endl;
			continue;
		}
		else {
			Visited(currentPoint.X, currentPoint.Y);
		}

		// 출구
		if (
			currentPoint.X == MAZE_COLUMN_COUNT - 1 &&
			currentPoint.Y == row - 1) {
			cout << "Exit -----" << endl;
			break;
		}

		for (int rowRelativeIndex = -1; rowRelativeIndex < 2; rowRelativeIndex++) {
			for (int columnRelativeIndex = -1; columnRelativeIndex < 2; columnRelativeIndex++) {
				int row = currentPoint.Y + rowRelativeIndex;
				int column = currentPoint.X + columnRelativeIndex;

				if (row < 0 || column < 0) {
					continue;
				}

				if (row == currentPoint.Y && column == currentPoint.X) {
					continue;
				}

				if (maze[row][column] == '1') {
					stack->Add(Point(column, row));
				}
			}
		}
	}
}