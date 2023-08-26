#include "Tree.h"
#include <map>
#include <string>
#include "node.h"
#include <bitset>
#define sentinel '*'
std::string toBinary(std::string const& str) {
	std::string binary = "";
	for (char const& c : str) {
		binary += std::bitset<8>(c).to_string();
	}
	return binary;
}
node* Tree::constructTree(Queue& q)
{
	while (q.size() != 1)
	{
		node* curr = new node;
		curr->left = q.getTop();
		curr->priority = q.getTop()->priority;
		q.deQueue();
		curr->right = q.getTop();
		curr->priority += q.getTop()->priority;
		q.deQueue();
		q.enQueue(*curr);
	}
	return q.getTop();
}
void Tree::encode(node* temp, std::string s)
{
	if (temp)
	{
		encode(temp->left, s + "0");
		encode(temp->right, s + "1");
		if (temp->data != sentinel)
		{
			m.insert(std::pair<char, std::string>(temp->data, s));
		}
	}
}
std::string Tree::createBinaryString(std::string text)
{
	std::string binary = "", newString = "";
	for (int i = 0; i < text.size(); i++)
	{
		binary += m.find(text[i])->second;
	}
	while (binary.size() % 8)
	{
		binary = binary + "0";
	}
	for (int i = 0; i < binary.size(); i += 8)
	{
		newString += std::stoi(binary.substr(i, 8), nullptr, 2);
	}
	return newString;
}
std::string Tree::decode(std::string text, node* head)
{
	std::string binary = toBinary(text);
	node* temp = head;
	std::string decoded = "";
	while (binary.size())
	{
		if (temp)
		{
			if (!(temp->left && temp->right))
			{
				decoded = decoded + temp->data;
				temp = head;
			}
			else
			{
				if (binary[0] == '0')
				{
					temp = temp->left;
				}
				if (binary[0] == '1')
				{
					temp = temp->right;
				}
				binary.erase(0, 1);
			}
		}

	}
	return decoded;
}
