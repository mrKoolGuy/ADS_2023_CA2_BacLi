#pragma once

//template <class T> class DLinkedList;
//template <class T> class DListIterator;

#include "DLinkedList.h"
#include "DListNode.h"

template <class T>
class DListIterator
{
public:
	DListNode<T>* currentNode;
	DLinkedList<T>* list;

	DListIterator(DLinkedList<T>* l = nullptr, DListNode<T>* node = nullptr);
	void start();
	void end();
	void advance();
	void previous();
	T item();
	bool isValid();
	bool isEnd();
	bool isStart();
};
