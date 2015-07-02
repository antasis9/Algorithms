#include "String.h"
#include <iostream>

using namespace std;

String::String(char* content) {
	value = content;
}

String::~String() {

}

int String::Search(String* pattern) {
	Fail(pattern, 4);

	return 0;
}

int String::GetLength() {
	int length = 0;

	while (value[length++] != NULL) { }

	return --length;
}

int String::Fail(String* pattern, int index) {
	int k = 0;
	int j = index;

	while (true) {
		if (k == j) {
			break;
		}

		int length = k + 1;

		char* prefix = new char[length + 1];
		char* postfix = new char[length + 1];

		for (int i = 0; i < length + 1; i++) {
			prefix[i] = '\0';
			postfix[i] = '\0';
		}

		for (int i = 0; i < length; i++) {
			prefix[i] = pattern->value[i];
			postfix[i] = pattern->value[j - k + i];
		}

		cout << "K: " << k << " Pre: " << prefix << ", Post: " << postfix << endl;

		k++;

		delete[] prefix;
		delete[] postfix;
	}

	return 0;
}