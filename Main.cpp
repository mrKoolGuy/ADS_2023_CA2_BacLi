#include <iostream>
#include "DLinkedList.h"
#include "DListIterator.h"
#include "DListNode.h"
#include "Stack.h" //cool for now but find fix for the fact that you cant link the .h
#include "Tree.h"
#include "TreeIterator.h"
#include "XML_Parser.h"
#include <queue>

int CountItems(Tree<string> tree)
{
	//start with one to include root in count
	int count = 1;
	queue<Tree<string>> queue;
	queue.push(tree);
	while (!queue.empty())
	{
		DListIterator<Tree<string>*> iter = queue.front().children->getIterator();
		while (iter.isValid())
		{
			count++;
			queue.push(*iter.item());
			iter.advance();
		}
		queue.pop();
	}
	return count;
}


int CalcMemory(Tree<string> tree, string folderName)
{
	//Calculate File Sizes in a Folder using a Breadth First Search
	int totalSize = 0;

	queue<Tree<string>> queue;
	queue.push(tree);
	while (!queue.empty())
	{
		DListIterator<Tree<string>*> iter = queue.front().children->getIterator();
		while (iter.isValid())
		{
			if (iter.item()->length != 0)
			{
				totalSize += iter.item()->length;
			}
			queue.push(*iter.item());
			iter.advance();
		}
		queue.pop();
	}

	return totalSize;
}

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

int main() 
{
	string testXML = "<root> gucci <dir> <name></name><name> </name>mommy <file>your momi love you </file></dir></root>";
	string x = R"(
<name>test</name>
    </dir>
)";
	string emptyStr = "   ";
	string testXML2 = "<root><dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file></dir><dir><name>gaming</name><file><name>newFIle</name><length>1234</length><type>.exe</type></file></dir></root>";
	XML_Parser xml(testXML2);
	cout << xml.ValidateXML();

	Tree<string>* root = nullptr;
	TreeIterator<string> iter(root);
	xml.CreateTree(root, iter);

	string folderName = "super";

	cout << CountItems(*root) << endl;
	printBFS(*root);
	cout << CalcMemory(*root, folderName) << endl;
}