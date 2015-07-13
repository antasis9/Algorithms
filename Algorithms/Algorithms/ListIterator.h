#pragma once

#include <iostream>
#include "List.h"

using namespace std;

template <class Type>
class ListIterator
{
public:
	ListIterator(List<Type>* l);

	bool NotNull();
	bool NextNotNull();
	Type* First();
	Type* Next();

private:
	List<Type>* list;
	ListNode<Type>* current;
};

template <class Type>
ListIterator<Type>::ListIterator(List<Type>* l) {
	list = l;
	current = l->first;
}

template <class Type>
bool ListIterator<Type>::NotNull() {
	if (current != NULL) {
		return true;
	}
	else {
		return false;
	}
}

template <class Type>
bool ListIterator<Type>::NextNotNull() {
	if (current != NULL && current->link != NULL) {
		return true;
	}
	else {
		return false;
	}
}

template <class Type>
Type* ListIterator<Type>::First() {
	if (list->first != NULL) {
		return &list->first->data;
	}
	else {
		return 0;
	}
}

template <class Type>
Type* ListIterator<Type>::Next() {
	if (current != NULL) {
		current = current->link;

		if (current != NULL) {
			return &current->data;
		}
	}
	else {
		return 0;
	}
}