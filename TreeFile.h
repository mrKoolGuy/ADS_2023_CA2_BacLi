#pragma once
#include "Tree.h"

template<class T>
class TreeFile : public Tree<T>
{
private: 
	int length; //size in b
	string type;

public:
	TreeFile();
	TreeFile(string name, int length, string type);
};

template<class T>
TreeFile<T>::TreeFile(string name, int length, string type)
{
	this->name = name;
	this->length = length;
	this->type = type;
}

template<class T>
TreeFile<T>::TreeFile()
{
	this->name = "Unidentified";
	this->length = 1;
	this->type = "txt";
}


