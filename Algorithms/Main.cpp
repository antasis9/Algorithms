#include <iostream>
#include "time.h"
#include "SparseMatrix.h"
#include "Algorithms\String.h"

using namespace std;

#define	ROWS	160
#define	COLUMNS	38

int main() {
	String content("afdsafsdfsdvxzaabcabcacadabcabcacabaaaa");
	String pattern("abcabcacab");

	int index = content.Search(&pattern);

	cout << "Index: " << index << endl;

	return 0;
}