#pragma once

template <class T>
class DListNode
{
public:
	T data;
	DListNode<T>* next;
	DListNode<T>* previous;

	DListNode(T item);
	DListNode(DListNode<T>& item);
	void insertBefore(T item);
	void insertAfter(T item);

	~DListNode()
	{
		//next = nullptr;
		//previous = nullptr;
	}
};

