#pragma once

#include "Bag.h"

#include <iostream>
using namespace std;

template <class T>
class Stack : public Bag <T> {
public:
	Stack(int maxSize) : Bag(maxSize) { }
	T* Delete(T&);
};

template <class T>
T* Stack<T>::Delete(T& item) {
	if (this->IsEmpty()) {
		return NULL;
	}

	item = this->items[top--];

	return &item;
}


//template <class T>
//virtual T* Bag<T>::Delete(T& item)
//{
//	if (IsEmpty()) {
//		Empty();
//	}
//	else {
//		int deleteIndex = top / 2;
//		int value = items[deleteIndex];
//
//		for (int index = deleteIndex; index < top; index++) {
//			items[index] = items[index + 1];
//		}
//
//		top--;
//
//		return &value;
//	}
//}