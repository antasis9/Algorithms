#include "SparseMatrix.h"
#include <iostream>

using namespace std;


SparseMatrix::SparseMatrix(int rows, int columns, int** items)
{
	this->rows = rows;
	this->columns = columns;
	this->terms = 0;

	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			int item = items[row][column];

			if (item != 0) {
				// Create new matrix term
				MatrixTerm* term = new MatrixTerm();
				term->row = row;
				term->col = column;
				term->value = item;

				this->items[this->terms++] = *term;
			}
		}
	}
}


SparseMatrix::~SparseMatrix()
{
	this->rows = 0;
	this->columns = 0;
	
	/*for (int i = 0; i < terms; i++) {
		delete &(items[i]));
	}*/
}


SparseMatrix SparseMatrix::Transpose()
{
	return *this;
}


SparseMatrix SparseMatrix::Add(SparseMatrix b)
{
	return b;
}


SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
{
	return b;
}


void SparseMatrix::Dump()
{
	cout << "Rows: " << rows << ", Columns: " << columns << ", Terms: " << terms << endl;

	for (int i = 0; i < terms; i++) {
		MatrixTerm term = items[i];

		cout << "Row:\t" << term.row << ", Column:\t" << term.col << ", Value:\t" << term.value << endl;
	}
}
