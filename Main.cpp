#include <iostream>
#include "DLinkedList.h"
#include "DListIterator.h"
#include "DListNode.h"
#include "Stack.h" //cool for now but find fix for the fact that you cant link the .h
#include "Tree.h"
#include "TreeIterator.h"
#include "XML_Parser.h"


int main() 
{
	string testXML = "<root> gucci <folder> mommy <file>your momi love you </file></folder>";
	XML_Parser xml(testXML);
	cout << xml.ValidateXML();
}