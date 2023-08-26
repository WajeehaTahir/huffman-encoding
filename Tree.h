#pragma once
#include <string>
#include <map>
#include "Queue.h"
#include "node.h"
class Tree
{
public:
	std::map<char, std::string> m;
	node* constructTree(Queue& q);
	void encode(node* temp, std::string s = "");
	std::string createBinaryString(std::string text);
	std::string decode(std::string text, node* head);
};