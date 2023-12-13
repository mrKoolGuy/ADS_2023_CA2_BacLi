#include <iostream>
#include "DLinkedList.h"
#include "DListIterator.h"
#include "DListNode.h"
#include "Stack.h" //cool for now but find fix for the fact that you cant link the .h
#include "Tree.h"
#include "TreeIterator.h"
#include "XML_Parser.h"
#include <queue>



void printBFS(Tree<string> tree)
{
	queue<Tree<string>> queue;
	queue.push(tree);
	while (!queue.empty())
	{
		DListIterator<Tree<string>*> iter = queue.front().children->getIterator();
		while (iter.isValid())
		{
			queue.push(*iter.item());
			iter.advance();
		}
		cout << queue.front().name << ", ";
		queue.pop();
	}
}

void displayTree(TreeIterator<string> iter, string indent)
{
	cout << indent << iter.node->name;
	if (iter.childValid())
	{
		cout << "(" << endl;

		while (iter.childValid())
		{
			TreeIterator<string> iter2(iter.childIter.currentNode->data);
			displayTree(iter2, "\t" + indent);
			iter.childForth();
		}
		cout << indent << ")";
	}
	cout << endl;
}

int main() 
{
	string testXML = "<root> gucci <dir> <name></name><name> </name>mommy <file>your momi love you </file></dir></root>";
	string emptyStr = "   ";
	string testXML2 = "<root><dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file></dir><dir><name>gaming</name><file><name>newFIle</name><length>1234</length><type>.exe</type></file></dir><dir><name>empty</name></dir></root>";
	
	string testFilePath = "./testxml.xml";
	XML_Parser xml(testFilePath);
	cout << xml.ValidateXML();

	Tree<string>* root = nullptr;
	xml.CreateTree(root);
	TreeIterator<string> iter(root);

	cout << xml.CountItems(*root) << endl;
	displayTree(iter, "   ");
	cout << xml.CalcMemory(*root) << endl;

	xml.RemoveEmptyFolders(iter);
	displayTree(iter, "   ");
	cout << xml.CountItems(*root) << endl;
}