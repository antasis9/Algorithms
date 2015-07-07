#include <iostream>
#include "time.h"
#include "SparseMatrix.h"
#include "Algorithms\String.h"
#include "Algorithms\Bag.h"

using namespace std;

#define	ROWS	160
#define	COLUMNS	38

int main() {
	/*String content("afdsafsdfsdvxzaabcabcacadabcabcacabaaaa");
	String pattern("abcabcacab");

	int index = content.Search(&pattern);

	cout << "Index: " << index << endl;*/

	Bag<int> bag(5);
	bag.Add(10);
	bag.Add(11);
	//bag.Add(12);
	//bag.Add(13);
	//bag.Add(14);
	//bag.Add(15);

	return 0;
}