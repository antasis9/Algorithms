#include "String.h"
#include <iostream>

#define DEBUG 0

using namespace std;

String::String(char* content) {
	value = content;
}

String::~String() {

}

int String::Search(String* pattern) {
	int contentLength = GetLength();
	int patternLength = pattern->GetLength();

	int* failTable = new int[patternLength];

	for (int i = 0; i < patternLength; i++) {
		failTable[i] = Fail(pattern, i);
	}

#ifdef DEBUG
	cout << "[Fail Table] ==========" << endl;
	for (int i = 0; i < patternLength; i++) {
		cout << "	Index: " << i << ", Value: " << failTable[i] << endl;
	}
	cout << "[Fail Table] ==========" << endl;
#endif

	int indexContent = 0;
	int indexPattern = 0;

	while (indexContent < contentLength && indexPattern < patternLength) {
		if (value[indexContent] == pattern->value[indexPattern]) {
			indexContent++;
			indexPattern++;
		}
		else {
			if (indexPattern == 0) {
				indexContent++;
			}
			else {
				indexPattern = failTable[indexPattern - 1] + 1;
			}
		}
	}

	delete[] failTable;

	if (indexPattern == patternLength) {
		return indexContent - patternLength;
	}
	else {
		return -1;
	}
}

int String::GetLength() {
	int length = 0;

	while (value[length++] != NULL) { }

	return --length;
}

int String::Fail(String* pattern, int index) {
	int result = -1;
	int k = 0;
	int j = index;

	cout << "Index: " << index << endl;
	while (k < j) {
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

		int isSame = strcmp(prefix, postfix);

#ifdef DEBUG
		cout << "K: " << k << " Pre: " << prefix << ", Post: " << postfix << ", " << isSame << endl;
#endif

		if (isSame == 0) {
			result = k;
		}

		k++;

		delete[] prefix;
		delete[] postfix;
	}

	cout << endl;

	return result;
}