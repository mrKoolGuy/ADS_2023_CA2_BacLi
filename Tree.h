#pragma once
#include "DLinkedList.h"

template<class T>
class Tree
{
	public:
		//Standard Tree Functions
		string name;
		int length; //size in bytes
		string type;
		Tree<T>* parent;
		DLinkedList<Tree<T>*>* children;
		Tree(string item, int length, string type);
		Tree(string item);
		int count();
		string getData();

		//Stage 2 Functions
		float CalcMemory();
		void BFS();
		void RemoveEmptyFolders();
		void FindElementbyName();
		void DisplayFolderContent();

};

template <class T>
string Tree<T>::getData()
{
	return name;
}

//for directories
template <class T>
Tree<T>::Tree(string name)
{
	this->name = name;
	children = new DLinkedList<Tree<T>*>();
	parent = nullptr;
}

//for leaf nodes
template <class T>
Tree<T>::Tree(string name, int length, string type)
{
	this->name = name;
	this->length = length;
	this->type = type;
	children = new DLinkedList<Tree<T>*>();
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