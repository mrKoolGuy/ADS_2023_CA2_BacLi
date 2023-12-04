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
	string testXML = "<root> gucci <dir> <name></name><name> </name>mommy <file>your momi love you </file></dir></root>";
	string x = R"(
<name>test</name>
    </dir>
)";
	string testXML2 = "<root><dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file></dir></root>";
	XML_Parser xml(testXML2);
	cout << xml.ValidateXML();

	/*Tree<string>* root = nullptr;
	TreeIterator<string> iter(root);
	xml.CreateTree(root);*/
}