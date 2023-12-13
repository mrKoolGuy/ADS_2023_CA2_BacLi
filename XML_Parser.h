#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Stack.h"
#include "Tree.h"
#include "TreeIterator.h"

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
	XML_Parser(string filePath);
	void SetXML(string s_xml);
	string GetXML();

	bool ValidateXML();
	string XMLtoString(string filePath);

	void CreateTree(Tree<string>*& root);

	void RemoveEmptyFolders(TreeIterator<string> iter);
	int CalcMemory(Tree<string> tree);
	int CountItems(Tree<string> tree);


};

