#pragma once
#include "DList.h"

template<class T>
class Tree
{
	public:
		T data;
		Tree<T>* parent;
		DList<Tree<T>*>* children;
		Tree(T item);
		int count();
		T getData();
};

