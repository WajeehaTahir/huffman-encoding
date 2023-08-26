#pragma once
#include <string>
#include <fstream>
#include "node.h"
class fileIO
{
public:
	std::string readFromFile(std::string filename);
	void writeToFile(node* temp, std::string text, std::string filename);
	node* readBinaryTree(std::string filename);
	node* buildTree(std::string in, std::string pre, int inStrt, int inEnd);
	int search(std::string arr, int strt, int end, char value);
	void inorder(node* temp, std::ofstream& out);
	void preorder(node* temp, std::ofstream& out);
};