#pragma once

#include <iostream>
using namespace std;

template <class T>
class Bag
{
public:
	Bag(int);
	~Bag();
	void Add(const T& item);
	virtual T* Delete(T& item);
	bool IsFull();
	bool IsEmpty();

protected:
	void Full();
	void Empty();
	T* items;
	int top;
	int maxSize;
};

template <class T>
Bag<T>::Bag(int maxSize)
{
	this->maxSize = maxSize;
	this->top = -1;
	this->items = new T[this->maxSize];
}

template <class T>
Bag<T>::~Bag()
{
	delete[] this->items;
}

template <class T>
void Bag<T>::Add(const T& item)
{
	if (IsFull()) {
		Full();
	}
	else {
		items[++top] = item;
	}
}

template <class T>
T* Bag<T>::Delete(T& item)
{
	if (IsEmpty()) {
		Empty();
	}
	else {
		int deleteIndex = top / 2;
		T value = items[deleteIndex];

		for (int index = deleteIndex; index < top; index++) {
			items[index] = items[index + 1];
		}

		top--;

		return &value;
	}
}

template <class T>
bool Bag<T>::IsFull()
{
	return maxSize == top + 1;
}

template <class T>
bool Bag<T>::IsEmpty()
{
	return top == -1;
}

template <class T>
void Bag<T>::Full()
{
	cout << "OnFull" << endl;
}

template <class T>
void Bag<T>::Empty()
{
	cout << "OnEmpty" << endl;
}
