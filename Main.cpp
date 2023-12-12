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

void RemoveEmptyFolders(TreeIterator<string> iter) //Work in Progress
{
	while (iter.childValid())
	{
		TreeIterator<string> iter2(iter.childIter.currentNode->data);
		RemoveEmptyFolders(iter2);
		iter.childForth();
	}
	if (iter.node->length == 0 && iter.node->children->count == 0)
	{
		iter.up();
		TreeIterator<string> iter2(iter.node);
		while (iter2.childValid())
		{		
			iter2.childForth();
			
			if (iter2.childIter.currentNode->data->length == 0 && iter2.childIter.currentNode->data->children->count == 0)
			{
				iter2.removeChild();
				cout << "Deleted!" << endl;
			}
		}		
	}
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
	string x = R"(
<name>test</name>
    </dir>
)";
	string emptyStr = "   ";
	string testXML2 = "<root><dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file></dir><dir><name>gaming</name><file><name>newFIle</name><length>1234</length><type>.exe</type></file></dir><dir><name>empty</name></dir></root>";
	
	string testFilePath = "./testxml.xml";
	XML_Parser xml(testFilePath);
	cout << xml.ValidateXML();

	Tree<string>* root = nullptr;
	xml.CreateTree(root);
	TreeIterator<string> iter(root);

	string folderName = "super";

	cout << CountItems(*root) << endl;
	displayTree(iter, "   ");
	cout << CalcMemory(*root, folderName) << endl;

	//RemoveEmptyFolders(iter);
	displayTree(iter, "   ");
}