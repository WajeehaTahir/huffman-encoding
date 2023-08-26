#pragma once
#include "node.h"
class Queue
{
private:
	node* head;
	void InsertAtStart(node* value);
	void InsertAtEnd(node* value);
	void InsertAtAnyPosition(node* value, int position);
public:
	Queue();
	Queue(Queue& obj);
	void enQueue(node value);
	void deQueue();
	bool isEmpty();
	node* getTop();
	void showQueue();
	int size();
	~Queue();
};
