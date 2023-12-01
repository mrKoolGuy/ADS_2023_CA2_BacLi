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

template <class T>
float Tree<T>::CalcMemory() 
{
	//Calculate File Sizes in a Folder using a Breadth First Search
}

template <class T>
void Tree<T>::BFS() 
{

}

template <class T>
void Tree<T>::RemoveEmptyFolders()
{

}

template <class T>
void Tree<T>::FindElementbyName()
{
	//Use Depth First Search
}

template <class T>
void Tree<T>::DisplayFolderContent()
{
	//Display Folder Content & File Sizes
}