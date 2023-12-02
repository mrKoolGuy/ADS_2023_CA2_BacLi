#include "DListIterator.h"

template <class T>
DListIterator<T>::DListIterator(DLinkedList<T>* l, DListNode<T>* n)
{
	list = l;
	currentNode = n;
}

template <class T>
void DListIterator<T>::start()
{
	currentNode = list->head;
}

template <class T>
void DListIterator<T>::end()
{
	currentNode = list->tail;
}
template <class T>
void DListIterator<T>::advance()
{
	if (currentNode == nullptr)
		return;
	currentNode = currentNode->next;
}

template <class T>
void DListIterator<T>::previous()
{
	if (currentNode == nullptr)
		return;
	currentNode = currentNode->previous;
}
template <class T>
T DListIterator<T>::item()
{
	return currentNode->data;
}

template <class T>
bool DListIterator<T>::isValid()
{
	return currentNode != nullptr;
}

template <class T>
bool DListIterator<T>::isEnd()
{
	return currentNode == list->tail;
}

template <class T>
bool DListIterator<T>::isStart()
{
	return currentNode == list->head;
}