#include "DLinkedList.h"

template <class T>
DLinkedList<T>::DLinkedList(DLinkedList<T>& list)
{
	head = nullptr;
	tail = nullptr;
	DListNode<T>* current;
	current = list.head;
	while (current != nullptr)
	{
		this->append(current->data);
		current = current->next;
	}
}
template <class T>
int DLinkedList<T>::size()
{
	return count;
}
template <class T>
DLinkedList<T>::DLinkedList()
{
	count = 0;
	head = tail = nullptr;
}
template <class T>
void DLinkedList<T>::append(T item)
{
	if (head == nullptr)
	{
		head = tail = new DListNode<T>(item);
	}
	else
	{
		tail->insertAfter(item);
		tail = tail->next;

	}
	count++;
}

template <class T>
void DLinkedList<T>::prepend(T item)
{
	if (head == nullptr)
	{
		head = tail = new DListNode<T>(item);


	}
	else
	{
		head->insertBefore(item);
		head = head->previous;

	}
	count++;
}

template <class T>
void DLinkedList<T>::removeHead()
{
	if (head == nullptr)
	{
		return;
	}
	else if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		count--;
	}
	else
	{
		DListNode<T>* temp = head;
		head = head->next;
		head->previous = nullptr;
		delete temp;
		temp = nullptr;

		count--;
	}
}

template <class T>
void DLinkedList<T>::removeTail()
{
	if (head == nullptr)
	{
		return;
	}
	else if (head == tail)
	{
		delete tail;
		head = tail = nullptr;
		count--;
	}
	else
	{
		DListNode<T>* temp = tail;
		tail = tail->previous;
		tail->next = nullptr;
		delete temp;
		temp = nullptr;

		count--;
	}
}
template <class T>
DListIterator<T> DLinkedList<T>::getIterator()
{
	return DListIterator<T>(this, head);
}
template <class T>
void DLinkedList<T>::insert(DListIterator<T>& iter, T item)
{
	if (iter.list != this || !iter.isValid())
	{
		return;
	}
	if (iter.currentNode == head)
	{
		prepend(item);
	}
	else
	{
		iter.currentNode->insertBefore(item);
		count++;
	}
}

template <class T>
DListIterator<T> DLinkedList<T>::remove(DListIterator<T>& iter)
{
	if (iter.list != this || !iter.isValid())
	{
		return iter;
	}
	if (iter.currentNode == head)
	{
		iter.advance();
		removeHead();
		return iter;
	}
	else
	{
		DListNode<T>* prev = iter.currentNode->previous;
		if (iter.currentNode == tail)
		{
			tail = prev;
		}
		prev->next = iter.currentNode->next;
		if (iter.currentNode->next != nullptr)
		{
			iter.currentNode->next->previous = prev;
		}
		delete iter.currentNode;
		count--;
		return DListIterator<T>(this, prev->next);
	}

}

template <class T>
DLinkedList<T>::~DLinkedList()
{
	DListNode<T>* iter, *next = nullptr;
	iter = head;
	while (iter != nullptr)
	{
		next = iter->next;
		delete iter;
		iter = next;

	}
	head = nullptr;
	tail = nullptr;
}