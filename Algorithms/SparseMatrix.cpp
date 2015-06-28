#include "SparseMatrix.h"
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int rows, int columns) {
	this->rows = rows;
	this->columns = columns;
}

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

				this->items[this->terms++] = term;
			}
		}
	}
}


SparseMatrix::~SparseMatrix()
{
	this->rows = 0;
	this->columns = 0;
	
	for (int i = 0; i < terms; i++) {
		MatrixTerm* term = this->items[i];

		delete term;
	}
}


SparseMatrix* SparseMatrix::Transpose()
{
	SparseMatrix* transposeMatrix = new SparseMatrix(columns, rows);

	for (int column = 0; column < this->columns; column++) {
		for (int i = 0; i < terms; i++) {
			MatrixTerm* term = this->items[i];
		
			if (term->col == column) {
				MatrixTerm* newTerm = new MatrixTerm();
				newTerm->row = term->col;
				newTerm->col = term->row;
				newTerm->value = term->value;

				transposeMatrix->items[transposeMatrix->terms++] = newTerm;
			}
		}
	}

	return transposeMatrix;
}

SparseMatrix* SparseMatrix::FastTranspose() {
	SparseMatrix* transposeMatrix = new SparseMatrix(columns, rows);

	int* rowSize = new int[columns];
	int* rowStart = new int[columns];

	for (int i = 0; i < columns; i++) {
		rowSize[i] = 0;
	}

	for (int i = 0; i < terms; i++) {
		rowSize[this->items[i]->col]++;
	}

	rowStart[0] = 0;
	for (int i = 1; i < columns; i++) {
		rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
	}

	for (int i = 0; i < terms; i++) {
		int j = rowStart[items[i]->col];

		MatrixTerm* newTerm = new MatrixTerm();
		newTerm->row = items[i]->col;
		newTerm->col = items[i]->row;
		newTerm->value = items[i]->value;

		transposeMatrix->items[j] = newTerm;
		transposeMatrix->terms++;

		rowStart[items[i]->col]++;
	}

	delete[] rowSize;
	delete[] rowStart;

	return transposeMatrix;
}


SparseMatrix SparseMatrix::Add(SparseMatrix b)
{
	return b;
}


SparseMatrix* SparseMatrix::Multiply(SparseMatrix b)
{
	if (columns != b.columns) {
		cout << "Incompatible matrices" << endl;
		return new SparseMatrix(0, 0);
	}

	SparseMatrix* matrix = new SparseMatrix(rows, columns);

	SparseMatrix* bXpose = b.FastTranspose();

	for (int row = 0; row < rows; rows++) {
		int value = 0;

		for (int column = 0; column < columns; column++) {
			for (int term = 0; term < b.terms; term++) {

			}
		}
	}

	delete bXpose;

	return matrix;
}

void SparseMatrix::Dump()
{
	cout << "Rows: " << rows << ", Columns: " << columns << ", Terms: " << terms << endl;

	for (int i = 0; i < terms; i++) {
		MatrixTerm* term = items[i];

		cout << "Row:\t" << term->row << ", Column:\t" << term->col << ", Value:\t" << term->value << endl;
	}
}
