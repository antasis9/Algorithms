#include <iostream>
#include "time.h"
#include "SparseMatrix.h"
#include "Algorithms\String.h"
#include "Algorithms\Bag.h"
#include "Algorithms\Stack.h"
#include "Algorithms\Maze.h"

using namespace std;

#define	ROWS	160
#define	COLUMNS	38

int main() {
	/*String content("afdsafsdfsdvxzaabcabcacadabcabcacabaaaa");
	String pattern("abcabcacab");

	int index = content.Search(&pattern);

	cout << "Index: " << index << endl;*/

	//Bag<int> bag(5);
	//bag.Add(10);
	//bag.Add(11);
	////bag.Add(12);
	////bag.Add(13);
	////bag.Add(14);
	////bag.Add(15);

	//Stack<int> stack(5);

	//stack.Add(1);
	//stack.Add(2);
	//stack.Add(3);
	//stack.Add(4);
	//stack.Add(5);

	char array[4][5] = {
		{ '1', '0', '1', '1', '1' },
		{ '0', '1', '1', '0', '1' },
		{ '0', '0', '1', '0', '1' },
		{ '0', '1', '1', '0', '1' }
	};

	Maze maze;
	maze.Search(array, 5);

	/*for (int i = 0; i < 5; i++) {
		int value = 0;

		cout << "Value: " << *stack.Delete(value) << endl;
	}*/

	return 0;
}