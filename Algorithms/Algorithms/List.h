#pragma once

#include <iostream>
using namespace std;

template <class Type> 
class List;

template <class Type>
class ListNode {
	friend class List < Type > ;

private:
	Type data;
	ListNode* link;
};

template <class Type>
class List {
public:
	List();
	~List();

	void Insert(Type& item);
	void Delete(Type& item);

private:
	ListNode<Type>* first;
};

template <class Type>
List<Type>::List() {
	first = NULL;
};

template <class Type>
List<Type>::~List() {
	ListNode<Type>* item = first;

	while (item != NULL) {
		ListNode<Type>* temp = item->link;

		delete item;

		item = temp;
	}
}

template <class Type>
void List<Type>::Insert(Type& item) {
	if (first == NULL) {
		first = new ListNode<Type>();
		first->data = item;
		first->link = NULL;
	}

	// 마지막 아이템을 구한다.
	ListNode<Type>* last = first;

	while (last->link != NULL) {}

	ListNode<Type>* newNode = new ListNode<Type>();
	newNode->data = item;
	newNode->link = NULL;

	last->link = newNode;
};

template <class Type>
void List<Type>::Delete(Type& item) {
	ListNode<Type>* previousNode = NULL;
	ListNode<Type>* currentNode = first;

	while (currentNode != NULL) {
		if (currentNode->data == item) {
			if (previousNode != NULL) {
				previousNode->link = currentNode->link;
			}

			delete currentNode;

			return;
		}

		previousNode = currentNode;
		currentNode = currentNode->link;
	}
};