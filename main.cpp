#include <iostream>
#include <string>
#include "fileIO.h"
#include "Queue.h"
#include "Tree.h"
using namespace std;
#define sentinel '*'
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}
void main()
{
	string filename = "Text";
	fileIO f;
	string text = f.readFromFile(filename);
	string str = text;
	Queue* q = new Queue;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != sentinel)
		{
			node* temp = new node;
			temp->data = str[i];
			temp->priority = count(str.begin(), str.end(), str[i]);
			q->enQueue(*temp);
			str = ReplaceAll(str, string(1, str[i]), string(1, sentinel));
		}
	}
	Tree t;
	node* head = t.constructTree(*q);
	t.encode(head);
	f.writeToFile(head, t.createBinaryString(text), filename);
	head = f.readBinaryTree(filename);
	cout << t.decode(f.readFromFile(filename + "_compressed"), head);
}