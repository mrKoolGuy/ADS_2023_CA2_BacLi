#pragma once
#include <string>

using namespace std;

template <class T>
class Stack
{
		T* data;
		int capacity;
		int topNum;
	public:
		Stack(string s);
		bool push(T item);
		T top();
		void pop();
		int size();
		bool isEmpty();
		void clear();
		void print();
		~Stack();	
};

