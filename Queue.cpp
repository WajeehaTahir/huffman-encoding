#include "Queue.h"
#include <cstddef>
#include "node.h"
#include <iostream>
void Queue::InsertAtStart(node* value)
{
	node* temp = new node;
	temp->data = value->data;
	temp->priority = value->priority;
	temp->left = value->left;
	temp->right = value->right;
	if (head)
	{
		temp->next = head;
	}
	else
	{
		temp->next = NULL;
	}
	head = temp;
}
void Queue::InsertAtEnd(node* value)
{
	node* newNode = new node;
	newNode->data = value->data;
	newNode->priority = value->priority;
	newNode->left = value->left;
	newNode->right = value->right;
	if (!head)
	{
		head = newNode;
		head->next = NULL;
	}
	node* temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->next = NULL;
}
void Queue::InsertAtAnyPosition(node* value, int position)
{
	if (position == 1)
	{
		InsertAtStart(value);
	}
	else if (position == size() + 1)
	{
		InsertAtEnd(value);
	}
	else if (size() >= position)
	{
		int count = 1;
		node* newNode = new node;
		newNode->data = value->data;
		newNode->priority = value->priority;
		newNode->left = value->left;
		newNode->right = value->right;
		node* temp = head;
		node* temp2;
		while (count < position - 1)
		{
			temp = temp->next;
			count++;
		}
		temp2 = temp->next;
		temp->next = newNode;
		newNode->next = temp2;
	}
}
Queue::Queue()
{
	head = NULL;
}
Queue::Queue(Queue& obj)
{
	if (obj.size() > 0)
	{
		head = new node;
		node* temp = head;
		node* temp2 = obj.head;
		while (temp2->next)
		{
			temp->data = temp2->data;
			temp->priority = temp2->priority;
			temp->next = new node;
			temp = temp->next;
			temp2 = temp2->next;
		}
		temp->data = temp2->data;
		temp->priority = temp2->priority;
		temp->next = NULL;
	}
	else
	{
		head = NULL;
	}
}
void Queue::enQueue(node value)
{
	if (head)
	{
		node* temp = head;
		int count = 1;
		while (true)
		{
			if (temp->priority > value.priority)
			{
				InsertAtAnyPosition(&value, count);
				break;
			}
			else
			{
				count++;
				temp = temp->next;
			}
			if (count > size())
			{
				InsertAtEnd(&value);
				break;
			}
		}
	}
	else
	{
		InsertAtStart(&value);
	}
}
void Queue::deQueue()
{
	if (head)
	{
		node* temp = head->next;
		//delete head;
		head = temp;
	}
}
bool Queue::isEmpty()
{
	if (head)
	{
		return false;
	}
	return true;
}
node* Queue::getTop()
{
	return head;
}
void Queue::showQueue()
{
	if (head)
	{
		node* temp = head;
		while (temp)
		{
			std::cout << temp->priority << ":" << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
}
int Queue::size()
{
	node* temp = head;
	int count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return count;
}
Queue::~Queue()	//try adding this
{
	/*if (head)
	{
		node* prev = head;
		node* temp = prev->next;
		while (temp)
		{
			delete prev;
			prev = temp;
			temp = temp->next;
		}
		delete temp;
	}*/
}
