#pragma once
#include <string>
#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#include "Tree.h"
#include "TreeIterator.h"
#include "TreeFile.h"

using namespace std;

class XML_Parser
{
private: 
	string s_xml;
	int validStackCap;

	string GetTag(int& i);
	string GetData(int& i);

public:
	XML_Parser();
	XML_Parser(string s);
	void SetXML(string s_xml);
	string GetXML();

	bool ValidateXML();
	bool XMLtoString();

	void CreateTree(Tree<string>*& root);
};

