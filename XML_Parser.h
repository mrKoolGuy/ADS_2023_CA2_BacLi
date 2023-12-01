#pragma once
#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;

class XML_Parser
{
private: 
	string s_xml;

public:
	XML_Parser();
	XML_Parser(string s);
	void SetXML(string s_xml);
	string GetXML();

	bool validateXML();
};

