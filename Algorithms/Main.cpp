#include <iostream>
#include "SparseMatrix.h"

using namespace std;

#define	ROWS	5
#define	COLUMNS	6

int main() {
	int temp[ROWS][COLUMNS] = {
		{ 0, 1, 0, 3, 4, 5 },
		{ 0, 0, 2, 0, 4, 5 },
		{ 0, 0, 2, 0, 0, 0 },
		{ 0, 0, 2, 0, 4, 5 },
		{ 0, 0, 2, 0, 4, 5 },
	};

	int** items = new int*[ROWS];
	for (int row = 0; row < ROWS; row++) {
		items[row] = new int[COLUMNS];

		for (int column = 0; column < COLUMNS; column++) {
			items[row][column] = temp[row][column];
		}
	}

	SparseMatrix matrix(ROWS, COLUMNS, items);
	matrix.Dump();

	return 0;
}