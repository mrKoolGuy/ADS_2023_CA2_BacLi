#pragma once
#include <iostream>

using namespace std;

template <class T>
class MyStack
{
		T* data;
		int capacity;
		int topNum;
	public:
		MyStack(T s, int i);
		bool push(T item);
		T top();
		void pop();
		int size();
		bool isEmpty();
		void clear();
		void print();
		~MyStack();	
};

