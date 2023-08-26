#include "fileIO.h"
#include <string>
#include <fstream>
#define sentinel '*'
std::string fileIO::readFromFile(std::string filename)
{
	std::ifstream in;
	in.open(filename + ".txt");
	std::string text;
	getline(in, text);
	in.close();
	return text;
}
void fileIO::writeToFile(node* temp, std::string text, std::string filename)
{
	std::ofstream out;
	out.open(filename + "_compressed.txt");
	out << text;
	out.close();
	out.open(filename + "_key.txt");
	inorder(temp, out);
	out << std::endl;
	preorder(temp, out);
	out.close();
}
node* fileIO::readBinaryTree(std::string filename)
{
	std::ifstream in;
	in.open(filename + "_key.txt");
	std::string i, pre;
	getline(in, i);
	getline(in, pre);
	node* head = buildTree(i, pre, 0, i.length() - 1);
	in.close();
	return head;
}
node* fileIO::buildTree(std::string in, std::string pre, int inStrt, int inEnd)
{
	static int preIndex = 0;
	if (inStrt > inEnd)
	{
		return NULL;
	}
	node* tNode = new node;
	tNode->data = pre[preIndex++];
	if (inStrt == inEnd)
	{
		return tNode;
	}
	int inIndex = search(in, inStrt, inEnd, tNode->data);
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
	return tNode;
}
int fileIO::search(std::string arr, int strt, int end, char value)
{
	for (int i = strt; i <= end; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
}
void fileIO::inorder(node* temp, std::ofstream& out)
{
	if (temp)
	{
		inorder(temp->left, out);
		if (temp->data == sentinel)
		{
			out << char((int(temp->left->data) + int(temp->right->data) + temp->right->priority) % 256);
		}
		else
		{
			out << temp->data;
		}
		inorder(temp->right, out);
	}
}
void fileIO::preorder(node* temp, std::ofstream& out)
{
	if (temp)
	{
		if (temp->data == sentinel)
		{
			out << char(int(temp->left->data) + int(temp->right->data) + temp->right->priority);
		}
		else
		{
			out << temp->data;
		}
		preorder(temp->left, out);
		preorder(temp->right, out);
	}
}