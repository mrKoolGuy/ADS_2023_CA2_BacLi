#include "Tree.h"

template <class T>
T Tree<T>::getData()
{
	return data;
}
template <class T>
Tree<T>::Tree(T item)
{

	data = item;
	children = new DList<Tree<T>*>();
	parent = nullptr;
}

template <class T>
int Tree<T>::count()
{
	int c = 1;
	DListIterator<Tree<T>*> iter = children->getIterator();
	while (iter.isValid())
	{
		c += iter.item()->count();
		iter.advance();
	}
	return c;
}