#pragma once
#include "DLinkedList.h"
#include <queue>

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
		string getName();

		//Stage 2 Functions
		void BFS(Tree<string> tree);
		void FindElementbyName();
		void DisplayFolderContent();

};

template <class T>
string Tree<T>::getName()
{
	return name;
}

//for directories
template <class T>
Tree<T>::Tree(string name)
{
	this->name = name;
	this->length = 0;
	this->type = "";
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
	children = new DLinkedList<Tree<T>*>();;
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
void Tree<T>::BFS(Tree<string> tree)
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