#pragma once
#include "DListNode.h"
#include "DListIterator.h"

template <class T> 
class DLinkedList
{
	public:
		DListNode<T>* head, * tail;
		int count;

		DLinkedList();
		DLinkedList(DLinkedList<T>& list);
		void append(T item);
		void prepend(T item);
		void removeHead();
		void removeTail();
		DListIterator<T> getIterator();
		void insert(DListIterator<T>& iter, T item);
		DListIterator<T> remove(DListIterator<T>& iter);
		int size();
		~DLinkedList();
};

