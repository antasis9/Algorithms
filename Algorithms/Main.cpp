#include <iostream>
#include "time.h"
#include "SparseMatrix.h"
#include "Algorithms\String.h"

using namespace std;

#define	ROWS	160
#define	COLUMNS	38

int main() {
	String content("ababdababc");
	String pattern("abcabcacab");

	content.Search(&pattern);

	return 0;
}