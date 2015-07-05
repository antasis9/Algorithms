#include "Bag.h"

template <class T>
Bag::Bag(int maxSize)
{
	this->maxSize = maxSize;
	this->top = -1;
	this->items = new T[this->maxSize];
}

template <class T>
Bag::~Bag()
{
	delete[] items;
}

template <class T>
void Bag::Add(Type& item)
{
	if (IsFull()) {
		Full();
	}
	else {
		items[--top] = item;
	}
}

<T>
T* Bag<T>::Delete(T& item)
{
	if (IsEmpty()) {
		Empty();
	}
	else {
		int deleteIndex = top / 2;
		int value = items[deleteIndex];

		for (int index = deleteIndex; i < top; i++) {
			items[index] = items[index + 1];
		}

		top--;

		return &value;
	}
}

<T>
Boolean Bag<T>::IsFull()
{
	return maxSize == top + 1;
}

<T>
Boolean Bag<T>::IsEmpty()
{
	return top == -1;
}

<T>
void Bag<T>::Full()
{
	cout << "OnFull" << endl;
}

<T>
void Bag<T>::Empty()
{
	cout << "OnEmpty" << endl;
}
