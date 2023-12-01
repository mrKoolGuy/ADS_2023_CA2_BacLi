#pragma once
#include "Tree.h"

template<class T>
class TreeIterator
{
	public:
		Tree<T>* node;
		DListIterator<Tree<T>*> childIter;

		TreeIterator(Tree<T>* root);
		void resetIterator();
		void root();
		void up();
		void down();
		void childBack();
		void childForth();
		void childStart();
		void childEnd();
		void appendChild(T item);
		void prependChild(T item);
		void insertChildBefore(T item);
		void insertChildAfter(T item);
		void removeChild();
		bool childValid();
		T childItem();
		T item();
	
};

