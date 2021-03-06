#pragma once
#include "MatrixTerm.h"

#define	MAX_ITEM_COUNTS	10000

class SparseMatrix
{
public:
	SparseMatrix(int rows, int columns);
	SparseMatrix(int rows, int columns, int** items);
	~SparseMatrix();
	SparseMatrix* Transpose();
	SparseMatrix* FastTranspose();
	SparseMatrix Add(SparseMatrix b);
	SparseMatrix* Multiply(SparseMatrix b);
	void Dump();

private:
	int rows = 0;
	int columns = 0;
	int terms = 0;
	MatrixTerm* items[MAX_ITEM_COUNTS];
};

