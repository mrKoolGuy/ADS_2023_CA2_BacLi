#pragma once
#include <string>
#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

class XML_Parser
{
private: 
	string s_xml;
	int validStackCap;

public:
	XML_Parser();
	XML_Parser(string s);
	void SetXML(string s_xml);
	string GetXML();

	bool ValidateXML();
	bool XMLtoString();
};

