#pragma once
#include "DLinkedList.h"

template<class T>
class Tree
{
	public:
		//Standard Tree Functions
		T data;
		Tree<T>* parent;
		DLinkedList<Tree<T>*>* children;
		Tree(T item);
		int count();
		T getData();

		//Stage 2 Functions
		float CalcMemory();
		void BFS();
		void RemoveEmptyFolders();
		void FindElementbyName();
		void DisplayFolderContent();

};

