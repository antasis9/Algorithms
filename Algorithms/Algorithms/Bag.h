#pragma once

template <class T>
class Bag
{
public:
	Bag();
	~Bag();
	void Add(const T& item);
	T* Delete(T& item);
	Boolean IsFull();
	Boolean IsEmpty();
private:
	void Full();
	void Empty();
	T* items;
	int top;
};
